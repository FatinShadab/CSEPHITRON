"""
My camera application
author : Fatin Shadab
"""
import sys
import cv2
import datetime

from PyQt5.QtWidgets import *
from PyQt5.QtCore import QTimer
from PyQt5.QtGui import QPixmap, QImage, QIcon


class Window(QWidget):
    """Main app window"""

    def __init__(self, **kwargs):
        super().__init__()

        # icon file paths
        self.cam_icon = QIcon(kwargs['capture_icon'])
        self.vcam_icon = QIcon(kwargs['video_capture_icon'])
        self.stop_icon = QIcon(kwargs['stop_video_icon'])

        # video record control variables
        self.is_recording = False
        self.blink_state = True
        self.fourcc = cv2.VideoWriter_fourcc(*'XVID')

        # cv2 related functions
        self.cam_mode = 0
        self.cap = None
        self.frame = None
        self.out = None

        # variables for app window
        self.window_width = 640
        self.window_height = 480

        # image variables
        self.image_label = None
        self.img_width = 640
        self.img_height = 400

        # setup the window
        self.setWindowTitle("Simple Camera")
        self.setGeometry(100, 100, self.window_width, self.window_height)
        self.setFixedSize(self.window_width, self.window_height)

        # Do the work of the while loop
        self.time_out = 5 # in ms
        self.timer = QTimer()
        self.timer.timeout.connect(self.update)
        
        self.ui()

    def ui(self):
        """ contains all ui code """
        # layout
        grid = QGridLayout()
        self.setLayout(grid)

        # image label
        self.image_label = QLabel(self)
        self.image_label.setGeometry(0, 0, self.img_width, self.img_height)

        # picture capture button
        self.cap_btn = QPushButton(self)
        self.cap_btn.setIcon(self.cam_icon)
        self.cap_btn.setStyleSheet("border-radius: 30px; border : 2px solid black; border-width : 3px")
        self.cap_btn.setFixedSize(60, 60)

        self.cap_btn.clicked.connect(self.save_img)

        # video capture button
        self.vcap_btn = QPushButton(self)
        self.vcap_btn.setIcon(self.vcam_icon)
        self.vcap_btn.setStyleSheet("border-radius: 30px; border : 2px solid black; border-width : 3px")
        self.vcap_btn.setFixedSize(60, 60)

        self.vcap_btn.clicked.connect(self.record)

        if not self.timer.isActive():
            self.cap = cv2.VideoCapture(self.cam_mode)
            self.timer.start(self.time_out)

        # Adding widgets in the layout
        grid.addWidget(self.cap_btn, 0, 0)
        grid.addWidget(self.vcap_btn, 1, 0)
        grid.addWidget(self.image_label, 0, 1, 2, 3)

        self.show()
        
    def update(self):
        """ Update frames """
        _, self.frame = self.cap.read()

        if self.is_recording:
            self.vcap_btn.setIcon(self.stop_icon)
            # red dot recoding indicator
            if self.blink_state:
                self.frame = cv2.circle(self.frame, (20, 70), 5, (0, 0, 255), 10)
                self.blink_state = False
            else:
                self.blink_state = True
        else:
            self.vcap_btn.setIcon(self.vcam_icon)

        frame = cv2.cvtColor(self.frame, cv2.COLOR_BGR2RGB)
        height, width, channel = frame.shape
        step = channel * width

        q_frame = QImage(frame.data, width, height, step, QImage.Format_RGB888)
        self.image_label.setPixmap(QPixmap.fromImage(q_frame))

    def save_img(self):
        """ save image from camera """
        cv2.imwrite(f"image_{self.get_date_time()}.jpg", self.frame)

    def record(self):
        """ record video """
        if (self.is_recording):
            self.is_recording = False
        else:
            self.is_recording = True
            self.out = cv2.VideoWriter(
                f"video_{self.get_date_time()}.avi",
                self.fourcc,
                20.0,
                (self.img_width, self.img_height)
            )

    def get_date_time(self) -> str:
        """A method to get the date time information when a picture is clicked"""
        now = datetime.datetime.now()
        return now.strftime("%m_%d_%y_%H_%M_%S")

if __name__ == "__main__":
    capture_icon = "F:/git/CSEPHITRON/Python Lang/resources/camera.svg"
    video_capture_icon = "F:/git/CSEPHITRON/Python Lang/resources/camera-reels.svg"
    stop_video_icon = "F:/git/CSEPHITRON/Python Lang/resources/stop-circle-fill.svg"

    app = QApplication(sys.argv)
    win = Window(
        capture_icon=capture_icon,
        video_capture_icon=video_capture_icon,
        stop_video_icon=stop_video_icon
    )
    sys.exit(app.exec_())