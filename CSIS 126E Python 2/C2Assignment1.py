# C2ASSIGNMENT1.PY

'''
Name: John Barbonio
ID: 0518876
Date: 19 March 2020
Desc: P2 Assignment 1 A Simple Class
'''

from Lab1 import Lab1

n = Lab1()

num1 = int(input("Please enter a number:\n"))

total = n.sumNums(num1)
result = n.reverseNums(num1)
myList = n.getList(num1)	# not sure if you wanted the original input as a list, or the reverse

print("Sum: ", total, "\nReverse: ", result, sep = "")

print("List:")
for i in range(0, len(myList)):
	print(myList[i])	# automatically prints on new \n line
