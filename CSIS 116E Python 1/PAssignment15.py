'''
Name: John Barbonio
ID: 0518876
Date: 01 March 2020
Desc: Assignment 15 
'''
from tkinter import *

main = Tk()
main.title("Assignment 15")
main.geometry("400x300")
# main.config(bg = "#141439")

lblFirstName = Label(main, text = "John", fg = "blue", font = "georgia 40")

lblLastName = Label(main, text = "Barbonio", fg = "#993399", font = "georgia 40")

lblDate = Label(main, text = "Mar. 1, 2020", fg = "#ff0000", font = "cambria 30 italic bold")

lblFirstName.grid(row = 0, column = 0, sticky = W)	# sticky orients the text within its label to the left (W)
lblLastName.grid(row = 1, column = 0, sticky = W)
lblDate.grid(row = 2, column = 0, sticky= W)

main.mainloop()	# keeps window running, event loop