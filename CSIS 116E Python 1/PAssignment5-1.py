'''
Name: John Barbonio
ID: 0518876
Date: 26 January 2020
Desc: Assignment 5: The Conditional Expression
'''

print("This program will determine whether a number is odd or even\n")
num1 = int(input("Enter a number: \n"))    #whole number needed
bState1 = ""   #intialized string variable before processing

if(num1 % 2 == 0): #if num_1 modulus zero has a remainder of zero, it is even, else it is odd
    bState1 = "EVEN"
else:
    bState1 = "ODD"

print("The number you entered is", bState1) # "conditional expression must assign a value of either "Odd" or "Even" to a var to be displayed"