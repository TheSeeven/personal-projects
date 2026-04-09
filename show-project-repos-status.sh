#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")" && pwd)"
MANIFEST_FILE="${ROOT_DIR}/project-repos.manifest"

if [[ ! -f "$MANIFEST_FILE" ]]; then
  echo "Manifest not found: $MANIFEST_FILE" >&2
  exit 1
fi

echo "Root repo path: $ROOT_DIR"
echo "Manifest path:  $MANIFEST_FILE"
echo

while IFS= read -r project || [[ -n "$project" ]]; do
  [[ -z "$project" || "$project" =~ ^# ]] && continue
  project_path="${ROOT_DIR}/${project}"

  if [[ ! -d "$project_path" ]]; then
    echo "[MISSING] $project"
    continue
  fi

  if [[ -d "${project_path}/.git" ]]; then
    head_commit="$(git -C "$project_path" rev-parse --short HEAD 2>/dev/null || true)"
    if [[ -n "$head_commit" ]]; then
      echo "[REPO] $project -> ${project_path} (HEAD ${head_commit})"
    else
      echo "[REPO] $project -> ${project_path} (no commits yet)"
    fi
  else
    echo "[NO GIT] $project -> ${project_path}"
  fi
done < "$MANIFEST_FILE"
