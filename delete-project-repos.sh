#!/usr/bin/env bash
set -euo pipefail

OWNER="${GITHUB_OWNER:-}"
APPLY="false"

usage() {
  cat <<EOF
Usage: ./delete-project-repos.sh --owner <github_username_or_org> [--apply] <glob1> [glob2 ...]

Default mode is dry-run (lists what would be deleted).
Examples:
  ./delete-project-repos.sh --owner TheSeeven 'security-and-criptography*' 'gui-*'
  ./delete-project-repos.sh --owner TheSeeven --apply 'cloud-computing-si-iot*'
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --owner)
      OWNER="$2"; shift 2 ;;
    --apply)
      APPLY="true"; shift ;;
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
echo "Patterns: $*"
echo

matches=()
for repo in "${repos[@]}"; do
  for pattern in "$@"; do
    if [[ "$repo" == $pattern ]]; then
      matches+=("$repo")
      break
    fi
  done
done

if [[ ${#matches[@]} -eq 0 ]]; then
  echo "No repositories matched the provided patterns."
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
