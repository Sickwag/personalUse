import math
import subprocess

from ugot import ugot
import time
from main1 import fin1 as fin
import threading

from openCamera import camera_test

camera_center_x = 320
camera_center_y = 240
max_rotate_speed = 60

u = ugot.UGOT()
u.initialize("192.168.227.160")
u.load_models(["line_recognition"])
time.sleep(2)
u.set_track_recognition_line(0)

# 创建PID控制器
pid_turn = u.create_pid_controller()

# 设置PID参数
pid_turn.set_pid(0.2, 0.001, 0)
offset = 0
fin = fin + 1


def main():
    control = Move()
    try:
        # 控制小车前进
        control.forward()
        u.play_audio_tts("任务一已完成", 0, True)
    finally:
        control.mecanum_stop()


class Move:
    def __init__(self) -> None:
        # 前进速度
        self.forward_speed = 20
        # 索引
        self.intersection_index = -1
        # 路口标志
        self.is_cross = True

    def mecanum_stop(self):
        u.mecanum_stop()

    # 计算小车原地转动的速度
    def get_rotate_speed(self, check_cross=False):
        line_info = u.get_single_track_total_info()
        print(line_info)

        offset, line_type, x, y = line_info

        old_is_cross = self.is_cross

        self.is_cross = line_type == 2 or line_type == 3

        if line_type == 2 or line_type == 3:
            print(line_info)
        if line_type == 0:
            return 0, line_type, 0, 0
        # 调用PID
        rotate_speed = round(pid_turn.update(offset))
        print("offset=", offset)
        if rotate_speed > max_rotate_speed:
            rotate_speed = max_rotate_speed
        if rotate_speed < -max_rotate_speed:
            rotate_speed = -max_rotate_speed
        return rotate_speed, line_type, x, y

    # 控制小车前进
    def forward(self):
        while True:
            old_is_cross = self.is_cross
            # 获取旋转速度
            speed_info = self.get_rotate_speed()

            rotate_speed, line_type, x, y = speed_info
            new_is_cross = self.is_cross

            if old_is_cross and not new_is_cross:
                self.intersection_index = self.intersection_index + 1
                print(
                    f"------------------------路口计数增加，序号：{self.intersection_index + 1}, 坐标x:{x}, y:{y}------------------------"
                )

                if self.intersection_index == 1:
                    # 识别到第二三个路口，向前走0.5秒然后向右转90度
                    print("识别到第二个路口，向前走0.5秒然后向右转90度")
                    u.mecanum_move_xyz(0, 20, 0)  # 向前走
                    time.sleep(1.1)
                    u.mecanum_stop()
                    u.mecanum_move_xyz(0, 0, -60)  # 右转
                    time.sleep(
                        1.7
                    )  # 旋转所需的时间，根据实际情况调整（这里假设1.5秒完成90度旋转）
                    u.mecanum_stop()
                    continue

                if self.intersection_index == fin:
                    # 识别到第二个路口，向前走0.5秒然后向右转90度
                    print("识别到第三个路口，向前走0.5秒然后向右转90度")
                    u.mecanum_move_xyz(0, 20, 0)  # 向前走
                    time.sleep(1)
                    u.mecanum_stop()
                    u.mecanum_move_xyz(0, 0, -60)  # 右转
                    time.sleep(
                        1.7
                    )  # 旋转所需的时间，根据实际情况调整（这里假设1.5秒完成90度旋转）
                    u.mecanum_stop()
                    continue
                if self.intersection_index == fin + 1:
                    # 识别到第二个路口，向前走0.5秒然后向右转90度
                    print("识别到第三个路口，向前走0.5秒然后向右转90度")
                    u.mecanum_move_xyz(0, 20, 0)  # 向前走
                    time.sleep(0.8)
                    u.mecanum_stop()
                    u.mechanical_single_joint_control(3, 45, 500)
                    u.mechanical_single_joint_control(2, -45, 500)
                    time.sleep(1)
                    u.mecanum_stop()
                    u.mechanical_clamp_release()
                    return
                if line_type == 0:
                    # 没有识别到线，停止
                    u.mecanum_stop()
                    print("没有识别到线,停止")
                    break
            # 巡线前进
            u.mecanum_move_xyz(0, self.forward_speed, -int(rotate_speed))


if __name__ == "__main__":
    main()
