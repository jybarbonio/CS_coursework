# WarGame.py

'''
Name: John Barbonio
ID: 0518876
Date: 11 April 2020
Desc: P2 Assignment 5 Class Construction
'''

import sys
import random
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

class WarGame(object):
	def __init__(self):
		rightsTurn = True
		rightVal = 0
		leftVal = 0
		win = self.createWindow("War Game")
		vBox = QVBoxLayout()

		vBox.addLayout(self.createTopPane())
		vBox.addLayout(self.createCardPane())
		vBox.addLayout(self.createButtonPane())
		win.setLayout(vBox)

		win.show()
		self.resetCardImages()
		sys.exit(self.app.exec_())

	def createWindow(self, title):
		self.app = QApplication(sys.argv)
		win = QWidget()
		win.resize(400, 300)
		win.move(300,300)
		win.setWindowTitle("Simple War Game")

		# members of class - The application variable (called app in Assignment 4). 
		return win

	def createTopPane(self):
		self.lblScore = QLabel("Score:\t")
		fntScore = QFont("Verdana", 10, QFont.Bold)
		pltScore = QPalette(self.lblScore.palette())
		hbTop = QHBoxLayout()	# hboxScore - Score and fields
		self.lblLeft = QLabel("Left:")
		self.lblRight = QLabel("Right:")
		self.tfLeft = QLineEdit("0")
		self.tfRight = QLineEdit("0")

		self.lblScore.setFont(fntScore)
		pltScore.setColor(QPalette.WindowText, QColor(Qt.red))
		self.lblScore.setPalette(pltScore)

		hbTop.setAlignment(Qt.AlignCenter)	# hboxScore - setting alignment
		hbTop.addWidget(self.lblScore)
		hbTop.addWidget(self.lblLeft)
		hbTop.addWidget(self.tfLeft)
		hbTop.addWidget(self.lblRight)
		hbTop.addWidget(self.tfRight)

		# Members of the class - lblScore, lblLeft, lblRight, tfLeft, tfRight
		return hbTop

	def createCardPane(self):
		hbDeck = QHBoxLayout()	# hbCardPane - card deck
		self.lblCardLeft = QLabel()
		self.lblCardDeck = QLabel()
		self.lblCardRight = QLabel()

		hbDeck.setAlignment(Qt.AlignVCenter)
		hbDeck.addWidget(self.lblCardLeft)
		hbDeck.addWidget(self.lblCardDeck)
		hbDeck.addWidget(self.lblCardRight)

		return hbDeck

	def createButtonPane(self):
		self.btnReset = QPushButton("Reset")
		self.vbBtm = QVBoxLayout()	# reset button

		self.vbBtm.setAlignment(Qt.AlignBottom)
		self.vbBtm.addWidget(self.btnReset)
		self.btnReset.clicked.connect(self.resetGame)

		# Members of the class - btnReset, resetGame
		return self.vbBtm

	def resetGame(self):
		self.rightVal = 0
		self.leftVal = 0
		self.tfRight.setText("0")
		self.tfLeft.setText("0")
		self.rightsTurn = True
		self.resetCardImages()
		# Members of the class - All variables and widgets in this function are members of the class. 

	def resetCardImages(self):
		self.lblCardLeft.setPixmap(QPixmap(self.getCardBack()))
		self.lblCardDeck.setPixmap(QPixmap(self.getCardBack()))
		self.lblCardRight.setPixmap(QPixmap(self.getCardBack()))
		# Members of the Class - lblCardDeck, lblCardLeft, lblCardRight, getCardBack

	def getCardBack(self):
		return "img\\155.gif"
