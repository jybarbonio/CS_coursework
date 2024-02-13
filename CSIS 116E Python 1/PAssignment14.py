'''
Name: John Barbonio
ID: 0518876
Date: 22 February 2020
Desc: Assignment 14: Lists and Dictionaries
'''

import math
import random

def createList(row, col) :
	tempList = [[random.randint(1, 100) for x in range(row)] for y in range(col)]
	return tempList

def printList(lst) :
	for row in range(0, len(lst)) :	# len(lst) gets row size
		for col in range(0, len(lst[0])) :	# len(lst[0]) gets column size
			print(lst[row][col], end = "\t")
		print(" ")

def labelValues(lst) :
	tempDict = {}

	for row in range(0, len(lst)) :
		for col in range(0, len(lst[0])) :
			if (lst[row][col] % 2 == 0 and lst[row][col] not in tempDict) :
				tempDict.update({ lst[row][col] : "even" })
			elif (lst[row][col] % 2 == 1 and lst[row][col] not in tempDict):
				tempDict.update({ lst[row][col] : "odd" })
			# else:
				# dupWarning(lst[row][col])
	return tempDict
'''
def dupWarning(n) :		# duplicate warning
	if (n % 2 == 0) :
		print(n, "is a duplicate even")
	else:
		print(n, "is a duplicate odd")
'''

myList = createList(10, 10)
printList(myList)

dictList = {}
dictList.update(labelValues(myList))
print(dictList)

'''
for key in dictList :
	print(key, dictList[key])
'''