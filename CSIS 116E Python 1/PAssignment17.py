'''
Name: John Barbonio
ID: 0518876
Date: 05 March 2020
Desc: Assignment 17 and 18 Tic Tac Toe
'''
from tkinter import *
from functools import partial

# will use buttons, labels, grid manager, and arrays

def resetGame():
    global numClicks
    global isXTurn
    global isDone

    for row in range(0, 3):
        for col in range(0, 3):
            grid[row][col].config(text = " ")

    numClicks = 0
    isXTurn = True
    isDone = False

    lblStatus.config(text = "X's Turn")

def markSpace(row, col):
    global numClicks
    global isXTurn
    global isDone

    if(isDone == True) :
        return

    # this line of code required using a partial, which we weren't shown
    space = grid[row][col].cget('text')

    if (space == " "):
        if(isXTurn == True):
            grid[row][col].config(text = "X", fg = "red")
            lblStatus.config(text = "O's Turn")
        else:
            grid[row][col].config(text = "O", fg = "blue")
            lblStatus.config(text = "X's Turn")
    else:
        lblStatus.config(text = "Invalid Move")
        return

    isXTurn = not isXTurn   # isXTurn != isXTurn does not work, so using not isXTurn instead
    print(isXTurn)
    numClicks += 1  # cries in numClicks++
    gameOver()  # I removed the (row, col) parameters because they aren't actually used

def gameOver() :    # the parameters for this game over function are never actually used
    global numClicks
    global isDone
    winner = " "

    if(grid[0][0].cget('text')  == grid[1][1].cget('text') and grid[1][1].cget('text') == grid[2][2].cget('text')) :
        winner = grid[0][0].cget('text')
    elif(grid[2][0].cget('text')  == grid[1][1].cget('text') and grid[1][1].cget('text') == grid[0][2].cget('text')) :
        winner = grid[1][1].cget('text')    # corrected, the Assignment example code was [2][4], not a proper diagonal 3 row check

    else :
        for r in range(0, 3) :
            if(grid[r][0].cget('text') != " " and grid[r][0].cget('text') == grid[r][1].cget('text') and grid[r][1].cget('text') == grid[r][2].cget('text')):
                winner = grid[r][0].cget('text')
            elif(grid[0][r].cget('text') != " " and grid[0][r].cget('text') == grid[1][r].cget('text') and grid[1][r].cget('text') == grid[2][r].cget('text')):
                winner = grid[0][r].cget('text')

    isDone = True
    if(winner == " " and numClicks >= 9) :
       lblStatus.config(text = "Tie Game")
    elif(winner != " ") :
        lblStatus.config(text = winner + " Wins!")
    else :
        lblStatus.config(text = "X's Turn" if isXTurn else "O's Turn")
        isDone = False

grid = [ [ 0 for i in range(3) ] for j in range(3) ]
numClicks = 0
isDone = False
isXTurn = True

root = Tk()
root.title("root")	# name
root.geometry("355x420")		# window size/dimensions

topFrame = Frame(root, width = 320, height = 40, bg = "yellow")	# yellow is #ffff00
topFrame.place(x = 12, y = 12)	# use place to add subframe
topFrame.pack_propagate(False)

mainFrame = Frame(root, width = 330, height = 330, bg = "black")
mainFrame.place(x = 10, y = 42)

lblStatus = Label(topFrame, text = "X's Turn", bg = "yellow", fg = "blue", font = ("Bookman Old Style", 20, "bold"))    # the font is a serif font according to wikipedia
lblStatus.pack(side = TOP)

for row in range(0, 3):
    for col in range(0, 3):
        # using higher order functions via partial so that I can access functions within functions
        grid[row][col] = Button(mainFrame, text = " ", relief = "solid", command = partial(markSpace, row, col))
        grid[row][col].config(font = "monospace 36 bold", fg = "red", height = 1,  width = 3)
        grid[row][col].place(x = row * 105 + 10, y = col * 105 + 10)

btnRestart = Button(root, text = "Restart", width = 30, command = resetGame)
btnRestart.place(x = 45, y = 380)

root.mainloop()	# keeps window running, event loop
