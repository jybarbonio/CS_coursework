# P2Assignment12.py

'''
Name: John Barbonio
ID: 0518876
Date: 3 May 2020
Desc: P2 Assignment 12 Recursion
'''

def ones(input, count):

	# recursive exit conditional
	if(input == 0):
		return count

	# recursive parameter modification
	if(input % 2 == 1):
		return ones(input // 2, count + 1)
	else:
		return ones(input // 2, count)

input = int(input("Please enter a number:\n"))

print("The total number of ones in", input, "is", ones(input, 0))