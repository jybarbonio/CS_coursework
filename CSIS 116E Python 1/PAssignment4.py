'''
Name: John Barbonio
ID: 0518876
Date: 26 January 2020
Desc: Assignment 4: Making Decisions
'''

# Mileage Calculator

mileage = int(input("Please clock in your mileage amount:\n"))
total = 0   #initializing int outside of conditional first

if(mileage <= 100):
    total = mileage * .25
else:
    total = ((mileage % 100) * .15) + 25

print("Your total earnings are ", "${:,.2f}".format(total)) #I guess converting the int 'total' is not necessary