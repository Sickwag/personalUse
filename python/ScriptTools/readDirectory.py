import os


def list_files_and_folders(directory, include_folders=True):
    """
    列出指定目录中的所有文件和文件夹，并将其写入一个txt文件中。
    :param directory: 要读取的文件夹路径
    :param include_folders: 是否包含文件夹名称，默认为True
    """
    if not os.path.exists(directory):
        print(f"目录 '{directory}' 不存在。")
        return

    items = os.listdir(directory)

    if not include_folders:
        items = [
            item for item in items if os.path.isfile(os.path.join(directory, item))
        ]

    output_file = os.path.join(directory, "filenames.txt")
    with open(output_file, "w", encoding="utf-8") as f:
        for item in items:
            f.write(item.split('.')[0] + "\n")

    print(f"文件名已成功写入 '{output_file}'。")

if __name__ == "__main__":
    folder_path = input("请输入文件夹路径: ")

    include_folders = input("是否包含文件夹名称？(y/n): ").lower() == "y"

    list_files_and_folders(folder_path, include_folders)
