import os
from pathlib import Path


def parse_structure_file(tree_text: str):
    lines = tree_text.strip().split("\n")
    root = lines[0].rstrip("/")
    struct = {root: []}
    current_path = [root]
    pre_indent = 0
    last_name = ""

    for line in lines[1:]:

        indent = len(line) - len(line.lstrip())
        line = line.strip()

        if indent > pre_indent:
            if last_name:
                current_path.append(last_name)
        elif indent < pre_indent:
            diff = (pre_indent - indent) // 4
            current_path = current_path[:-diff]

        if line.endswith("/"):
            dir_name = line.split("├── ")[-1].split("└── ")[-1].rstrip("/")
            last_name = dir_name
            full_path = os.path.join(*current_path, dir_name)
            struct.setdefault(full_path, [])

        else:
            file_name = line.split("├── ")[-1].split("└── ")[-1]
            parent_dir = os.path.join(*current_path)
            struct[parent_dir].append(file_name)

        pre_indent = indent

    return struct


def create_tree_from_structure(structure: dict):
    for path, items in structure.items():
        Path(path).mkdir(parents=True, exist_ok=True)
        print(f"created FOLDER: {path}")

        for item in items:
            if "/" not in item:
                file_path = Path(path) / item
                file_path.touch()
                print(f"created FILE: {item}")


def main() -> None:
    structure_file_path = input("input struct file path : ")
    with open(structure_file_path, "r", encoding="utf-8") as f:
        tree_text = f.read()

    structure = parse_structure_file(tree_text=tree_text)
    create_tree_from_structure(structure)


if __name__ == "__main__":
    print("Start building...")
    main()
    print("Directory built.")
