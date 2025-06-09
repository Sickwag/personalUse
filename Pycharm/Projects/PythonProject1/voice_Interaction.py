import time


class Language:
    def __init__(self, ugot_controller):
        self.u = ugot_controller  # 依赖注入，避免全局变量

    def get_task_from_voice(self):
        """通过语音交互获取任务参数"""
        # 欢迎语
        self.u.play_audio_tts("欢迎使用UGOT搬运系统", 0, True)
        time.sleep(0.5)

        # 一次性获取所有信息
        while True:
            self.u.play_audio_tts(
                "请说出完整指令，例如：请搬运红色色块，运输至A号存储区", 0, True
            )
            command = self.u.start_audio_asr()

            if not command:
                self.u.play_audio_tts("没有检测到语音，请重试", 0, True)
                continue

            command = command.lower()

            # 解析颜色
            if any(word in command for word in ["红", "红色"]):
                target_color = "红色"
            elif any(word in command for word in ["绿", "绿色"]):
                target_color = "绿色"
            elif any(word in command for word in ["蓝", "蓝色"]):
                target_color = "蓝色"
            else:
                self.u.play_audio_tts(
                    "没有识别到有效颜色，请包含红色、绿色或蓝色", 0, True
                )
                continue

            # 解析存储区
            if any(word in command for word in ["a", "a区", "a号"]):
                fin_line = "A"
            elif any(word in command for word in ["b", "b区", "b号"]):
                fin_line = "B"
            else:
                self.u.play_audio_tts("没有识别到有效存储区，请包含A区或B区", 0, True)
                continue

            if target_color and fin_line:
                confirm_text = f"您需要搬运{target_color}物体到{fin_line}区"
                self.u.play_audio_tts(confirm_text, 0, True)
                return target_color, fin_line
            # final test, remove before official match start
            # confirm_result = self.u.start_audio_asr()

            # if confirm_result and ("对" in confirm_result or "是的" in confirm_result):
            #     self.u.play_audio_tts('任务已确认，即将开始执行', 0, True)
            #     return target_color, fin_line
            # else:
            #     self.u.play_audio_tts('好的，我们将重新获取指令', 0, True)
