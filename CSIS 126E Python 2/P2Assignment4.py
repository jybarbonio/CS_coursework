# C2ASSIGNMENT4.PY

'''
Name: John Barbonio
ID: 0518876
Date: 4 April 2020
Desc: P2 Assignment 4 PyQt Events & Layout
'''

import sys
import random
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

rightsTurn = True
rightVal = 0
leftVal = 0

def getRandomCard():
    # random.seed() # already seeds at the top of __name__
	path = random.randint(101, 152)  # randint is inclusive ranges 1, and 155 # alternatively use randrangeprint(path)
	# print("Current Deck:", path - 100)

	if(path == 101):
		return "img\\" + str(path) + ".gif", 13		# hardcoded alternate if ACE was equal to high, ACE would equal zero if this conditional wasn't in place
	else:
		return "img\\" + str(path) + ".gif", ((path - 100) - 1) % 13	# returns a tuple

def mouseClick(event):	# event is well, mouse event from if the label is clicked by a mouse
	global rightsTurn
	global rightVal
	global leftVal

	cardName, cardVal = getRandomCard()
	print("Score:", cardVal)

	if(rightsTurn == True):
		rightVal = cardVal
		lblCardRight.setPixmap(QPixmap(cardName))
	else:
		leftVal = cardVal
		lblCardLeft.setPixmap(QPixmap(cardName))
		if(rightVal > leftVal and leftVal != 0):
			score = int(tfRight.text())
			score = score + cardVal
			tfRight.setText(str(score))
		elif(leftVal > rightVal and rightVal != 0):
			score = int(tfLeft.text())
			score = score + cardVal
			tfLeft.setText(str(score))
		# this else is used to exclude scoring on the initial card plays (cards are equal to 0 at the beginning), also passes over ties
		else:
			pass
	rightsTurn = not rightsTurn
	# print((cardVal - 100) % 13)
def getCardBack():
	return "img\\155.gif"
def resetCardImages():
	lblCardLeft.setPixmap(QPixmap(getCardBack()))
	lblCardDeck.setPixmap(QPixmap(getCardBack()))
	lblCardRight.setPixmap(QPixmap(getCardBack()))
def resetGame():
	rightVal = 0
	leftVal = 0
	tfRight.setText("0")
	tfLeft.setText("0")
	rightsTurn = True
	resetCardImages()
if __name__ == "__main__":
	random.seed()

	app = QApplication(sys.argv)
	vBox = QVBoxLayout()
	win = QWidget()
	hbTop = QHBoxLayout()	# Score and fields
	hbDeck = QHBoxLayout()	# card deck
	vbBtm = QVBoxLayout()	# reset button

	lblLeft = QLabel("Left:")
	lblRight = QLabel("Right:")
	tfLeft = QLineEdit("0")
	tfRight = QLineEdit("0")

	lblCardLeft = QLabel()
	lblCardDeck = QLabel()
	lblCardRight = QLabel()

	btnReset = QPushButton("Reset")

	win.setLayout(vBox) # vertical box
	win.resize(400, 300)
	win.move(300,300)
	win.setWindowTitle("Simple War Game")

	vBox.addLayout(hbTop)
	vBox.addLayout(hbDeck)
	vBox.addLayout(vbBtm)

	hbTop.setAlignment(Qt.AlignCenter)
	hbTop.addWidget(lblLeft)
	hbTop.addWidget(tfLeft)
	hbTop.addWidget(lblRight)
	hbTop.addWidget(tfRight)

	hbDeck.setAlignment(Qt.AlignVCenter)
	hbDeck.addWidget(lblCardLeft)
	hbDeck.addWidget(lblCardDeck)
	hbDeck.addWidget(lblCardRight)
	lblCardLeft.mousePressEvent = mouseClick
	lblCardDeck.mousePressEvent = mouseClick
	lblCardRight.mousePressEvent = mouseClick
	resetCardImages()	# resets to card backs

	vbBtm.setAlignment(Qt.AlignBottom)
	vbBtm.addWidget(btnReset)
	btnReset.clicked.connect(resetGame)



	win.show()
	sys.exit(app.exec_())
