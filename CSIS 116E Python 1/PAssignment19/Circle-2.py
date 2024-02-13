# CIRCLE.PY

'''
Name: John Barbonio
ID: 0518876
Date: 07 March 2020
Desc: Assignment 19 Introduction to Classes
'''

import math

class Circle(object):
	# constructor takes in one parameter, radius, but setRadius() can override this. radius' default parameter is 0
	# the assignment did not ask for unique diameter or area properties, so I assume calculate through radius
	def __init__(self, radius = 0):
		# below can also be self.radius = self.getRadius() instead, but then the constructor would be overridden
		self.radius = radius
		self.diameter = self.getDiameter()
		self.area = self.getArea()
	def __str__(self):
		return "Circumference: " + str(self.getCircumference()) + "\nArea: " + str(self.getArea()) + "\nDiameter: " + str(self.getDiameter()) + "\nRadius: " + str(self.radius) + "\n"
	
	# this function is the basis for calculations of everything else, since circle properties are co-dependent on a single property
	def setRadius(self, radius):
		self.radius = radius
	''' # unused
	def getRadius(self):
		return self.radius
	'''

	''' # unused
	def setArea(self, area):
		self.area = area
	'''
	def getArea(self):
		return math.pi * math.pow(self.radius, 2)
	
	''' # unused
	def setDiameter(self, diameter):
		self.diameter = diameter
	'''
	def getDiameter(self):
		return self.radius * 2

	''' # unused
	def setDiameter(self, circumfrence):
		self.circumference = circumference
	'''
	def getCircumference(self):
		return (2 * math.pi) * self.radius
