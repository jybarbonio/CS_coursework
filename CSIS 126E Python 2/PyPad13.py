# PyPad.py

'''
Name: John Barbonio
ID: 0518876
Date: 8 May 2020
Desc: P2 Assignment 13 Regular Expressions
'''


import sys
import os # ostream
import re

from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtGui import QFont
from PyQt5.QtCore import *

class PyPad(QMainWindow):
	resized = pyqtSignal()

	def __init__(self, parent = None):
		self.app = QApplication(sys.argv)
		super(PyPad, self).__init__(parent)
		self.resized.connect(self.sizeEvent)

		self.fname = "Untitled"
		self.path = ""
		self.currentlyOpenFile = ""
		# was the window res (525 x 325) in the assignment page incorrect to the image? I overlayed this with it via Paint and these dimensions match up
		self.resize(600, 900)
		self.setWindowTitle("PyPad - Untitled")

		self.createMenu()
		self.textArea()
		self.status()

		self.show()
		sys.exit(self.app.exec_())

	def textArea(self):
		self.textArea = QPlainTextEdit(self)
		fnttextArea = QFont("consolas", 14)
		self.textArea.setFont(fnttextArea)
		self.textArea.setFixedWidth(523)
		self.textArea.setFixedHeight(335)
		self.textArea.move(1, 21)

	def status(self):
		self.status = QStatusBar(self)
		self.status.showMessage("Ready")
		self.status.move(1, 350)	# may have problems

		# initial properties of status bar dimensions/positions, changed when resize event occurs
		self.status.setFixedWidth(200)
		self.status.setFixedHeight(self.status.geometry().height())

	def createMenu(self):
		self.bar = self.menuBar()
		file = self.bar.addMenu("File")

		fNew = QAction("New", self)
		fOpen = QAction("Open", self)
		fSave = QAction("Save", self)
		fSaveAs = QAction("Save As", self)
		fQuit = QAction("Quit", self)
		sep = QAction(file)

		sep.setSeparator(True)
		sep.triggered.connect(self.newFile)

		fNew.triggered.connect(self.newFile)
		fOpen.triggered.connect(self.openFile)
		fSave.triggered.connect(self.saveFile)
		fSaveAs.triggered.connect(self.saveFileAs)
		fQuit.triggered.connect(self.close)

		fNew.setShortcut("Ctrl+N")
		fOpen.setShortcut("Ctrl+O")
		fSave.setShortcut("Ctrl+S")
		fSaveAs.setShortcut("Ctrl+A")
		# fQuit.setShortcut("Ctrl+Q")

		file.addAction(fNew)
		file.addAction(fOpen)
		file.addAction(fSave)
		file.addAction(fSaveAs)
		file.addAction(sep)
		file.addAction(fQuit)

	def resizeEvent(self, event):
		self.resized.emit()
		return super(PyPad, self).resizeEvent(event)

	def sizeEvent(self):

		self.textArea.setFixedWidth(self.geometry().width() - 2)
		self.textArea.setFixedHeight(self.geometry().height() - 40)

		# Absolute positioning of status, starts in Quadrant 1 of imaginary pixel graph chart (top right for some unholy reason)
		self.status.move(self.geometry().width() - self.geometry().width(), self.geometry().height() - 25)

	def newFile(self):
		self.fname = "Untitled"
		self.setWindowTitle("PyPad - " + self.fname)
		self.path = ""
		self.textArea.clear()
		self.textArea.setFocus()

	def openFile(self):
		# fName, filter = QFileDialog.getOpenFileName(self, "Open File", os.getcwd(), "PyPad Files (*.ppad)") # local variable fName, not fname yikes
		fPath, filter = QFileDialog.getOpenFileName(self, 'Open File', os.getcwd(), "HTML Files (*.html)")
		self.path = fPath

		if(self.path):
			self.readFile()
		else:
			self.status.showMessage(self.fname)
			self.textArea.setFocus()
			self.path = self.currentlyOpenFile


	def saveFile(self):
		if(os.path.exists(self.path)):
			self.writeFile()
		# if(self.fname == "Untitled"):
		else:
			self.saveFileAs()

	def saveFileAs(self):
		self.path, filter = QFileDialog.getSaveFileName(self, "Save File", os.getcwd(), "PyPad Files (*.ppad)")
		if(self.path):
			self.writeFile()
		else:
			self.status.showMessage(self.fname)
			self.textArea.setFocus()
			self.path = self.currentlyOpenFile

	def writeFile(self):
		outfile = open(self.path, "w")
		taContents = self.textArea.toPlainText()

		for i in range(len(taContents)):
			# "val = chr(ord(ch) + 128)"
			# chr returns a unicode (string) representation of specified integer number
			# ord is the inverse, returns integer of a unicode character
			# therefore, below is turning char into an int, adding 128 as "encrypting", then returning and saving it as a char again
			outfile.write(taContents[i])

		self.status.showMessage("File Written Successfully")
		self.setWindowTitle("PyPad -" + self.fnameFromPath(self.path))

		self.currentlyOpenFile = self.path
		outfile.close()

	def readFile(self):
		if(self.fname == "Untitled"):
			self.textArea.clear()
			self.textArea.setFocus()

			infile = open(self.path, "r+")
			# self.textArea.insertPlainText(infile.read())

			entire = ""

			# first line
			s = ""
			s = infile.readline()
			entire = entire + self.regEx(s)

			while(len(s) > 0):	
				s = infile.readline()
				entire = entire + self.regEx(s)

			# scanning the resulting dictionary words for palindromes
			palindromes = re.findall(".+ \- PALINDROME", entire)
			# space between dictionary words and palindromes
			entire = "\n" + entire

			for i in range(len(palindromes), 0, -1):
				entire = palindromes[i - 1] + "\n" + entire

			infile.close()
			self.textArea.setPlainText(entire)
			self.status.showMessage("File Read Successfully")
			# print(self.path)
			self.setWindowTitle("PyPad - " + self.fnameFromPath(self.path))

			self.currentlyOpenFile = self.path

	# gets dictionary words from the files
	def regEx(self, s):

		# No special RegEx needed other than the two anchor parameters
		find = re.search("<B>.+<\/B>", s)
		# handles the None return
		narrow1 = find.group() if find else ""
		# clears anchors
		narrow2 = re.sub("<B>", "", narrow1)
		word = re.sub("</B>", "", narrow2)

		if find:
			# word lower is the parameter 
			result = re.search(self.rgArgument(word), word.lower())

			if result and len(word) > 1:
				return word + " - PALINDROME\n"
			else:
				return word + "\n"
		else:
			return ""

	# creates an argument that return a regex format for the word to be tested
	def rgArgument(self, w):
		reg = ""

		if(len(w) % 2 == 1 and len(w) > 1):
			for i in range(0, int(len(w)/2)):
				reg = reg + "(.)"

			reg = reg + "."

			for i in range(int(len(w) / 2), 0, -1):
				reg = reg + "\\" + str(i)

		elif(len(w) % 2 == 0 and len(w) > 1):
			for i in range(0, int(len(w)/2)):
				reg = reg + "(.)"

			for i in range(int(len(w) / 2), 0, -1):
				reg = reg + "\\" + str(i)

		return reg

	def getNextChar(self, f):
		c = f.read(1)
		while c:
			yield c
			c = f.read(1)

	def fnameFromPath(self, path): # this doesnt really need any arguments, could just return name from path member
		tempList = []
		tempList = path.split("/")
		return tempList[len(tempList) - 1]