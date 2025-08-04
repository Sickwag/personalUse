# 获取天气，硬编码版
import requests

def get_history_today():
    url = "https://api.dwo.cc/api/tianqi"
    params = {"districtId": "上海市"}

    try:
        response = requests.get(url, params=params, timeout=10)
        response.raise_for_status()  # 检查 HTTP 错误

        data = response.json()

        if data.get("status") == 200:
            content = data.get("data", [])
            print("weather" + data.get("day", ""))
            print("-" * 50)
            for event in content:
                print(event)
        else:
            print("API error code:", data.get("code"))

    except requests.exceptions.RequestException as e:
        print("网络请求失败:", e)
    except ValueError as e:
        print("JSON 解析失败:", e)


# 调用函数
if __name__ == "__main__":
    get_history_today()
