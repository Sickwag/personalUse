from ugot import ugot
import time

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
