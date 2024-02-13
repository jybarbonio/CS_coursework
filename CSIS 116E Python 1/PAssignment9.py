'''
Name: John Barbonio
ID: 0518876
Date: 09 February 2020
Desc: Assignment 9 Primed Loops
'''
import math

print("This simple calculator has the following fuctions:\nS - Sine\nC - Cosine\nT - Tangent\nR - Square Root\nN - Natural Log\nX - Exit the program")
userInput = input("Please enter a function and a value i.e. T 30 or t 45\n. To close, type x 0")
inputIndex = userInput.split()
op = str(inputIndex[0])
opState = ""
result = 0.0
value = float(inputIndex[1])

while(op != "X" or op != "x") :

	if(op == "S" or op == "s") :
		result = math.sin(value)
		opState = "Sin"
	elif(op == "C" or op == "c") :
		result = math.cos(value)
		opState = "Cos"
	elif(op == "T" or op == "t") :
		result = math.tan(value)
		opState = "Tan"
	elif(op == "R" or op == "r") :
		result = math.sqrt(value)
		opState = "Square Root"
	elif(op == "N" or op == "n") :
		result = math.log10(value)
		opState = "Natural Log"
	else:
		print("Invalid input. Either the instruction does not exist or function is not supported")

	print("The", opState, "of your number is:", result)

	userInput = input("Please enter a function and a value i.e. T 30 or t 45\n")
	inputIndex = userInput.split()	#very repetitive code but it does clear and reset the variables
	op = str(inputIndex[0])
	opState = ""
	result = 0.0
	value = float(inputIndex[1])

print("Goodbye!")