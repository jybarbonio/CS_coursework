# GUI.PY

'''
Name: John Barbonio
ID: 0518876
Date: 07 March 2020
Desc: Assignment 19 Introduction to Classes
'''
from tkinter import *
from tkinter import messagebox

from Circle import Circle
from functools import partial


class GUI(object):
	def __init__(self):
		main = Tk()
		main.title("Assignment 19 GUI")
		main.geometry("640x380")
		main.config(bg = "#bfbfbf")
		main.resizable(width=False, height=False)

		circleCanvas = Canvas(main, width = 180, height = 160)	# utilize canvas for mock graphical depiction of circle
		circleCanvas.grid(row = 4, column = 0, sticky = SW, padx = 10)		# sticky it to the southeast quadrant of window

		def createCircle(xPos, yPos, radius, circle, x):
			clr = [ "green", "yellow", "blue" ]
			x0 = xPos - radius
			y0 = yPos - radius
			x1 = xPos + radius
			y1 = yPos + radius

			return circle.create_oval(x0, y0, x1, y1, fill = str(clr[x]))	# why is it create circle and not create oval?

		def calculate(x):
			c = Circle()
			r = float(grid[0][x].get())
			c.setRadius(float(r))

			grid[1][x].config(text = str("%.2f" % c.getCircumference()))
			grid[2][x].config(text = str("%.2f" % c.getArea()))
			grid[3][x].config(text = str("%.2f" % c.getDiameter()))
			print(c)
			circleCanvas.delete("all")	# clears circle canvas when calculate button is hit again
			createCircle(90, 80, r, circleCanvas, x - 1)


		grid = [ [ 0 for x in range(4) ] for y in range(4) ]
		btnCalc = [ "Calculate 1", "Calculate 2", "Calculate 3" ]
		lstProperties = [ "Radius:", "Circumference:", "Area:", "Diameter:" ]

		for x in range(0, 4):
			grid[x][0] = Label(main, font = ("Consolas", 16, "bold"), text = lstProperties[x], fg = "black", bg = "#bfbfbf")
			grid[x][0].grid(row = x, column = 0, sticky = W, padx = 8, pady = 8)

			# three entry boxes
			if(x != 0):
				grid[0][x] = Entry(main, width = 8, font = ("Consolas", 16), insertbackground = "black", fg = "black", bg = "#ffffff")
				grid[0][x].grid(row = 0, column = x, sticky = W, padx = 12, pady = 12)
			if(x < 3):
				# buttons
				btnCalc[x] = Button(main, font = ("Consolas", 14), width = 10, text = "Calculate", fg = "black", bg = "#bfbfbf", relief = RAISED, command = partial(calculate, x + 1))
				btnCalc[x].grid(row = 4, column = x + 1, sticky = N, pady = 20)
			for y in range(1, 4):

				if(x != 0):
					grid[x][y] = Label(main, font = ("Consolas", 16), text = "0.0",  fg = "#e60000", bg = "#bfbfbf")
					grid[x][y].grid(row = x, column = y, padx = 10, pady = 10, sticky = W)

		grid[0][1].focus_set()

		main.mainloop()

