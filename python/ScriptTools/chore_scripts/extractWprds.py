from spire.doc import *
from spire.doc.common import *

# 创建Document实例
document = Document()
# 加载Word文档
document.LoadFromFile("D:\\edge下载目录\\吉林农业大学本科生科技创新基金-段创举.doc")

# 获取文档的文本内容
document_text = document.GetText()

# 将获取的文本内容保存到文本文件
with open("文档文字.txt", "w", encoding="utf-8") as file:
    file.write(document_text)

document.Close()
