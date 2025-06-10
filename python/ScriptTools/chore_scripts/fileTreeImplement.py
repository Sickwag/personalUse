import os
from pathlib import Path


def parse_tree_structure(tree_text):
    """Prase Tree struct plain text and store in dict"""
    lines = tree_text.strip().split('\n') # get a array of formatted file or folder name
    root = lines[0].rstrip("/")  # 获取根目录名称
    """
        用来存储所有文件和文件夹的路径
        存储格式为：文件夹名[文件1，文件2，...]
        方便后面create_structure_from_dict函数根据绝对路径创建文件和文件夹
    """
    structure = {
        root: []
    } 
    current_path = [root] # 存储当前处理的文件路径
    prev_indent = 0 # 初始缩进
    last_name = None 

    for line in lines[1:]:
        # 计算缩进级别
        indent = len(line) - len(line.lstrip())
        line = line.strip()

        # 确定当前层级
        if indent > prev_indent: # 如果当前行缩进大于之前行的缩进，说明当前文件或者文件夹是嵌套在上一层中的，所以需要将lastname添加到current_path中，增长路径字符串
            current_path.append(last_name)
        elif indent < prev_indent: # 如果当前行缩进小于之前行，说明上一层文件夹内容已经遍历完，需要回退领
            diff = (prev_indent - indent) // 4 # 确定回退层级
            current_path = current_path[:-diff] # 根据回退层级回退到目标层级路径

        # 处理当前行
        if line.endswith("/"):
            # 这是一个目录
            dir_name = (
                line.split("├── ")[-1].split("└── ")[-1].rstrip("/")
            )  # 如果他以└──或者├──开头，就去掉这个符号和行尾的/目录识别符号，获取文件夹名称
            last_name = dir_name # 文件夹名称
            full_path = os.path.join(
                *current_path, dir_name
            )  # *是解包操作符，它的作用是将 current_path 列表中的元素解包为独立的参数，传递给 os.path.join。
            structure.setdefault(
                full_path, []
            )  # 如果字典存在键 key ，返回它的值。如果不存在，插入值为 default 的键 key ，并返回 default 。 default 默认为 None。
        else:
            # 这是一个文件
            file_name = line.split("├── ")[-1].split("└── ")[-1] # 文件同理，不需要去掉末尾/符号，因为没有
            parent_dir = os.path.join(
                *current_path
            ) 
            structure[parent_dir].append(file_name) # 在structure中的filename文件的对应文件夹中添加文件名，并存电弧

        prev_indent = indent # 更新pre_indent

    return structure


def create_structure_from_dict(structure):
    """create folder and files based on structure"""
    for path, items in structure.items():
        Path(path).mkdir(parents=True, exist_ok=True)
        print(f"created FOLDER: {path}")

        for item in items:
            if "/" not in item:  # 确保是文件而不是子目录
                file_path = Path(path) / item
                """
                    使用给定的路径创建文件。 如果给出了 mode，它将与进程的 umask 值合并以确定文件模式和访问旗标。 如果文件已存在，则当 exist_ok 为真值时函数将成功执行（并且其修改时间将更新为当前时间），在其他情况下则会引发 FileExistsError。
                """
                file_path.touch()
                print(f"created FILE: {file_path}")


def main():
    # 读取树形结构文件
    struct_file_path = input("input the structure file path : ")
    with open(
        struct_file_path,
        "r",
        encoding="utf-8",
    ) as f:
        tree_text = f.read()

    # 解析并创建结构
    structure = parse_tree_structure(tree_text)
    create_structure_from_dict(structure)


# if __name__ == "__main__":
    print("Start building...")
    main()
    print("Directory built.")
