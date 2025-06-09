import threading
from ugot import ugot
import cv2
import numpy as np

got = ugot.UGOT()
camera_stopped = False
got.initialize("192.168.227.160")
got.load_models(["color_recognition"])


def camera_test():
    got.open_camera()
    while not camera_stopped:
        frame = got.read_camera_data()
        if frame is not None:
            nparr = np.frombuffer(frame, np.uint8)
            data = cv2.imdecode(nparr, cv2.IMREAD_COLOR)
            cv2.imshow("camera", data)
            cv2.waitKey(1)


if __name__ == "__main__":
    t1 = threading.Thread(target=camera_test)
    t1.start()
