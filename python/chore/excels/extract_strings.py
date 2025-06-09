import openpyxl.utils
import re
import openpyxl.workbook


def modify_cell_content(cell_value):
    """
    修改单元格内容，提取符合 "数字-数字周" 格式的部分，并替换为 "数字-数字"。
    :param cell_value: 单元格内容
    :return: 修改后的内容
    """
    pattern = re.compile(r"(\d+-\d+)周")
    matches = pattern.findall(cell_value)
    if matches:
        modified_content = "，".join(matches)
        return modified_content
    else:
        return None


def process_excel(file_path, sheet_name, cell_range):
    """
    处理 Excel 文件中的单元格内容。
    :param file_path: Excel 文件路径
    :param sheet_name: 工作表名称
    :param cell_range: 单元格范围（如 "A1:B2"）
    """
    workbook = openpyxl.load_workbook(file_path)
    sheet = workbook[sheet_name]
    min_col, min_row, max_col, max_row = openpyxl.utils.range_boundaries(cell_range)

    for row in sheet.iter_rows(
        min_row=min_row, max_row=max_row, min_col=min_col, max_col=max_col
    ):
        for cell in row:
            if cell.value:
                # 将局部变量重命名为 modified_content，避免与函数名冲突
                modified_content = modify_cell_content(cell.value)
                if modified_content:
                    cell.value = modified_content
                else:
                    print(f"{cell.coordinate} matched failed, skipped")
    workbook.save(file_path)
    print(f"{file_path} saved")


if __name__ == "__main__":
    file_path = "D:\\数据保存位置\\Files\\xskb.xlsx"
    sheet_name = "xskb"
    cell_range = "E6:K17"
    # file_path = input("input file path: ")
    # sheet_name = input("input sheet name: ")
    # cell_range = input("input cell range (like: A1:B2): ")
    process_excel(file_path, sheet_name, cell_range)
