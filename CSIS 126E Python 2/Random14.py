# Random.py

'''
Name: John Barbonio
ID: 0518876
Date: 10 May 2020
Desc: P2 Assignment 14 Collections
'''

from random import Random

import collections

# inherits random
class Random(Random):
	def __init__(self, seed = 0, min = 0, max = 100):
		self.seed(0)
		self.min = min
		self.max = max
		self.dequeMinSize = 5

		self.randomDeck = collections.deque()
		self.fillDeque()

	def fillDeque(self):
		# clear deque
		self.randomDeck.clear()
		# checks for invalid ranges
		if (self.min > self.max):
			self.min = 0
			self.max = 10
		else:
			pass

		for i in range(0, 250):
			# adds a tuple of an int and a float to the deque (acting as a stack)
			self.randomDeck.append( ( self.randint(self.min, self.max), self.random() ) )

		self.shuffle(self.randomDeck)

	def nextInt(self):
		self.dequeSizeCheck()
		temp = self.randomDeck.pop()
		return int(temp[0] + temp[1])
	
	def nextFloat(self):
		self.dequeSizeCheck()
		temp = self.randomDeck.pop()
		return float(temp[0] + temp[1])

	def nextFraction(self):
		self.dequeSizeCheck()
		temp = self.randomDeck.pop()
		# below is (0-250) + ~1) divided by (max random number size plus 1 (default is 251)) so the result is between 0 - 1
		return ((temp[0] + temp[1]) / (self.max + 1))

	def setRange(self, min, max):
		self.min = min
		self.max = max

		self.fillDeque()

	# checks if vector goes under a certain size (5)
	def dequeSizeCheck(self):
		if (len(self.randomDeck) < self.dequeMinSize):
			self.fillDeque()
		else:
			pass

	def setDequeMinSize(self, size):
		self.dequeMinSize = size
		self.dequeSizeCheck()