#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
MANIFEST_FILE="${ROOT_DIR}/project-repos.manifest"

if [[ ! -f "$MANIFEST_FILE" ]]; then
  echo "Manifest not found: $MANIFEST_FILE" >&2
  exit 1
fi

created=0
skipped=0
missing=0

while IFS= read -r project || [[ -n "$project" ]]; do
  [[ -z "$project" || "$project" =~ ^# ]] && continue

  project_path="${ROOT_DIR}/${project}"

  if [[ ! -d "$project_path" ]]; then
    echo "[MISSING] $project"
    ((missing+=1))
    continue
  fi

  if [[ -d "${project_path}/.git" ]]; then
    echo "[SKIP] Already a git repo: $project"
    ((skipped+=1))
    continue
  fi

  git -C "$project_path" init -q
  echo "[OK] Initialized repo: $project"
  ((created+=1))
done < "$MANIFEST_FILE"

echo

echo "Finished. Created: $created | Skipped: $skipped | Missing: $missing"
