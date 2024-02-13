'''
Name: John Barbonio
ID: 0518876
Date: 09 February 2020
Desc: Assignment 10 Functions
'''
def C2F(C) :	#celsius to fahrenheit
	return float(C * 9 / 5) + 32.0
def K2F(K) :	#kevin to fahrenheit
	return float(1.8 * (K - 273.15) + 32.0)	#is his kelvin calculation wrong because I am pulling the actual formula here!!
def N2F(N) :	#newtons to fahrenheit
	return float(N * 5.4545) + 32.0

print("This is a to fahrenheit temperature calculator.\nIt can convert\nC - Celsius\nK - Kelvin\nN - Newton\nX - Exit\n")
print("Please enter a value like so: 36 c, or 32 k")

userInput = str(input("Please enter the temperature to be converted and its type:\n")) #Stevenson really worded this assignment in a confusing way rip
inputIndex = userInput.split()
value = float(inputIndex[0])
print(value)
op = inputIndex[1]
opType = ""
result = 0

while(op != "X" or op != "x") :
	if(inputIndex[1] == "C" or inputIndex[1] == "c") :
		result = C2F(value)
	elif(inputIndex[1] == "K" or inputIndex[1] == "k") :
		result = K2F(value)
	elif(inputIndex[1] == "N" or inputIndex[1] == "n") :
		result = N2f(value)
	else:
		print("Invalid input! Please run the program again and enter valid inputs and functions")

	print(value, op, "is", result, "in fahrenheit")

	userInput = str(input("Please enter the temperature to be converted and its type:\n")) #Stevenson really worded this assignment in a confusing way rip
	inputIndex = userInput.split()
	value = float(inputIndex[0])
	op = inputIndex[1]
	opType = ""
	result = 0