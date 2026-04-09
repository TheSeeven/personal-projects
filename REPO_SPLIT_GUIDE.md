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

## Publishing repos to GitHub safely

Use `publish-project-repos.sh`.

- It avoids the `<YOUR_GITHUB_USERNAME>` placeholder mistake by requiring `--owner` (or auto-detecting via `gh api user`).
- It runs as dry-run by default.
- Use `--apply` to actually create/push repos.

Examples:

```bash
./publish-project-repos.sh --owner TheSeeven --private
./publish-project-repos.sh --owner TheSeeven --private --apply
```

### If you get `CreateRepository` permission errors

Error like:

- `GraphQL: <user> does not have the correct permissions to execute CreateRepository`

means your current `gh` auth token cannot create repos (common in Codespaces).

Fix:

```bash
gh auth logout -h github.com -u TheSeeven
# or simply: gh auth logout -h github.com
gh auth login -h github.com -w -s repo,read:org
```

Then retry in safe mode first:

```bash
./publish-project-repos.sh --owner TheSeeven --private
./publish-project-repos.sh --owner TheSeeven --private --apply
```

If you create repos manually in GitHub first, use push-only mode:

```bash
./publish-project-repos.sh --owner TheSeeven --skip-create --apply
```

### If `gh auth login` says it is using `GITHUB_TOKEN`

In Codespaces, a pre-set `GITHUB_TOKEN` can block storing your own credentials.

Run:

```bash
unset GITHUB_TOKEN
unset GH_TOKEN
gh auth login -h github.com -w -s repo,read:org
gh auth status
```

If you see `nothing added to commit but untracked files present`, inspect and clean your working tree:

```bash
git status --short
# if the files are temporary and you don't need them:
git clean -fd
# or add/commit specific files if you do need them
```

## Bulk delete repos by name pattern (safe dry-run first)

Use `delete-project-repos.sh` to match and delete repos from your GitHub account.

Dry-run preview:

```bash
./delete-project-repos.sh --owner TheSeeven \
  'security-and-criptography*' \
  'cloud-computing-si-iot*' \
  'concurent-and-distributed-programming*' \
  'gui-lab*' \
  'gui-proiect_giu' \
  'gui-*'
```

Apply deletion:

```bash
./delete-project-repos.sh --owner TheSeeven --apply \
  'security-and-criptography*' \
  'cloud-computing-si-iot*' \
  'concurent-and-distributed-programming*' \
  'gui-lab*' \
  'gui-proiect_giu' \
  'gui-*'
```

> Deletion is permanent. Always run dry-run first.
