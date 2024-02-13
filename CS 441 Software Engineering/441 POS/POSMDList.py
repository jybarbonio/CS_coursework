
from kivymd.app import MDApp
from kivy.lang import Builder
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.core.window import Window
from kivy.uix.label import Label
from kivymd.uix.list import *
from kivy.clock import Clock
from kivy.uix.image import Image

import cv2                          # OpenCV is under Apache License 2.0, so it is free to use commercially
import numpy as np
import time
from pyzbar.pyzbar import decode    # PyzBar is under the MIT License, which among other things permits modification and re-sale

Builder.load_file('POSMDList.kv')

class mainPOS(Screen):


    def onpress(self, pressed, list_id):
        item = TwoLineAvatarListItem(text=f"soup", secondary_text=f"$2.99")
        item.add_widget(IconLeftWidget(icon="soup.png"))
        self.ids.itemlist.add_widget(item)

    def cvCamera(self):
        self.image = Image()
        self.add_widget(self.image)
        self.capture = cv2.VideoCapture(1)
        Clock.schedule_interval(self.load_video, 1.0/10.0)  # 10 fps scan check is modest for cheap cameras

    def load_video(self, *args):
        print("getting vid")

                # img = cv2.imread('1.png')
        # set to 0 to use internal PC/laptop webcam, 1 for peripheral such as an external USB cam
        cap = cv2.VideoCapture(1, cv2.CAP_DSHOW)
        cap.set(3, 640)
        cap.set(4, 480)

        Prev = False  # used to check/break the scanning loop 

        while True:     # probably change this bad condition
            success, img = cap.read()
            for barcode in decode(img):
                myData = barcode.data.decode('utf-8')
                # print(myData, barcode.data, "\n")

                # bounding box overlay to visually to track scans
                # we might be able to implement a preview screen in kivy
                pts = np.array([barcode.polygon], np.int32)
                pts = pts.reshape(-1, 1, 2)
                cv2.polylines(img, [pts], True, (255, 0, 255), 5)

                # prevents overscanning of item if held in camera for too long
                # if new scan isn't same as old one, and a barcode was scanned
                # then it's a different scan or intentionally repeated scan
                # else it is too consistent and thus user is hovering when they should rescan
                if Prev != False and success == True:
                    print("NOT SAME", myData, barcode.data, success, "\n")
                    Prev = False   # update data of previous scan for future scan to check
                elif Prev == True and success == True:
                    print("YES SAME", myData, barcode.data, success, "\n")
                    Prev = True   # update data of previous scan for future scan to check
                else:
                    print("scan failed", success, "\n")
                    Prev = False   # update data of previous scan for future scan to check

            cv2.imshow('Result', img)       # camera view in window
            cv2.waitKey(1)

            # time.sleep(0.2)     # slow barcode read cycle improving

class posApp(MDApp):
    def build(self):
        screen_manager = ScreenManager()
        screen_manager.add_widget(mainPOS(name="main"))

        return screen_manager

if __name__ == '__main__':
    posApp().run()