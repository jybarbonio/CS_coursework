from tkinter import *
import re

class HW7GUI:
    def __init__(self, root):
        self.count = 0
        self.entrylines = 1.0
        self.lsttokens = []
        self.intoken = [ "", "" ]

        self.master = root
        self.master.title("Lexical Analyzer for TinyPie")

        self.label1 = Label(self.master, text="Source Code Input:")
        self.label1.grid(row=0,column=0,sticky=W)
        self.label2 = Label(self.master, text="Lexical Analyzed Result:")
        self.label2.grid(row=0,column=1,sticky=W)
        self.label3 = Label(self.master, text="Parse Tree:")
        self.label3.grid(row=0,column=2,sticky=W)
        self.label4 = Label(self.master, text="Current Processing Line: %s" %("-"))
        self.label4.grid(row=2,column=0,sticky=W)

        self.entryboxI = Text(self.master,width=50,height=20)
        self.entryboxI.grid(row=1, column=0, sticky=W)
        self.entryboxO = Text(self.master,width=50,height=20)
        self.entryboxO.grid(row=1, column=1, sticky=W)
        self.entryboxParse = Text(self.master,width=50,height=20)
        self.entryboxParse.grid(row=1, column=2, sticky=W)
        
        self.submitbutton = Button (self.master, text="Next Line", command=self.bNextline)
        self.submitbutton.grid(row=3,column=0, sticky=E)
        self.quitbutton = Button (self.master, text="Quit", command=self.bQuit)
        self.quitbutton.grid(row=3,column=2, sticky=E)

    def bNextline(self):
        lines = self.entryboxI.get("1.0", END).splitlines()
        self.label4.config(text=("Current Processing Line: %s" %(self.count + 1)))

        if(self.count < len(lines)):
            self.lsttokens = self.tokenizer(lines[self.count])
            for t in self.lsttokens:
                self.entryboxO.insert(str(self.entrylines), "< " + str(t[0] + ", " + str(t[1] + " >" + "\n" )))
                self.entrylines += 1.0
            self.count += 1
            self.exp()
            print("\n-------------------------------------------------------------\n")
        else:
            # pass    # end of line, do nothing
            self.label4.config(text=("Current Processing Line: %s" %("-")))

    def tokenizer(self, line):
        tline = """"""
        tline += str(line)
        # tline = tline.replace(" ", "")
        print(tline)
        regblank = re.compile('\s?\s+')
        regendline = re.compile('\;')
        regKey = re.compile('print|int|float|str|if|else')
        regID = re.compile('[A-Za-z]?[A-Za-z0-9]+')
        regOp = re.compile('\*|\/|\+|\-|\=|\:|\>|\<')
        
        # literals
        regLit_int = re.compile('\d+')
        regLit_fl = re.compile('\d+\.\d+')
        # sub regexes
        regStr = re.compile('\".+\"|\'.+\'|')
        
        regSep = re.compile('\"|\'|\(|\)')

        lstLine = []

        while tline != "":
            print("%s" %(tline))
            # removes/ignores spaces from line
            if tline[0].isspace():
                    t = regblank.search(tline)
                    tline = tline.replace(t.group(), "", 1)
                    print("Match: %s" %(t.group()))
            # literals int/float
            elif tline[0].isdigit():
                if(regLit_fl.search(tline)):
                    t = regLit_fl.search(tline)
                    lstLine.append([ "float_literal", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    print("Match: %s" %(t.group()))
                elif(regLit_int.search(tline)):
                    t = regLit_int.search(tline)
                    lstLine.append([ "int_literal", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    print("Match: %s" %(t.group()))
            # keyword/ids
            elif tline[0].isalpha():
                if(regKey.search(tline)):
                    t = regKey.search(tline)
                    lstLine.append([ "keyword", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    print("Match: %s" %(t.group()))
                elif(regID.search(tline)):
                    t = regID.search(tline)
                    lstLine.append([ "id", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    print("Match: %s" %(t.group()))
            # operand/strings
            else:
                if(regOp.search(tline[0])):
                    t = regOp.search(tline)
                    lstLine.append([ "operand", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    print("Match: %s" %(t.group()))
                # handles strings/ quotation separators
                elif(regSep.search(tline[0])):
                    t = regSep.search(tline)
                    lstLine.append([ "sep", t.group() ])
                    if(t.group() == "\"" or t.group() == "\'"):
                        t2 = regStr.search(tline)
                        s = t2.group()
                        s = s.replace("\"", "")
                        s = s.replace("\'", "")

                        lstLine.append([ "string_literal", s ])
                        tline = tline.replace(t2.group(), "", 1)
                        print("Match: %s" %(t2.group()))
                        lstLine.append([ "sep", t.group() ])
                    else:
                        tline = tline.replace(t.group(), "", 1)
                        print("Match: %s" %(t.group()))
                # ; endline condition
                elif(regendline.search(tline[0])):
                    t = regendline.search(tline)
                    lstLine.append([ "sep", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    print("Match: %s" %(t.group()))
            
        return lstLine

    def accept_token(self):
        print("     accepted token from the list: " + self.intoken[1])

        if(len(self.lsttokens) != 0):
            self.intoken = self.lsttokens.pop(0)
        else:
            return

    def multi(self):
        t_int = re.compile("\d+")
        t_float = re.compile("\d\.\d+")
        t_multi = re.compile("\*")
        if(t_float.search(self.intoken[1])):    # is float
            self.accept_token()
        elif(t_int.search(self.intoken[1])):    # is int
            self.accept_token()
        
            if(t_multi.search(self.intoken[1])):
                self.accept_token()
                self.multi()

    def math(self):
        if(self.intoken[0] == "int_literal" or "float_literal" or "string_literal"):
            self.multi()
        else:
            print("error: math expects a literal")
            return

        if(self.intoken[1] == "+"):
            print("child node (token): " + self.intoken[1])
            self.accept_token()
            print("internal child node: math")
        self.multi()

        if(self.intoken[1] == ";"):
            print("parse tree building success!")
        else:
            print(self.intoken[0] + " " + self.intoken[1])
            print("there are unhandled elems in line, spaces, or ; not found")

    # exp()
    def exp(self):
        # initialize, begin processing queue
        if(len(self.lsttokens) > 0):
            self.intoken = self.lsttokens.pop(0)
        else:
            return

        print("parse tree building process")

        if(self.intoken[0] == "keyword"):
            print("keyword identified: " + self.intoken[1])
            self.accept_token()
        # token type
        if(self.intoken[0] == "id"):
            print("child node (internal): identifier")
            print("     identifier has child node (token): " + self.intoken[0])
            self.accept_token()
        else:
            print("identifier is always expected as first elem of expression!!")
            # return

        if(self.intoken[1] == "="):
            print("child node (token): " + self.intoken[1])
            self.accept_token()
        else:
            print("expect = as second element of expression!")
            # return

        print("Child node (internal): math")
        self.math()

    def bQuit(self):
        print("window closed")
        self.master.destroy()   # close window

if __name__ == '__main__':
    myTkRoot = Tk()

    my_gui = HW7GUI(myTkRoot)
    myTkRoot.mainloop()

