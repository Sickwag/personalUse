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
ip = "192.168.227.160"
u.initialize(ip)

def grab_object():
    u.mechanical_arms_restory()
    u.mechanical_clamp_release()
    time.sleep(1)
    u.mechanical_joint_control(0, -60, -20, 1500)
    time.sleep(2)
    # 闭合夹手
    u.mechanical_clamp_close()
    time.sleep(2)
    u.mechanical_joint_control(0, 50, 50,1500)
    time.sleep(1)
    u.mechanical_joint_control(0, 20, 30, 1500)

def main():
    u.mechanical_clamp_release()
    u.mechanical_arms_restory()
    u.stop_all_servos()
    u.stop_chassis()
    # grab_object()

main()
