#!/usr/bin/env bash
set -euo pipefail

OWNER="${GITHUB_OWNER:-}"
APPLY="false"
ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
MANIFEST_FILE="${ROOT_DIR}/project-repos.manifest"
FROM_MANIFEST="false"

usage() {
  cat <<EOUSAGE
Usage: ./delete-project-repos.sh --owner <github_username_or_org> [--from-manifest] [--manifest-file <path>] [--apply] <glob1> [glob2 ...]

Default mode is dry-run (lists what would be deleted).
Examples:
  ./delete-project-repos.sh --owner TheSeeven 'security-and-criptography*' 'gui-*'
  ./delete-project-repos.sh --owner TheSeeven --from-manifest 'Security and criptography/*' 'GUI/*'
  ./delete-project-repos.sh --owner TheSeeven --apply 'cloud-computing-si-iot*'
EOUSAGE
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --owner)
      OWNER="$2"; shift 2 ;;
    --apply)
      APPLY="true"; shift ;;
    --from-manifest)
      FROM_MANIFEST="true"; shift ;;
    --manifest-file)
      MANIFEST_FILE="$2"; shift 2 ;;
    -h|--help)
      usage; exit 0 ;;
    --)
      shift; break ;;
    -*)
      echo "Unknown option: $1" >&2
      usage
      exit 1 ;;
    *)
      break ;;
  esac
done

if ! command -v gh >/dev/null 2>&1; then
  echo "GitHub CLI (gh) is required." >&2
  exit 1
fi

if [[ -z "$OWNER" ]]; then
  OWNER="$(gh api user -q .login 2>/dev/null || true)"
fi

if [[ -z "$OWNER" ]]; then
  echo "Owner is required (use --owner or set GITHUB_OWNER)." >&2
  exit 1
fi

if [[ $# -lt 1 ]]; then
  echo "Provide at least one glob pattern." >&2
  usage
  exit 1
fi

mapfile -t repos < <(gh repo list "$OWNER" --limit 500 --json name -q '.[].name')

if [[ ${#repos[@]} -eq 0 ]]; then
  echo "No repos found for owner: $OWNER"
  exit 0
fi

echo "Owner: $OWNER"
echo "Mode: $([[ "$APPLY" == "true" ]] && echo APPLY || echo DRY-RUN)"
echo "Match source: $([[ "$FROM_MANIFEST" == "true" ]] && echo manifest || echo repository-names)"
echo "Patterns: $*"
echo

slugify_repo_name() {
  local src="$1"
  src="$(printf '%s' "$src" | sed -E 's#^(\./)+##; s#^(\.\./)+##')"
  printf '%s\n' "$(echo "$src" | tr '[:upper:]' '[:lower:]' | sed 's#[ /]#-#g')"
}

matches=()
source_names=("${repos[@]}")
if [[ "$FROM_MANIFEST" == "true" ]]; then
  if [[ ! -f "$MANIFEST_FILE" ]]; then
    echo "Manifest file not found: $MANIFEST_FILE" >&2
    exit 1
  fi
  mapfile -t source_names < <(awk 'NF && $0 !~ /^#/ {print}' "$MANIFEST_FILE")
fi

for source_name in "${source_names[@]}"; do
  repo="$source_name"
  if [[ "$FROM_MANIFEST" == "true" ]]; then
    repo="$(slugify_repo_name "$source_name")"
  fi
  for pattern in "$@"; do
    if [[ "$repo" == $pattern ]]; then
      matches+=("$repo")
      break
    fi
  done
done

if [[ ${#matches[@]} -eq 0 && "$FROM_MANIFEST" != "true" && -f "$MANIFEST_FILE" ]]; then
  mapfile -t manifest_names < <(awk 'NF && $0 !~ /^#/ {print}' "$MANIFEST_FILE")
  for source_name in "${manifest_names[@]}"; do
    repo="$(slugify_repo_name "$source_name")"
    for pattern in "$@"; do
      if [[ "$repo" == $pattern ]]; then
        matches+=("$repo")
        break
      fi
    done
  done
fi

if [[ ${#matches[@]} -eq 0 ]]; then
  echo "No repositories matched the provided patterns."
  echo "Total repos visible to gh for $OWNER: ${#repos[@]}"
  echo
  if [[ "$FROM_MANIFEST" != "true" && -f "$MANIFEST_FILE" ]]; then
    echo "Tip: if your patterns are based on manifest paths, use --from-manifest."
    echo "Example: ./delete-project-repos.sh --owner $OWNER --from-manifest 'GUI/*'"
    echo
  fi
  echo "Tip: check exact names with: gh repo list $OWNER --limit 500 --json name -q '.[].name'"
  echo "First 30 visible repo names:"
  printf ' - %s\n' "${repos[@]:0:30}"
  exit 0
fi

mapfile -t matches < <(printf '%s\n' "${matches[@]}" | awk '!seen[$0]++')

filtered_matches=()
for repo in "${matches[@]}"; do
  if printf '%s\n' "${repos[@]}" | rg -x --fixed-strings "$repo" >/dev/null; then
    filtered_matches+=("$repo")
  fi
done
matches=("${filtered_matches[@]}")

if [[ ${#matches[@]} -eq 0 ]]; then
  echo "Patterns matched manifest-derived repo names, but none currently exist on GitHub for $OWNER."
  echo "They may already be deleted."
  exit 0
fi

printf 'Matched repos (%d):\n' "${#matches[@]}"
printf ' - %s\n' "${matches[@]}"
echo

if [[ "$APPLY" != "true" ]]; then
  echo "Dry-run only. Re-run with --apply to delete these repositories."
  exit 0
fi

for repo in "${matches[@]}"; do
  echo "[DELETE] $OWNER/$repo"
  gh repo delete "$OWNER/$repo" --yes >/dev/null
done

echo
echo "Deleted ${#matches[@]} repositories."
