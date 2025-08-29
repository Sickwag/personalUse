
import re
import sys
import argparse
from aliyun_translate import AliyunTranslator

def translate_comment_text(text, translator):
    """
    调用翻译器翻译文本，处理可能出现的API异常。
    """
    if not text.strip():
        return text  # 如果注释为空或只有空白，则不翻译
    try:
        return translator(text)
    except Exception as e:
        print(f"警告: 翻译API调用失败: {e}", file=sys.stderr)
        return text # 如果翻译失败，返回原文

def translate_comments_in_file(file_path: str, source_lang: str = 'auto'):
    """
    读取文件，查找并翻译所有支持的注释类型，然后将结果写回文件。

    :param file_path: 要处理的代码文件的路径。
    :param source_lang: 源语言，默认为'auto'自动检测。
    """
    print(f"正在处理文件: {file_path}...")

    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()
    except Exception as e:
        print(f"错误: 无法读取文件 {file_path}: {e}", file=sys.stderr)
        return

    translator = AliyunTranslator(source_language=source_lang, target_language='zh')

    # 翻译回调函数
    def translate_match(match):
        # 提取捕获组中的注释内容
        comment_content = match.group(1)
        # 翻译注释
        translated_content = translate_comment_text(comment_content, translator)
        # 重建整个注释
        return match.group(0).replace(comment_content, translated_content)

    # 定义各类注释的正则表达式
    # 顺序很重要：先处理多行注释，再处理单行注释
    patterns = [
        r'(/\*.*?\*/)',      # C/C++ 多行注释 /* ... */
        r'("""(.*?)""")',    # Python 多行注释/文档字符串 """..."""
        r"('''(.*?)''')",    # Python 多行注释/文档字符串 '''...'''
        r'(//.*)',           # C/C++ 单行注释 // ...
        r'(#.*)',            # Python 单行注释 # ...
    ]
    
    original_content = content
    for pattern in patterns:
        # 使用 re.DOTALL 使 '.' 可以匹配换行符，这对于多行注释至关重要
        content = re.sub(pattern, translate_match, content, flags=re.DOTALL)

    if content != original_content:
        try:
            with open(file_path, 'w', encoding='utf-8') as f:
                f.write(content)
            print(f"翻译完成，文件已更新: {file_path}")
        except Exception as e:
            print(f"错误: 无法写回文件 {file_path}: {e}", file=sys.stderr)
    else:
        print("未找到需要翻译的注释，或翻译结果与原文相同。")


def main():
    """
    主函数，用于解析命令行参数。
    """
    parser = argparse.ArgumentParser(
        description='将C++或Python代码文件中的注释翻译成中文。',
        epilog='示例: python comment_translator.py your_code_file.cpp'
    )
    parser.add_argument(
        'file',
        type=str,
        help='需要翻译注释的代码文件的路径。'
    )
    parser.add_argument(
        '--lang',
        type=str,
        default='auto',
        help='源语言代码 (例如 "en", "ja")。默认为 "auto" 自动检测。'
    )
    args = parser.parse_args()
    
    translate_comments_in_file(args.file, args.lang)

if __name__ == '__main__':
    main()
