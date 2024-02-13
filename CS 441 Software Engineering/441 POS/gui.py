from functools import partial

from kivy.lang import Builder
from kivy.clock import Clock
from kivy.core.window import Window
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.uix.label import Label
from kivy.uix.image import Image

from kivymd.app import MDApp
from kivymd.uix.list import *

import cv2                          # OpenCV is under Apache License 2.0, so it is free to use commercially
import numpy as np
from pyzbar.pyzbar import decode    # PyzBar is under the MIT License, which among other things permits modification and re-sale

#screen_manager = ScreenManager()


Builder.load_file('frontPage.kv')
Builder.load_file('login.kv')
Builder.load_file('mainPOS.kv')
Builder.load_file('cart.kv')
Builder.load_file('reports.kv')
Builder.load_file('addInv.kv')
Builder.load_file('account.kv')

class frontPage(Screen):
    #user=ObjectProperty(None)
    #password=ObjectProperty(None)
    pass

class login(Screen):
    pass

class mainPOS(Screen):
    pass

class cart(Screen):
    pass

class reports(Screen):
    pass

class addInv(Screen):
    pass

class account(Screen):
    pass

#screen_manager.add_widget(frontPage(name="front"))
#screen_manager.add_widget(login(name="login"))
#screen_manager.add_widget(mainPOS(name="main"))
#screen_manager.add_widget(cart(name="cart"))
#screen_manager.add_widget(reports(name="reports"))
#screen_manager.add_widget(addInv(name="invent"))
#screen_manager.add_widget(account(name="account"))

class mainPOS(Screen):
    # params for additem are as follows
    # scr is screen for widget (list item to be added)
    # frame is the frame to be scanned for barcodes by decode func
    def addscanitem(self, scr, success, frame):
        # note that decode gets ALL barcodes in a frame, but we only want the first one detected
        barcodes = decode(frame)
        bdata = barcodes[0].data.decode('utf-8')
        print("barcode found: adding ", bdata, " to mem loc ", scr.ids.mdlstITEMS)

        # placeholder for barcode returning from SQL a list of relevant item properties
        lstItem = [ "NAME", "$X.XX", "ABC-abc-1234", 2, "genericitem.png" ]
        
        # create an item to be added to MDList with evident properties
        item = ThreeLineAvatarListItem(
            text = lstItem[0], 
            secondary_text = lstItem[1], 
            tertiary_text = lstItem[2]
            )
        # add to the MDList item a widget for the icon lest it just be text lines
        # notice 'item' is itself a widget, so widget within a widget
        item.add_widget(IconLeftWidgetWithoutTouch(icon = str(lstItem[4])))

        # attach to the MDList item a self-delete upon click function
        item.bind(on_press = mainPOS().deleteitem)
        scr.ids.mdlstITEMS.add_widget(item)

    # placeholder func as of now, later this will cause a popup where one can add an item by barcode lookup
    def addmanualitem(self, barcode):
        # some code here to query SQL db, giving it barcode and 
        # returning name, price, barcode, amount to purchase, icon

        # hypothetical returned data example from SQL query
        lstItem = [ "NAME", "$X.XX", "ABC-abc-1234", 2, "genericitem.png" ]

        self.item = ThreeLineAvatarListItem(
            text = lstItem[0], 
            secondary_text = lstItem[1],
            tertiary_text = lstItem[2]
            )
        self.item.add_widget(IconLeftWidgetWithoutTouch(icon = str(lstItem[4])))
        self.ids.mdlstITEMS.add_widget(self.item)
    
    # function to self delete MDList item upon click
    # the button passes itself (obj) as arg and you want to delete it,
    #   but the func needs to by invoked via the parent, with parameter being the child (obj) list item
    def deleteitem(self, obj):
        print(self, " | ", obj.parent)
        obj.parent.remove_widget(obj)

    def deleteallitems(self, obj):
        print(self, " | ", obj)
        self.ids.mdlstITEMS.clear_widgets()

class posApp(MDApp):
    def build(self):
        self.theme_cls.theme_style = "Dark"
        self.screen_manager = ScreenManager()
        self.screen_manager.add_widget(frontPage(name="front"))
        self.screen_manager.add_widget(login(name="login"))
        self.screen_manager.add_widget(mainPOS(name="main"))
        self.screen_manager.add_widget(cart(name="cart"))
        self.screen_manager.add_widget(reports(name="reports"))
        self.screen_manager.add_widget(addInv(name="invent"))
        self.screen_manager.add_widget(account(name="account"))

        # check camera every second or so for a barcode
        # Clock does not like passing a func with params, so oncvscan is a middle man
        Clock.schedule_interval(self.oncvscan, 1.0/1.0)
        self.cam = cv2.VideoCapture(1)

        return self.screen_manager

    def oncvscan(self, *args):
        scr = self.screen_manager.get_screen("main")
        success, frame = self.cam.read()

        # you don't want camera to add items when off main item screen
        if(self.screen_manager.current == "main"):
            # if barcode was detected
            if(len(decode(frame)) > 0):
                print("yes barcode")
                mainPOS().addscanitem(scr, success, frame)
            else:
                print("no barcode")

if __name__ == '__main__':
    posApp().run()