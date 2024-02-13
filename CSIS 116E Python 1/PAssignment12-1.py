'''
Name: John Barbonio
ID: 0518876
Date: 16 February 2020
Desc: Assignment 12 Functions and the Math Class
'''
import math

# I should probably add a func to handle negative exponents but the assignment didn't ask for it so I'll figure that out later
def pythag(s1, s2, strSide) :
	if(strSide == "C" or strSide == "c") :
		return math.sqrt(math.pow(s1, 2) + math.pow(s2, 2)) # result equals square root of (a^2 + b^2)
	elif(strSide == "A" or strSide == "a") :
		return math.sqrt(math.pow(s2, 2) - math.pow(s1, 2)) # result equals square root of (c^2 - b^2)
	elif(strSide == "B" or strSide == "b") :
		return math.sqrt(math.pow(s2, 2) - math.pow(s1, 2)) # #result equals square root of (c^2 - a^2)
	else:
		return 0
def getFloat() :	# "you'll float too you'll float too"
	return float(input("Please enter a float\n"))

a = getFloat()
b = getFloat()
c = pythag(a, b, "C")

print("Side C is equal to", c)
print("Now enter sides B and C and I will solve for A")

a = getFloat()
b = getFloat()
c = pythag(a, b, "A")

print("Side A is equal to", c)
print("Now enter sides A and C and I will solve for B")

a = getFloat()
b = getFloat()
c = pythag(a, b, "B")

print("Side B is equal to", c)