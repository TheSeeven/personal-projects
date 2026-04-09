#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
MANIFEST_FILE="${ROOT_DIR}/project-repos.manifest"
DEFAULT_BRANCH="${DEFAULT_BRANCH:-main}"
INIT_MESSAGE="${INIT_MESSAGE:-Initial commit}"

if [[ ! -f "$MANIFEST_FILE" ]]; then
  echo "Manifest not found: $MANIFEST_FILE" >&2
  exit 1
fi

created_commits=0
already_committed=0
empty_repos=0
missing=0

while IFS= read -r project || [[ -n "$project" ]]; do
  [[ -z "$project" || "$project" =~ ^# ]] && continue

  project_path="${ROOT_DIR}/${project}"

  if [[ ! -d "$project_path" ]]; then
    echo "[MISSING] $project"
    ((missing+=1))
    continue
  fi

  if [[ ! -d "${project_path}/.git" ]]; then
    git -C "$project_path" init -q -b "$DEFAULT_BRANCH"
    echo "[INIT] $project"
  fi

  # stage everything but nested repos
  git -C "$project_path" add -A

  if git -C "$project_path" diff --cached --quiet; then
    if git -C "$project_path" rev-parse --verify HEAD >/dev/null 2>&1; then
      echo "[SKIP] Already committed: $project"
      ((already_committed+=1))
    else
      echo "[EMPTY] No files to commit: $project"
      ((empty_repos+=1))
    fi
    continue
  fi

  git -C "$project_path" commit -q -m "$INIT_MESSAGE"
  echo "[COMMIT] $project"
  ((created_commits+=1))
done < "$MANIFEST_FILE"

echo
echo "Finished. Commits created: $created_commits | Already committed: $already_committed | Empty: $empty_repos | Missing: $missing"
