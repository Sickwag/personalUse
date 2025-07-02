import pyperclip
import os
import datetime
import win32clipboard
import win32con
from io import BytesIO
from PIL import Image

output_dir = 'output'
os.makedirs(output_dir, exist_ok=True)

timestamp = datetime.datetime.now().strftime('%Y%m%d_%H%M%S')

try:
    text_content = pyperclip.paste()
    if text_content:
        file_path = os.path.join(output_dir, f'clipboard_text_{timestamp}.txt')
        with open(file_path, 'w', encoding='utf-8') as f:
            f.write(text_content)
        print(f"成功保存文本到 {file_path}")
    else:
        win32clipboard.OpenClipboard()
        if win32clipboard.IsClipboardFormatAvailable(win32con.CF_DIB):
            data = win32clipboard.GetClipboardData(win32con.CF_DIB)
            image = Image.open(BytesIO(data))
            file_path = os.path.join(output_dir, f'clipboard_image_{timestamp}.png')
            image.save(file_path, 'PNG')
            print(f"成功保存图片到 {file_path}")
        else:
            print("剪切板中没有文本或图片")
    win32clipboard.CloseClipboard()
except Exception as e:
    print(f"操作失败: {str(e)}")
