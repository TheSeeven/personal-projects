# Repo split guide (where the changes are)

If you're new to Codex, here's exactly where the repo-splitting changes were made.

## Files added at the root of this repository

- `project-repos.manifest`
  - List of all project folders that should be individual repos.
- `split-projects-into-repos.sh`
  - Creates `.git` folders in each manifest path (`git init`).
- `bootstrap-project-repos.sh`
  - Creates initial commits inside each individual project repo.
- `show-project-repos-status.sh`
  - Shows where each project repo exists on disk and its current HEAD commit.

## How to verify in your terminal

From repository root (`/workspace/personal-projects`):

```bash
./show-project-repos-status.sh
```

This prints lines like:

- `[REPO] dice -> /workspace/personal-projects/dice (HEAD abc1234)`
- `[NO GIT] ...` if a project has no `.git`
- `[MISSING] ...` if a manifest path doesn't exist

## Important

These project repos are local until you add remotes and push them.
