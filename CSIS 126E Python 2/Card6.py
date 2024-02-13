# Card.py

'''
Name: John Barbonio
ID: 0518876
Date: 11 April 2020
Desc: P2 Assignment 6 Composition & Constructor
'''

import sys
import random
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

class Card(object):
	def __init__(self):
		random.seed()
		self.imgCard = QPixmap("img\\155.gif")
		self.cardValue = 0

	def getRandomCard(self):
		path = random.randint(101, 152)  # randint is inclusive ranges 1, and 155 # alternatively use randrangeprint(path)

		return "img\\" + str(path) + ".gif", path	# returns a tuple, the file path, and the specific random number

	def getCardBack(self):
		return "img\\155.gif"

	def getCardValues(self, value):
		# ((path - 100) - 1) % 13
		temp = (((value - 100) - 1)) % 13 if (((value - 100) - 1) % 13) < 10 else 10
		self.cardValue = 11 if temp == 0 else temp

	def getValue(self):
		return self.cardValue

	def getCard(self):
		filePath, value = self.getRandomCard()
		self.imgCard = QPixmap(filePath)
		self.getCardValues(value)

		return self.imgCard