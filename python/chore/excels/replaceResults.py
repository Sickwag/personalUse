import openpyxl
import os


def read_file_paths_from_excel(file_path, column_name):
    """
    Read Records in xlsx file
    :param file_path: Excel path
    :param column_name:  like "A" or "B"
    :return: the matched list
    """
    workbook = openpyxl.load_workbook(file_path)
    sheet = workbook.active
    file_paths = []

    # 遍历指定列的所有行
    for row in sheet[column_name]:
        if row.value:  # skip those cells in blank
            file_paths.append(row.value.strip())  # delete blank chars

    return file_paths


def replace_in_file(file_path, search_str, replace_str):
    """
    :param file_path: filepath
    :param search_str: search string
    :param replace_str: replace string
    """
    try:
        with open(file_path, "r", encoding="utf-8") as file:
            content = file.read()

        new_content = content.replace(search_str, replace_str)

        with open(file_path, "w", encoding="utf-8") as file:
            file.write(new_content)

        print(f"$file: {file_path} string '{search_str}' had replaced '{replace_str}'")
    except Exception as e:
        print(f"Error: traverse to {file_path} occurs an error: {e}")


def main():
    # 用户输入
    excel_file = input("input Excel xlsx file path: ")
    column_name = input("input column code like A or B ")
    search_str = input("input the match string:")
    replace_str = input("input the replace string: ")

    file_paths = read_file_paths_from_excel(excel_file, column_name)

    for file_path in file_paths:
        if os.path.exists(file_path):
            replace_in_file(file_path, search_str, replace_str)
        else:
            print(f"Warning: {file_path} doesn't exist, skip")


if __name__ == "__main__":
    main()
