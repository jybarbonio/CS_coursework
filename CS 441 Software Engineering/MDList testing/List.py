from functools import partial
import re

from kivy.lang import Builder
from kivy.clock import Clock
from kivy.core.window import Window
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.label import Label
from kivy.uix.image import Image
from kivy.uix.popup import Popup
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout

from kivymd.app import MDApp
from kivymd.uix.list import *

import cv2                          # OpenCV is under Apache License 2.0, so it is free to use commercially
import numpy as np
from pyzbar.pyzbar import decode    # PyzBar is under the MIT License, which among other things permits modification and re-sale

screen_manager = ScreenManager()

ITEMLIST = []

class List(Screen):
    def __init__(self, **kwargs):
        super(Screen, self).__init__(**kwargs)

        Clock.schedule_interval(self.oncvscan, 1.0/1.0)
        self.cam = cv2.VideoCapture(1)
        self.prior = None

    def oncvscan(self, *args):
        success, frame = self.cam.read()

        if(screen_manager.current == "List"):
            if(len(decode(frame)) > 0):
                if(decode(frame)[0].data != self.prior):
                    print("barcode found")
                    self.prior = decode(frame)[0].data
                    self.addscanitem(frame)
                else:
                    print("Repeated barcode scan! Briefly remove from camera and scan again.")
            else:
                print("barcode not found")
                self.prior = ""

    def addscanitem(self, frame):
        bdata = decode(frame)[0]
        bliteral = bdata.data.decode('utf-8')
        print("Added TYPE:", bdata.type, "| DATA:", bliteral, "| @ mem loc", self.ids.mdlITEMLIST)
        item = [ "NAME", 2.99, bliteral, 2, "soup.png", bdata.type ]

        mdlitem = ThreeLineAvatarListItem(
            text = str(item[0]),              # product name
            secondary_text = str(item[1]),    # price
            tertiary_text = str(item[2])      # barcode
        )

        mdlitem.add_widget(IconLeftWidget(icon = str(item[4])))     # product picture
        mdlitem.bind(on_release = self.deleteitem)

        print(self.ids.total.text)
        it = float(re.search("(\d+\.\d\d)", str(self.ids.total.text)).group())
        it += item[1]
        print(str(it))

        self.ids.total.text = ""
        self.ids.total.text = str(it)

        self.ids.mdlITEMLIST.add_widget(mdlitem)

    def deleteitem(self, obj):
        tTotal = float(re.search("(\d+\.\d\d)", str(self.ids.total.text)).group())
        sub = float(re.search("(\d+\.\d\d)", str(obj.secondary_text)).group())
        tTotal -= sub

        self.ids.total.text = str(tTotal)
        
        print("deleting item in: ", self, " | ", obj.parent)
        obj.parent.remove_widget(obj)

    def deleteallitems(self, obj):
        self.ids.mdlITEMLIST.clear_widgets()
        self.ids.total.text = "0.00"

class ListApp(MDApp):
    def build(self):
        self.theme_cls.theme_style = "Dark"

        screen_manager.add_widget(List(name = "List"))
        return screen_manager

if __name__ == '__main__':
    ListApp().run()