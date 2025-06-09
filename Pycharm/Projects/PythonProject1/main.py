import math
import subprocess

from ugot import ugot
import time
import threading
camera_center_x = 320
camera_center_y = 240
max_rotate_speed = 60
base_angle2 = 90
base_angle3 = -80

u = ugot.UGOT()
u.initialize("192.168.227.160")
u.load_models(["line_recognition"])
time.sleep(2)
u.set_track_recognition_line(0)
# 创建PID控制器。
pid_turn = u.create_pid_controller()
# 设置PID参数
pid_turn.set_pid(0.2, 0.001, 0)
offset = 0
# 起始距离物块量
Distance = 20
# 加载识别
flag_1 = 0
# 颜色
target_color = "红色"
# 路线
fin_line = "B"
if fin_line == "A":
    fin1 = 1
if fin_line == "B":
    fin1 = 2
# 标签
Tagid = 0
# 区间定位
flagqqq = 1


def main():
    control = MoveControl()
    # 关节角度控制
    u.mechanical_joint_control(0, 0, 0, 500)
    try:

        target_color_str = str(target_color)
        fin_line_str = str(fin_line)

        # TTS

        u.play_audio_tts(
            "我要搬运{}物块并运输至{}号存储区".format(target_color_str, fin_line_str),
            0,
            True,
        )
        # 控制小车前进
        u.mechanical_single_joint_control(3, -45, 500)
        control.forward()
        time.sleep(1)
        print("开始这个啦")
        # TTS

        subprocess.run(["python", r"D:\Code Files\tempStorage\睿抗机器人\睿抗机器人\Ugot\Ugot\task2.py"])

    finally:
        control.mecanum_stop()


class MoveControl:

    def __init__(self) -> None:
        # 前进速度
        self.forward_speed = 20
        # 索引
        self.intersection_index = -1
        # 路口标志
        self.is_cross = False
        u.mechanical_arms_restory()

    def mecanum_stop(self):
        u.mecanum_stop()

    # 抓物块
    def grab_object(self):
        u.mechanical_arms_restory()
        u.mechanical_clamp_release()
        time.sleep(1)
        u.mechanical_joint_control(0, -60, -10, 1500)
        time.sleep(2)
        # 闭合夹手
        u.mechanical_clamp_close()
        time.sleep(2)
        u.mechanical_joint_control(0, 50, 50,1500)
        time.sleep(1)
        u.mechanical_joint_control(0, 20, 30, 1500)

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
        flag_1 = 0
        global Distance  # 使用全局变量
        global flagqqq
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
                # 第一个路口
                if self.intersection_index == 0:
                    print("识别到第一个路口，向前走0.5秒然后向右转90度")
                    # 向前走
                    u.mecanum_move_xyz(0, self.forward_speed - 5, 0)
                    time.sleep(1.3)
                    u.mecanum_stop()
                    # 右转90度
                    u.mecanum_move_xyz(0, 0, -max_rotate_speed)
                    time.sleep(1.7)  # 根据实际情况调整时间，以完成90度旋转
                    u.mecanum_stop()
                if self.intersection_index == 1:
                    print(
                        "识别到第二个路口，向前走0.5秒然后向右转90度,在直走0.8秒到达第三个路口进行右转，接着直走进入中间空白区域"
                    )
                    # 向前走
                    u.mecanum_move_xyz(0, self.forward_speed - 5, 0)
                    time.sleep(1.3)
                    u.mecanum_stop()
                    # 右转90度
                    u.mecanum_move_xyz(0, 0, -max_rotate_speed)
                    time.sleep(1.8)
                    # 根据实际情况调整时间，以完成90度旋转
                    u.mecanum_stop()
                    # 直走到第三个路口
                    u.mecanum_move_xyz(0, self.forward_speed, 0)
                    time.sleep(2.8)
                    # 右转90度
                    u.mecanum_move_xyz(14, 0, 0)  # 右移
                    time.sleep(1)  # 适当的延迟以稳定旋转
                    u.mecanum_move_xyz(0, 0, -61)  # 右转
                    time.sleep(
                        1.85
                    )  # 旋转所需的时间，根据实际情况调整（这里假设1.5秒完成90度旋转）
                    u.mecanum_move_xyz(0, 30, 0)  # 向前走

                    time.sleep(1.76)
                    u.mecanum_stop()
                    u.mecanum_move_xyz(0, 0, -61)  # 右转
                    time.sleep(
                        0.6
                    )  # 旋转所需的时间，根据实际情况调整（这里假设1.5秒完成90度旋转）
                    u.mecanum_stop()

                    # 扫描物块所在位置

                    u.load_models(["color_recognition"])
                    grab_object = GrabObject()
                    start_time = time.time()
                    observed_colors = set()
                    while (
                        time.time() - start_time < 100
                    ):  # 转动10秒，调整时间以确保观察到整个360度
                        color_info = u.get_color_total_info()
                        [
                            color,
                            type,
                            target_center_x,
                            target_center_y,
                            height,
                            width,
                            area,
                        ] = color_info

                        if len(color) > 0 and target_center_x != -1:
                            observed_colors.add(color)
                            print(f"识别到颜色: {color}")
                            if color == target_color:
                                break

                        # 控制小车原地旋转
                        print("平移")
                        if time.time() - start_time < 1:
                            u.mecanum_move_xyz(0, 0, 40)
                            time.sleep(0.1)  # 适当的延迟以稳定旋转
                            flagqqq = 1
                        if (
                            time.time() - start_time > 1
                            and time.time() - start_time < 2
                        ):
                            u.mecanum_move_xyz(-3, 0, 0)  # 左移
                            time.sleep(0.1)  # 适当的延迟以稳定旋转
                            flagqqq = 1
                        if (
                            time.time() - start_time > 2
                            and time.time() - start_time < 5
                        ):
                            u.mecanum_move_xyz(0, 0, 38)
                            time.sleep(0.1)  # 适当的延迟以稳定旋转
                            flagqqq = 0
                        if time.time() - start_time > 5:
                            u.mecanum_move_xyz(-7, 0, 0)  # 左移
                            time.sleep(0.1)  # 适当的延迟以稳定旋转
                            flagqqq = 0
                    grab_object.go_and_grap_object(target_color)
                    # 第一次找小物块
                    # 起始距离物块量
                    Distance = 20
                    reach_target(target_color)
                    print("我靠近啦1")
                    # 再校准一次
                    grab_object.go_and_grap_object(target_color)
                    u.mecanum_stop()
                    time.sleep(1)
                    # 第二次靠近小物块
                    Distance = 8.5
                    print(Distance)
                    reach_target(target_color)
                    print("我靠近啦2")
                    # 抓物块
                    u.mecanum_move_xyz(0, 5, 0)
                    time.sleep(0.6)
                    u.mecanum_stop()
                    self.grab_object()
                    # 倒退
                    print(flagqqq)
                    if flagqqq == 1:
                        u.mecanum_move_xyz(0, -30, 0)  # 后退
                        time.sleep(1)
                        u.mecanum_stop()
                    if flagqqq == 0:
                        u.mecanum_move_xyz(0, -10, 0)  # 后退
                        time.sleep(1)
                        u.mecanum_stop()

                    # 标签定位
                    u.load_models(["apriltag_qrcode"])
                    time.sleep(1)

                    # 实例化 FaceAprilTag 类
                    apriltag_tool = FaceAprilTag(u)
                    tagid = Tagid
                    apriltag_tool.find_apriltag_and_face_it(tagid)
                    time.sleep(1)
                    # 定位之后左转
                    u.mecanum_move_xyz(0, -30, 0)  # 后退
                    time.sleep(1.1)
                    u.mecanum_stop()
                    u.mecanum_move_xyz(-5, 0, 0)  # 左移
                    time.sleep(0.6)
                    u.mecanum_stop()
                    u.mecanum_move_xyz(0, 0, -max_rotate_speed)
                    time.sleep(0.3)
                    u.mecanum_stop()
                    u.load_models(["apriltag_qrcode"])
                    time.sleep(1)

                    # 实例化 FaceAprilTag 类
                    apriltag_tool = FaceAprilTag(u)
                    apriltag_tool.find_apriltag_and_face_it(tagid)
                    time.sleep(1)
                    u.mecanum_move_xyz(0, -10, 0)  # 后退
                    time.sleep(0.8)
                    u.mecanum_stop()
                    u.mecanum_turn_speed(2, 70)  # 左转
                    time.sleep(1.53)
                    u.mecanum_stop()
                    u.mecanum_move_xyz(0, -12, 0)  # 后退
                    time.sleep(0.8)
                    u.mecanum_stop()
                    print("找黑线")
                    u.mecanum_move_xyz(12, 0, 0)  # 右移
                    time.sleep(1.3)
                    u.mecanum_stop()
                    print("我结束啦")
                    print("最后")
                    break
            # 巡线前进
            u.mecanum_move_xyz(0, self.forward_speed, -int(rotate_speed))


class GrabObject:

    def __init__(self) -> None:
        # 创建PID控制器
        self.pid_rotate_speed = u.create_pid_controller()
        # 设置PID控制器参数
        self.pid_rotate_speed.set_pid(0.3, 0, 0.01)

        self.pid_forward_speed = u.create_pid_controller()
        self.pid_forward_speed.set_pid(0.9, 0, 0.001)

        self.gap = 0

    #
    def go_and_grap_object(self, target_color):
        start_y_speed = 0
        # 调整小车朝向
        self.adjust_direction(start_y_speed, target_color)

    # 计算小车原地转动的速度
    def get_rotate_speed(self, target_color):
        color_info = u.get_color_total_info()
        [color, type, target_center_x, target_center_y, height, width, area] = (
            color_info
        )
        if (
            len(color) == 0
            or len(type) == 0
            or target_center_x == -1
            or str(target_color) != color
        ):
            target_center_x = 460  # ！
            return -30

        gap = target_center_x - camera_center_x
        # 调用PID
        rotate_speed = round(self.pid_rotate_speed.update(gap))
        if rotate_speed > max_rotate_speed:
            rotate_speed = max_rotate_speed
        if rotate_speed < -max_rotate_speed:
            rotate_speed = -max_rotate_speed
        return rotate_speed

    # 调整小车朝向
    def adjust_direction(self, forward_speed, target_color):
        # 获取小车旋速度
        rotate_speed = self.get_rotate_speed(target_color)
        while abs(rotate_speed) > 3:
            u.mecanum_move_xyz(0, forward_speed, int(rotate_speed))
            # 计算小车原地转动速度
            rotate_speed = self.get_rotate_speed(target_color)


max_forward_speed = 10

# 创建PID控制器
pid_forward_speed = u.create_pid_controller()
# 设置PID控制参数
pid_forward_speed.set_pid(0.7, 0, 0.002)


# 计算前进速度（负数就表示后退速度）
def get_forward_speed(target_color):
    # 获取传感器数据
    distance = u.read_distance_data(21)
    print("distance:", distance)
    dis = Distance - distance
    # 调用PID
    forward_speed = round(pid_forward_speed.update(dis))
    if forward_speed > max_forward_speed:
        forward_speed = max_forward_speed
    if forward_speed < -max_forward_speed:
        forward_speed = -max_forward_speed
    print("forward_speed:", forward_speed)
    return forward_speed


# 靠近目标
def reach_target(target_color):
    forward_speed = 3
    flag = True
    while flag:
        color_info = u.get_color_total_info()
        print(color_info)
        [color, type, target_center_x, target_center_y, height, width, area] = (
            color_info
        )
        if (
            len(color) == 0
            or len(type) == 0
            or target_center_x == -1
            or str(target_color) != color
        ):
            u.mecanum_stop()
        else:
            flag = False
    while abs(forward_speed) > 1:
        direction = 0 if forward_speed > 0 else 1
        print("direction:", direction)
        u.mecanum_move_speed(direction, abs(forward_speed))
        # 获取小车前进速度
        forward_speed = get_forward_speed(target_color)

    u.mecanum_stop()


class FaceAprilTag:
    def __init__(self, ugot) -> None:
        self.u = ugot
        pass

    def find_apriltag_and_face_it(self, tagid):
        tag = self.find_april_tag(tagid)
        self.approach_apriltag(tagid, tag)

    def get_apriltag_total_info_by_id(self, tagid=0):
        a = self.u.get_apriltag_total_info()
        for info in a:
            id = info[0]
            if id == tagid:
                return info
        return None

    def check_degreey(self, degreey):
        if degreey < 90 and degreey > 0:
            degreey = 180 - degreey
        if degreey < 0 and degreey > -90:
            degreey = -180 - degreey

        if degreey < 0:
            degreey = -180 - degreey
        if degreey > 0:
            degreey = 180 - degreey
        return degreey

    def find_april_tag(self, tagid=0):
        while True:
            tag = self.get_apriltag_total_info_by_id(tagid)
            if tag is not None and tag[0] == tagid:
                (
                    id,
                    center_x,
                    center_y,
                    height,
                    width,
                    area,
                    distance5,
                    distance7,
                    distance10,
                    x,
                    y,
                    z,
                ) = tag
                gap = camera_center_x - center_x
                print(f"gap to center is {gap}")
                if abs(gap) < 100:
                    self.u.mecanum_stop()
                    return tag
            self.u.mecanum_turn_speed(2, 16)

    def approach_apriltag(self, tagid, info):
        (
            id,
            center_x,
            center_y,
            height,
            width,
            area,
            distance5,
            distance7,
            distance10,
            x,
            y,
            z,
        ) = info
        b = abs(round(distance5 * 100 * 0.70))
        if b > 20:
            fd = round(b)
            self.u.mecanum_move_speed_times(0, 20, b, 1)
            self.u.mecanum_stop()
            info = self.get_apriltag_total_info_by_id(tagid)
            if info is None:
                info = self.find_april_tag(tagid)
            (
                id,
                center_x,
                center_y,
                height,
                width,
                area,
                distance5,
                distance7,
                distance10,
                x,
                y,
                z,
            ) = info
        degreey = math.degrees(y)
        degreey = self.check_degreey(degreey)
        print("approach_apriltag", id, distance5, degreey)

        direct = 3 if degreey > 0 else 2
        direct_str = "右转" if degreey > 0 else "左转"
        siny = math.sin(y)
        dist_offset = abs(int(siny * distance5 * 100))
        d = abs(int(degreey))
        if d > 0:
            print(f"approach_apriltag {direct_str}:{degreey}")
            self.u.mecanum_turn_speed_times(direct, 60, d, 2)
            self.u.mecanum_stop()

        left_right_flag = 90 if degreey < 0 else -90
        left_right_flag_str = "右移" if degreey < 0 else "左移"
        total_offset_dist = dist_offset
        if abs(total_offset_dist) > 0:
            print(f"approach_apriltag {left_right_flag_str}:{total_offset_dist}")
            self.u.mecanum_translate_speed_times(
                left_right_flag, 30, total_offset_dist, 1
            )


if __name__ == "__main__":
    main()
