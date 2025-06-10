import requests
import webbrowser
import os
from tqdm import tqdm  # 进度条库

url = "https://v2.xxapi.cn/api/meinv"

payload = {}
headers = {"User-Agent": "xiaoxiaoapi/1.0.0 (https://xxapi.cn)"}

# 获取视频URL
print("正在获取视频地址...")
response = requests.request("GET", url, headers=headers, data=payload)
video_url = response.json()["data"]

# 下载视频并显示进度
print("开始下载视频...")
temp_path = os.path.join(os.environ["TEMP"], "xxapi_video.mp4")

# 使用流式下载以支持大文件和进度显示
response = requests.get(video_url, stream=True)
total_size = int(response.headers.get("content-length", 0))  # 获取文件总大小
block_size = 1024  # 每次下载的数据块大小

with open(temp_path, "wb") as f:
    # 使用tqdm创建进度条
    progress_bar = tqdm(total=total_size, unit="iB", unit_scale=True)
    for data in response.iter_content(block_size):
        f.write(data)
        progress_bar.update(len(data))  # 更新进度条
    progress_bar.close()

# 检查下载是否完整
if total_size != 0 and progress_bar.n != total_size:
    print("下载可能不完整！")

# 打开视频
print("下载完成，正在打开视频...")
webbrowser.open(temp_path)
