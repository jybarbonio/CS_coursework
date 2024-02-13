from tkinter import *

class HW4GUI:
    def __init__(self, root):
        self.count = 0

        self.master = root
        self.master.title("Lexical Analyzer for TinyPie")

        self.label1 = Label(self.master, text="Source Code Input:")
        self.label1.grid(row=0,column=0,sticky=W)
        self.label2 = Label(self.master, text="Lexical Analyzed Result:")
        self.label2.grid(row=0,column=1,sticky=W)
        self.label3 = Label(self.master, text="Current Processing Line: %s" %("-"))
        self.label3.grid(row=2,column=0,sticky=W)

        self.entryboxI = Text(self.master,width=20,height=8)
        self.entryboxI.grid(row=1, column=0, sticky=W)
        self.entryboxO = Text(self.master,width=20,height=8)
        self.entryboxO.grid(row=1, column=1, sticky=W)
        
        self.submitbutton = Button (self.master, text="Next Line", command=self.bNextline)
        self.submitbutton.grid(row=3,column=0, sticky=E)
        self.submitbutton = Button (self.master, text="Quit", command=self.bQuit)
        self.submitbutton.grid(row=3,column=1, sticky=E)

    def bNextline (self):
        lines = self.entryboxI.get("1.0", END).splitlines()
        self.label3.config(text=("Current Processing Line: %s" %(self.count + 1)))

        if(self.count < len(lines)):
            self.entryboxO.insert(str((self.count + 1.0)), lines[self.count] + "\n")  # get line at current line read and place in output
            self.count += 1
        else:
            # pass    # end of line, do nothing
            self.label3.config(text=("Current Processing Line: %s" %("-")))

    def bQuit(self):
        print("window closed")
        self.master.destroy()   # close window

if __name__ == '__main__':
    myTkRoot = Tk()

    my_gui = HW4GUI(myTkRoot)
    myTkRoot.mainloop()

