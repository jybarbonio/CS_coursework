# GUI.PY

'''
Name: John Barbonio
ID: 0518876
Date: 19 March 2020
Desc: P2 Assignment 2 TKinter Review
'''
from tkinter import *

from Lab2 import Lab2

class GUI(object):
	def __init__(self):
		main = Tk()
		main.title("Assignment 2 TKinter Review")
		main.geometry("600x300")
		main.resizable(width=False, height=False)

		def computeNumber():
			l = Lab2()
			grid[1][1].config(text = l.sumNums(int(grid[0][1].get())))	# there must be a better way like intVar?
			grid[2][1].config(text = l.reverseNums(int(grid[0][1].get())))

			tempList = l.getList(int(grid[0][1].get()))

			for c in range(1, 4): # alternatively could use len(tempList) + 1 but the system is for 3 digit numbers specifically
				grid[3][c].config(text = tempList[c - 1])

		def textColor():
			for r in range(0, 6):
						for c in range(0, 6):
							# Number Labels Vertical (column 1)
							if(r > 0 and r < 4):
								grid[r][1].config(fg = s.get())
							# Number Labels Horizontal (columns 2 and 3)
							if(c > 1 and c < 4):
								if(c == 2):
									grid[3][c].config(fg = s.get())
								if(c == 3):
									grid[3][c].config(fg = s.get())

		s = StringVar() # mutual exclusion
		s.set("Red")	# initialization. default is red
		grid = [ [ 0 for r in range(6) ] for c in range(6) ]

		lstLabels = [ "Enter a 3-digit number", "Sum:", "Reverse:", "Array:" ]
		lstRclrs = [ "Red", "Green", "Blue" ]

		# I believe the font in the Assignment example is sans serif?
		for r in range(0, 6):
			# Description Labels
			if(r < 4):
				grid[r][0] = Label(main, font = ("Sans Serif", 10, "bold"), text = lstLabels[r], fg = "black")
				grid[r][0].grid(row = r, column = 0, sticky = W, padx = (0, 10), pady = 10)
			for c in range(0, 6):
				# Number Labels Vertical (column 1)
				if(r > 0 and r < 4):
					'''stylistically I would've preferred black as a default start color since the user doesn't
					choose the color from the start, but the radio buttons need one button filled as a start so red it is '''
					grid[r][1] = Label(main, font = ("MS Sans Serif", 10, "bold"), text = "0", fg = "red")
					grid[r][1].grid(row = r, column = 1, sticky = S, pady = 10)
				# Number Labels Horizontal (columns 2 and 3)
				if(c > 1 and c < 4):
					grid[3][c] = Label(main, font = ("Sans Serif", 10, "bold"), text = "0", fg = "red")
					
					if(c == 2):
						grid[3][c].grid(row = 3, column = c, sticky = W, padx = (20, 0), pady = 10)
					if(c == 3):
						grid[3][c].grid(row = 3, column = c, sticky = W, padx = 0, pady = 10)

				# Radio buttons
				if(r == 4 and c < 3):

					grid[4][c] = Radiobutton(main, font = ("Sans Serif", 10, "bold"), text = lstRclrs[c], fg = "black", variable = s, value = lstRclrs[c], command = textColor)

					if(c == 0):
						grid[4][c].grid(row = 4, column = c, sticky = S, padx = 0, pady = 10)
						grid[4][c].select()	# extra precaution for mutual exclusion
					if(c == 1):
						grid[4][c].grid(row = 4, column = c, sticky = S, padx = 0, pady = 10)
						grid[4][c].deselect()
					if(c == 2):
						grid[4][c].grid(row = 4, column = c, sticky = S, padx = (40, 0), pady = 10)
						grid[4][c].deselect()

		# Entry
		grid[0][1] = Entry(main, width = 8, font = ("Sans Serif", 10), fg = "black")
		grid[0][1].grid(row = 0, column = 1, sticky = W, padx = 10, pady = 10)
		grid[0][1].focus_set()
		# Button
		grid[5][1] = Button(main, font = ("Sans Serif", 10), text = "Compute", fg = "black", command = computeNumber)
		grid[5][1].grid(row = 5, column = 1, sticky = W, padx = 10, pady = 10)

		main.mainloop()