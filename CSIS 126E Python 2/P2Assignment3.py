# C2ASSIGNMENT3.PY

'''
Name: John Barbonio
ID: 0518876
Date: 30 March 2020
Desc: P3 Assignment 3 Introduction to PyQt
'''

import sys
import random
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

def getRandomCard():
    random.seed()
    # Stevenson said between 101 and 152, DOES HE MEAN IN BETWEEN A RANGE OF (102 to 151), OR INCLUSIVE (101 - 152) ??
    path = random.randint(101, 152)  # randint is inclusive ranges 101, and 152 # alternatively could use randrange
    return "img\\" + str(path) + ".gif"

if __name__ == "__main__":
    app = QApplication(sys.argv)
    win = QWidget()
    vBox = QVBoxLayout()
    win.setLayout(vBox)
    
    win.resize(300, 250)
    win.move(300,300)
    win.setWindowTitle("Assignment 3")

    # Labels
    lblTop = QLabel("Random Card")
    lblCard = QLabel()
    lblBtm = QLabel("Nothing Up My Sleeve!")

    # Fonts
    fntTop = QFont("Arial", 24, QFont.Bold)
    fntBtm = QFont("Verdana", 16)
    fntBtm.setItalic(True)

    # Palettes
    palTop = QPalette(lblTop.palette())
    palTop.setColor(QPalette.WindowText, QColor(128, 0, 128))
    palBtm = QPalette(lblBtm.palette())
    palBtm.setColor(QPalette.WindowText, QColor(255, 102, 102))

    # lbl.setText("sets to specified text")
    lblTop.setFont(fntTop)
    lblTop.setPalette(palTop)
    lblTop.setAlignment(Qt.AlignLeft)

    lblCard.setPixmap(QPixmap(getRandomCard()))
    lblCard.setAlignment(Qt.AlignCenter)

    lblBtm.setFont(fntBtm)
    lblBtm.setPalette(palBtm)
    lblBtm.setAlignment(Qt.AlignRight)

    vBox.addWidget(lblTop)
    vBox.addStretch(1)
    vBox.addWidget(lblCard)
    vBox.addStretch(1)
    vBox.addWidget(lblBtm)

    win.show()
    sys.exit(app.exec_())