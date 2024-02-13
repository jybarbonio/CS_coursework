# Card.py

'''
Name: John Barbonio
ID: 0518876
Date: 14 April 2020
Desc: P2 Assignment 7 Inheritance
'''
from enum import Enum

import sys
import random
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *

class Card(QPixmap):
	def __init__(self, cardVal):
		random.seed()
		QPixmap.__init__(self, "img\\" + str(cardVal) + ".gif")
		self.getCardValues(cardVal)

	def getRandomCard(self):
		path = random.randint(101, 152)  # randint is inclusive ranges 1, and 155 # alternatively use randrangeprint(path)

		return "img\\" + str(path) + ".gif", path	# returns a tuple, the file path, and the specific random number

	def getCardBack(self):
		return "img\\155.gif"

	def getCardValues(self, value):
		self.suit = Suit(1)

		if(value >= 140):
			self.suit = 3
		elif(value >= 127 and value < 140):
			self.suit = 2
		elif(value >= 114 and value < 127):
			self.suit = 4
		else:
			self.suit = 1

		temp = (((value - 100) - 1)) % 13 if (((value - 100) - 1) % 13) < 10 else 10
		self.cardValue = 11 if temp == 0 else temp

	def getValue(self):
		return self.cardValue

	def getCard(self):
		filePath, value = self.getRandomCard()
		self.imgCard = QPixmap(filePath)
		self.getCardValues(value)

		return self.imgCard
	def getSuit(self):
		return self.suit

class Suit(Enum):	# "Inside the module Card.py", derived from Enum
	DIAMONDS = 1
	HEARTS = 2
	SPADES = 3
	CLUBS = 4

class CardBack(Card):
	def __init__(self):
		Card.__init__(self, 155)

class Deck(Card):
	def __init__(self):
		self.cardList = []
		self.index = 0
		self.lastCard = 45
		self.loadCards()
	
	def loadCards(self):
		for i in range(101, 153):

			self.cardList.append(Card(i))
			self.index = self.index + 1

		self.shuffle()

	def shuffle(self):
		random.shuffle(self.cardList)

	def deal(self):
		if(self.index >= self.lastCard):
			self.shuffle()
			self.index = 0

		self.index = self.index + 1
		return self.cardList[self.index]