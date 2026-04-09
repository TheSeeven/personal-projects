#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
MANIFEST_FILE="${ROOT_DIR}/project-repos.manifest"
OWNER="${GITHUB_OWNER:-}"
VISIBILITY="${VISIBILITY:-private}" # private|public
APPLY="false"
SKIP_CREATE="false"

usage() {
  cat <<EOF
Usage: ./publish-project-repos.sh [--owner <github_username_or_org>] [--public|--private] [--skip-create] [--apply]

Default mode is dry-run (no GitHub changes).
Examples:
  ./publish-project-repos.sh --owner TheSeeven --private
  ./publish-project-repos.sh --owner TheSeeven --private --apply
  ./publish-project-repos.sh --owner TheSeeven --skip-create --apply
  GITHUB_OWNER=TheSeeven VISIBILITY=public ./publish-project-repos.sh --apply
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --owner)
      OWNER="$2"; shift 2 ;;
    --public)
      VISIBILITY="public"; shift ;;
    --private)
      VISIBILITY="private"; shift ;;
    --skip-create)
      SKIP_CREATE="true"; shift ;;
    --apply)
      APPLY="true"; shift ;;
    -h|--help)
      usage; exit 0 ;;
    *)
      echo "Unknown arg: $1" >&2
      usage
      exit 1 ;;
  esac
done

if [[ ! -f "$MANIFEST_FILE" ]]; then
  echo "Manifest not found: $MANIFEST_FILE" >&2
  exit 1
fi

if ! command -v gh >/dev/null 2>&1; then
  echo "GitHub CLI (gh) is required." >&2
  exit 1
fi

if [[ -z "$OWNER" ]]; then
  OWNER="$(gh api user -q .login 2>/dev/null || true)"
fi

if [[ -z "$OWNER" || "$OWNER" =~ [<>] ]]; then
  echo "Could not determine a valid GitHub owner. Use --owner <username>." >&2
  exit 1
fi

echo "Owner: $OWNER"
echo "Visibility: $VISIBILITY"
echo "Mode: $([[ "$APPLY" == "true" ]] && echo APPLY || echo DRY-RUN)"
echo "Skip create: $SKIP_CREATE"
echo

created=0
exists=0
pushed=0
missing=0
create_failed=0
push_skipped=0

while IFS= read -r p || [[ -n "$p" ]]; do
  [[ -z "$p" || "$p" =~ ^# ]] && continue
  path="$ROOT_DIR/$p"

  if [[ ! -d "$path" ]]; then
    echo "[MISSING] $p"
    ((missing+=1))
    continue
  fi

  repo="$(echo "$p" | tr '[:upper:]' '[:lower:]' | sed 's#[ /]#-#g')"
  full="$OWNER/$repo"
  remote_url="https://github.com/$full.git"

  exists_now="false"
  if gh repo view "$full" >/dev/null 2>&1; then
    echo "[EXISTS] $full"
    ((exists+=1))
    exists_now="true"
  elif [[ "$SKIP_CREATE" == "true" ]]; then
    echo "[SKIP CREATE] $full"
  else
    echo "[CREATE] $full"
    if [[ "$APPLY" == "true" ]]; then
      if gh repo create "$full" "--$VISIBILITY" --disable-issues --disable-wiki >/dev/null 2>&1; then
        exists_now="true"
        ((created+=1))
      else
        echo "[CREATE FAILED] $full (check gh auth scopes: repo, read:org; or org permissions)"
        ((create_failed+=1))
      fi
    else
      ((created+=1))
      exists_now="true"
    fi
  fi

  if [[ "$APPLY" == "true" ]]; then
    if [[ "$exists_now" != "true" ]] && ! gh repo view "$full" >/dev/null 2>&1; then
      echo "[SKIP PUSH] $p -> $full (remote repo does not exist)"
      ((push_skipped+=1))
      continue
    fi

    if git -C "$path" remote get-url origin >/dev/null 2>&1; then
      git -C "$path" remote set-url origin "$remote_url"
    else
      git -C "$path" remote add origin "$remote_url"
    fi

    if git -C "$path" push -u origin HEAD:main >/dev/null 2>&1; then
      echo "[PUSH] $p -> $full"
      ((pushed+=1))
    else
      echo "[PUSH FAILED] $p -> $full"
      ((push_skipped+=1))
    fi
  else
    echo "[WOULD PUSH] $p -> $full"
  fi
done < "$MANIFEST_FILE"

echo
echo "Summary: created=$created exists=$exists pushed=$pushed missing=$missing create_failed=$create_failed push_skipped=$push_skipped"
