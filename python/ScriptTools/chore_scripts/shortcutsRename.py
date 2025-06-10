import os
import sys
import ctypes
import time
import winreg
from ctypes import wintypes


# 获取真实桌面路径的终极方案
def get_custom_desktop():
    try:
        # 方法1：读取注册表获取实际桌面路径
        with winreg.OpenKey(
            winreg.HKEY_CURRENT_USER,
            r"Software\Microsoft\Windows\CurrentVersion\Explorer\User Shell Folders",
            0,
            winreg.KEY_READ,
        ) as key:
            path, _ = winreg.QueryValueEx(key, "Desktop")
            expanded = os.path.expandvars(path)
            if os.path.isdir(expanded):
                return expanded
    except Exception as e:
        pass

    # 方法2：兼容企业环境重定向
    buf = ctypes.create_unicode_buffer(wintypes.MAX_PATH)
    if ctypes.windll.shell32.SHGetFolderPathW(0, 0x0010, 0, 0, buf) == 0:
        return buf.value

    # 方法3：终极回退方案
    return os.path.join(os.environ["USERPROFILE"], "Desktop")


def debug_log(message):
    """智能日志记录到临时目录"""
    log_path = os.path.join(os.environ["TEMP"], "desktop_rename.log")
    with open(log_path, "a", encoding="utf-8", errors="ignore") as f:
        timestamp = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
        f.write(f"[{timestamp}] {message}\n")


def is_admin():
    """准确检测管理员权限"""
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False


def secure_rename(src, dst):
    """增强型安全重命名"""
    for _ in range(3):
        try:
            if os.path.exists(dst):
                os.remove(dst)
            os.rename(src, dst)
            return True
        except WindowsError as e:
            if e.winerror == 32:  # 文件被占用
                time.sleep(0.5)
                continue
            debug_log(f"重命名失败 [{e.winerror}]: {src} -> {dst}")
            return False
    return False


def main():
    debug_log("脚本启动")

    desktop_path = get_custom_desktop()
    debug_log(f"解析到的桌面路径: {desktop_path}")

    if not os.path.exists(desktop_path):
        debug_log("错误：桌面路径不存在")
        return

    try:
        items = [
            f
            for f in os.listdir(desktop_path)
            if f.lower().endswith(".lnk") and not f.startswith("~")
        ]
    except Exception as e:
        debug_log(f"读取目录失败: {str(e)}")
        return

    debug_log(f"找到 {len(items)} 个快捷方式")

    for idx, name in enumerate(items, 1):
        src = os.path.join(desktop_path, name)
        unique = f"{os.getpid()}_{time.time_ns()}"
        new_name = f"\u00a0\u200b{unique}.lnk"  # 不可见前缀
        dst = os.path.join(desktop_path, new_name)

        if secure_rename(src, dst):
            debug_log(f"成功: {name} -> {new_name}")
        else:
            debug_log(f"失败: {name}")

    # 强制刷新
    ctypes.windll.user32.SendMessageTimeoutW(0xFFFF, 0x1A, 0, None, 0, 1000, None)
    ctypes.windll.shell32.SHChangeNotify(0x8000000, 0x1000, None, None)
    debug_log("操作完成")


if __name__ == "__main__":
    # 确保控制台可见
    ctypes.windll.kernel32.AllocConsole()

    try:
        if not is_admin():
            debug_log("请求提权")
            params = f'"{sys.executable}" "{__file__}"'
            ctypes.windll.shell32.ShellExecuteW(
                None, "runas", sys.executable, params, None, 1
            )
        else:
            print("正在处理桌面快捷方式...")
            main()
            print(f"操作完成，日志已保存至：{os.environ['TEMP']}\\desktop_rename.log")
            print("请检查：")
            print("1. 桌面图标名称是否隐藏")
            print("2. 按F5刷新确认是否生效")
            input("按回车退出...")
    except Exception as e:
        debug_log(f"致命错误: {str(e)}")
    finally:
        ctypes.windll.kernel32.FreeConsole()
