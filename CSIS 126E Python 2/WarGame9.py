# WarGame.py

'''
Name: John Barbonio
ID: 0518876
Date: 22 April 2020
Desc: P2 Assignment 9 Polymorphism
'''

import sys
import random

from Card import *
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

class WarGame(object):
	def __init__(self):
		self.rightScore = Score()
		self.leftScore = Score()

		self.rightsTurn = True
		self.rightVal = 0
		self.leftVal = 0
		win = self.createWindow("War Game")
		vBox = QVBoxLayout()

		vBox.addLayout(self.createTopPane())
		vBox.addLayout(self.createCardPane())
		vBox.addLayout(self.createButtonPane())
		win.setLayout(vBox)

		deck = Deck()
		
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
		self.lblCardDeck.mousePressEvent = self.mouseClick
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
		self.lblCardLeft.setPixmap(QPixmap(TarotCard()))
		self.lblCardDeck.setPixmap(QPixmap(TarotCard()))
		self.lblCardRight.setPixmap(QPixmap(TarotCard()))
		# Members of the Class - lblCardDeck, lblCardLeft, lblCardRight, getCardBack

	def getCardBack(self):
		return "img\\155.gif"

	def mouseClick(self, event):
		deck = Deck()

		if(self.rightsTurn):
			self.cardRight = deck.deal()
			self.lblCardRight.setPixmap(self.cardRight)    
			self.rightVal = self.cardRight.getValue()
			self.printValue(self.rightVal, "R", Suit(self.cardRight.getSuit()))	# used to observe if addition is working properly and going to the correct card
		else:
			self.cardLeft = deck.deal()
			self.lblCardLeft.setPixmap(self.cardLeft)
			self.leftVal = self.cardLeft.getValue()
			self.printValue(self.leftVal, "L", Suit(self.cardLeft.getSuit()))	# used to observe if addition is working properly and going to the correct card
			if(self.rightVal > self.leftVal):
				# self.rightScore = int(self.tfRight.text())
				self.rightScore += 1
				self.tfRight.setText(str(self.rightScore))

			elif(self.leftVal > self.rightVal):
				# self.leftScore = int(self.tfLeft.text())
				self.leftScore += 1
				self.tfLeft.setText(str(self.leftScore))
			else:
				pass	# tie, scores do not change
		self.rightsTurn = not self.rightsTurn

	def resetGame(self):
		self.rightScore = 0
		self.leftScore = 0

		self.rightVal = 0
		self.leftVal = 0
		self.tfRight.setText("0")
		self.tfLeft.setText("0")
		self.rightsTurn = True
		self.resetCardImages()
	def printValue(self, value, str, Suit):
		print("Value:", value, str, Suit.name, "Suit:", Suit.value) # uses Suit.name and Suit.value so Enum name is not cluttered with Suit. prefixed to it