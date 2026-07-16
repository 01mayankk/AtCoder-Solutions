from pathlib import Path
import re

# Repository root directory
REPOSITORY_ROOT = Path(__file__).resolve().parent.parent

README_FILE = REPOSITORY_ROOT / "README.md"

CONTEST_DIRECTORIES = {
    "AtCoder-Beginner-Contest": "AtCoder Beginner Contest",
    "AtCoder-Regular-Contest": "AtCoder Regular Contest",
    "AtCoder-Grand-Contest": "AtCoder Grand Contest",
    "Educational-DP-Contest": "Educational DP Contest",
}


def count_solutions(contest_directory: Path) -> int:
    """
    Counts solved problems inside a contest directory.

    A problem is considered solved if the problem directory contains
    at least one C++ source file.
    """

    if not contest_directory.exists():
        return 0

    total = 0

    for problem_directory in contest_directory.rglob("*"):
        if not problem_directory.is_dir():
            continue

        has_cpp_file = any(
            file.is_file() and file.suffix.lower() == ".cpp"
            for file in problem_directory.iterdir()
        )

        if has_cpp_file:
            total += 1

    return total


def generate_dashboard() -> str:
    """
    Generates the Project Dashboard section.
    """

    contest_counts = {}

    total_solutions = 0

    for folder_name, display_name in CONTEST_DIRECTORIES.items():
        count = count_solutions(REPOSITORY_ROOT / folder_name)

        contest_counts[display_name] = count
        total_solutions += count

    dashboard = f"""
### 📚 Repository Overview

| Metric | Value |
|:--------|:-----:|
| Total Solutions | **{total_solutions}** |
| AtCoder Beginner Contest | **{contest_counts["AtCoder Beginner Contest"]}** |
| AtCoder Regular Contest | **{contest_counts["AtCoder Regular Contest"]}** |
| AtCoder Grand Contest | **{contest_counts["AtCoder Grand Contest"]}** |
| Educational DP Contest | **{contest_counts["Educational DP Contest"]}** |
"""

    return dashboard.strip()


def update_readme():
    """
    Replaces the repository metrics section inside README.md.
    """

    readme = README_FILE.read_text(encoding="utf-8")

    replacement = generate_dashboard()

    pattern = re.compile(
        r"<!-- START_SECTION:repository_metrics -->.*?<!-- END_SECTION:repository_metrics -->",
        re.DOTALL,
    )

    updated = pattern.sub(
        f"<!-- START_SECTION:repository_metrics -->\n\n{replacement}\n\n<!-- END_SECTION:repository_metrics -->",
        readme,
    )

    README_FILE.write_text(updated, encoding="utf-8")


if __name__ == "__main__":
    update_readme()
