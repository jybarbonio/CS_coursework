'''
Name: John Barbonio
ID: 0518876
Date: 26 January 2020
Desc: Assignment 6: Decisions with if/elif
'''

calcInput = str(input("Please enter a basic calculator expression i.e. '2 * 5' with spaces:\n"))
inputExp = calcInput.split()     #splits the string to inputExp, denotes split with whitespace ' '

op = str(inputExp[1])   #the operation type is cast to str for data type consistency
opType = ""
ans = 0 #initializing before conditional

if(op == "+"):
    ans = float(inputExp[0]) + float(inputExp[2])   #this is more efficient than creating two new float variables to cast the lists to floats
    opType = "sum"
elif(op == "-"):
    ans = float(inputExp[0]) - float(inputExp[2])   #admittedly though, readability suffers
    opType = "difference"
elif(op == "*"):
    ans = float(inputExp[0]) * float(inputExp[2])
    opType = "product"
elif (op == "/"):
    opType = "quotient"

    if(float(inputExp[2]) == 0): #this checks if the denominator is zero, why doesn't this conditional work when inside the above +elif?
        ans = None  #is this ok or no
    else:
        ans = float(inputExp[0]) / float(inputExp[2])
else:
    print("Error, either you are trying to divide a zero or the operator/numbers are invalid inputs")

print("The", opType, "is", ans)