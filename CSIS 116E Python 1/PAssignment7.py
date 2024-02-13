'''
Name: John Barbonio
ID: 0518876
Date: 02 February 2020
Desc: Assignment 7: The For Loop
'''

userBalance = float(input("Please enter your balance\n"))
userInterestRate = float(input("Now enter your interest rate i.e. 2.7\n"))
userTimeframe = int(input("Enter how many years\n"))

for ch in range(0, userTimeframe) :
	calcInterest = userBalance * userInterestRate / 100.0	# Input, Process, Output, don't do the calculations in the print statement
	userBalance += calcInterest
	print("Year:", ch + 1, "${:,.2f}".format(userBalance))	# increment to make it more human readable