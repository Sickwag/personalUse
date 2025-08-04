# 调用get_baisi接口获取视频，放在C盘默认下载文件夹中
import requests
import os
import webbrowser  # 用于调用默认程序打开图片

# 1. 调用API获取图片URL
url = "https://v2.xxapi.cn/api/heisi"
response = requests.get(url)
result = response.json()

if result["code"] == 200:
    image_url = result["data"]  # 提取图片URL
    print("图片地址:", image_url)

    # 2. 下载图片到本地临时文件
    image_data = requests.get(image_url).content
    temp_path = os.path.join(
        os.environ["TEMP"], "xxapi_image.jpg"
    )  # 保存在系统临时目录
    with open(temp_path, "wb") as f:
        f.write(image_data)

    # 3. 用Windows图片查看器打开
    webbrowser.open(temp_path)  # 调用默认程序打开
else:
    print("API请求失败:", result["msg"])
