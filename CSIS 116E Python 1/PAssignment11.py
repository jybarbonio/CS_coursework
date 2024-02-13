'''
Name: John Barbonio
ID: 0518876
Date: 09 February 2020
Desc: Assignment 11 Combining Functions, Loops, and Decisions
'''

def sumTo(n1, n2) :
	temp1 = 0
	temp2 = 0
	tempTotal = 0

	if (num1 < num2) :	# I wonder if there is a python function for this 'which is greater' task
		temp1 = num1
		temp2 = num2
	elif (num1 > num2) :
		temp1 = num2
		temp2 = num1
	else:				#I guess if the range is say, only 5 (both numbers inputted being equal), the result would be just 5
		temp1 = num1
		temp2 = num1

	for i in range(temp1, temp2 + 1) : #example: (0, 4) would be adding 0, 1, 2, 3, 4 - range func adds five variables but leaving out end range num, + 1 added to range
		tempTotal += i
	return tempTotal

def getInput() :
	return int(input("Please enter an integer\n"))

num1 = getInput();
num2 = getInput();

total = sumTo(num1, num2)

print("The sum of the range of numbers is", total)