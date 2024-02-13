'''
Name: John Barbonio
ID: 0518876
Date: 22 February 2020
Desc: Assignment 13: Working with Lists
'''

import math
import random

def createList(listSize) :	# I guess I can't use len(lst) in the function parameter, doesn't work
	list = []
	for i in range(listSize) :
		list.append(random.randint(1, 100))
	return list

def printList(myList) :
	print(myList)

def smallLarge(myList) :
	lowest = myList[0]
	highest = myList[0]
	for i in range(len(myList)) :
		if (myList[i] < lowest) :
			lowest = myList[i]
		elif (myList[i] > highest) :
			highest = myList[i]

	tupLowHigh = (lowest, highest);	# list uses brackets, tuple uses parentheses
	return tupLowHigh


myList = createList(25)
printList(myList)
result = smallLarge(myList)
print("Lowest:", result[0], "Highest:", result[1])