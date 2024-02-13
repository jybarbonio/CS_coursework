'''
Name: John Barbonio
ID: 0518876
Date: 01 March 2020
Desc: Assignment 16 Buttons and Events
'''
from tkinter import *
from tkinter import messagebox
import math

def calculate() :
	amt = float(entAmt.get())	# cast amt, interest rate, and time to float so the actual calculation is easier to read
	interestRate = (float(entInterestRate.get()) / 100) / 12	# initial interest rate must be divided by 100 and then by 12
	time = int(entTime.get())

	monthlyPay = (amt * interestRate) / (1 - (math.pow(1 / (1 + interestRate), time * 12)))
	payment = (monthlyPay * 12 * time)	# this took me an hour to find

	lblInterestResult.config(text = (str('${:,.2f}'.format(monthlyPay)))) # formatted to monetary look
	lblCostResult.config(text = (str('${:,.2f}'.format(payment))))


main = Tk()
main.title("Assignment 16")
main.geometry("400x300")

# variables/objects
lblAmt = Label(main, text = "Amount of Purchase:")
lblInterestRate = Label(main, text = "Interest Rate (like 7.5):")
lblTime = Label(main, text = "Years to Pay:")
lblMonthlyInterest = Label(main, text = "Monthly Interest:")
lblTotalCost = Label(main, text = "Total Purchase Cost:")
lblInterestResult = Label(main, text = "$")
lblCostResult = Label(main, text = "$")

entAmt = Entry(main, width = 24)
entInterestRate = Entry(main, width = 24)
entTime = Entry(main, width = 24)

btnCalculate = Button(main, text = "CALCULATE", width = 20, command = calculate)


# adding objects to console w/ properties
# column 0
lblAmt.grid(row = 0, column = 0, sticky = W, pady = 8)
lblInterestRate.grid(row = 1, column = 0, sticky = W, pady = 8)
lblTime.grid(row = 2, column = 0, sticky = W, pady = 8)
lblMonthlyInterest.grid(row = 3, column = 0, sticky = W, pady = 8)
lblTotalCost.grid(row = 4, column = 0, sticky = W, pady = 8)

# column 1
entAmt.grid(row = 0, column = 1, pady = 8)
entInterestRate.grid(row = 1, column = 1, pady = 8)
entTime.grid(row = 2, column = 1, pady = 8)
lblInterestResult.grid(row = 3, column = 1, sticky = W, pady = 8)
lblCostResult.grid(row = 4, column = 1, sticky = W, pady = 8)

# single button at bottom of grid
btnCalculate.grid(row = 5, column = 1, pady = 8)

main.mainloop()