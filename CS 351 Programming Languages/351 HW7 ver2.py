from tkinter import *
import re

class HW7GUI:
    def __init__(self, root):
        self.count = 0
        self.entrylines = 1.0
        self.entrylines2 = 1.0
        self.lsttokens = []
        self.strBNFline = ""
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
        self.entryboxParse = Text(self.master,width=80,height=20)
        self.entryboxParse.grid(row=1, column=2, sticky=W)
        
        self.submitbutton = Button (self.master, text="Next Line", command=self.bNextline)
        self.submitbutton.grid(row=3,column=0, sticky=E)
        self.clearbutton = Button (self.master, text="Clear", command = self.bclear)
        self.clearbutton.grid(row=3,column=1, sticky=E)
        self.quitbutton = Button (self.master, text="Quit", command=self.bQuit)
        self.quitbutton.grid(row=3,column=2, sticky=E)

    def bNextline(self):
        lines = self.entryboxI.get("1.0", END).splitlines()
        self.label4.config(text=("Current Processing Line: %s" %(self.count + 1)))

        if(self.count < len(lines)):
            self.lsttokens = self.tokenizer(lines[self.count])
            for t in self.lsttokens:
                self.entryboxO.insert(str(self.entrylines), "< " + t[0] + ", " + str(t[1]) + " >" + "\n" )
                self.entrylines += 1.0
            self.count += 1

            if(len(self.lsttokens) > 0):
                self.intoken = self.lsttokens.pop(0)
                if(self.intoken[1] == "if"):
                    # if expression case
                    self.if_exp()
                elif(self.intoken[1] == "print"):
                    self.print_exp()
                else:
                    self.exp()
            else:
                print("this line is empty")
                return
            print("\n----------------------------\n")
        else:
            # pass    # end of line, do nothing
            self.label4.config(text=("Current Processing Line: %s" %("-")))

    def bclear(self):
        self.entryboxO.delete(0.0, "end")
        self.entryboxParse.delete(0.0, "end")
        self.entrylines = 1.0

    def tokenizer(self, line):
        tline = """"""
        tline += str(line)

        regblank = re.compile('\s?\s+')
        regendline = re.compile('\;')
        regKey = re.compile('print|int|float|str|if|else')
        regID = re.compile('[A-Za-z]?[A-Za-z0-9]+')
        regOp = re.compile('\*|\/|\+|\-|\=|\:|\>|\<')
        # literal
        regLit = re.compile('\d+\.\d+|\d+')
        # sub regexes to
        regStr = re.compile('\".+\"|\'.+\'|“.+”')
        regSep = re.compile('\"|\'|\(|\)|“|”')

        lstLine = []

        # return if line is completely blankspace
        if(tline.isspace()):
            return

        while tline != "":
            # print("%s" %(tline))
            # removes/ignores spaces from line
            if tline[0].isspace():
                    t = regblank.search(tline)
                    tline = tline.replace(t.group(), "", 1)
                    # print("Match: %s" %(t.group()))
            # literals int/float
            elif tline[0].isdigit():
                if(regLit.search(tline)):
                    t = regLit.search(tline)

                    if(float(t.group()) % 1.0 == 0.0):
                        lstLine.append([ "int_literal", int(t.group()) ])
                    else:
                        lstLine.append([ "float_literal", float(t.group()) ])
                    tline = tline.replace(t.group(), "", 1)
                    # print("Match: %s" %(t.group()))
            # keyword/ids
            elif tline[0].isalpha():
                if(regKey.search(tline)):
                    t = regKey.search(tline)
                    lstLine.append([ "keyword", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    # print("Match: %s" %(t.group()))
                elif(regID.search(tline)):
                    t = regID.search(tline)
                    lstLine.append([ "id", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    # print("Match: %s" %(t.group()))
            # operand/strings
            else:
                if(regOp.search(tline[0])):
                    t = regOp.search(tline)
                    lstLine.append([ "operator", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    # print("Match: %s" %(t.group()))
                # handles strings/ quotation separators
                elif(regSep.search(tline[0])):
                    t = regSep.search(tline)
                    lstLine.append([ "sep", t.group() ])
                    if(t.group() == "\"" or t.group() == "\'" or t.group() == "“"):
                        t2 = regStr.search(tline)
                        s = t2.group()
                        s = s.replace("\"", "")
                        s = s.replace("\'", "")
                        s = s.replace("“", "")
                        s = s.replace("”", "")
                        lstLine.append([ "string_literal", s ])
                        tline = tline.replace(t2.group(), "", 1)
                        # print("Match: %s" %(t2.group()))
                        lstLine.append([ "sep", t.group() ])
                    else:
                        tline = tline.replace(t.group(), "", 1)
                        # print("Match: %s" %(t.group()))
                # ; endline condition
                elif(regendline.search(tline[0])):
                    t = regendline.search(tline)
                    lstLine.append([ "sep", t.group() ])
                    tline = tline.replace(t.group(), "", 1)
                    # print("Match: %s" %(t.group()))
                    
        return lstLine

    def accept_token(self):
        print("         accepted token from the list: %s" %(self.intoken[1]))
        self.entryboxParse.insert(str(self.entrylines2), ("         accepted token from the list: %s\n" %(self.intoken[1]))); self.entrylines2 += 1

        if(len(self.lsttokens) > 0):
            self.intoken = self.lsttokens.pop(0)
        else:
            return

    def multi(self):
        print("CHILD NODE multi(), child func of math")
        self.entryboxParse.insert(str(self.entrylines2), ("CHILD NODE multi(), child func of math\n")); self.entrylines2 += 1

        t_int = re.compile("\d+")
        t_float = re.compile("\d\.\d+")
        t_multi = re.compile("\*")
        if(self.intoken[0] == "float_literal"):    # is float
            print("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()
        elif(self.intoken[0] == "int_literal"):    # is int
            print("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()
        
        if(self.intoken[1] == "*"):
            print("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()
            self.multi()

    def math(self):
        print("CHILD NODE math()")
        self.entryboxParse.insert(str(self.entrylines2), ("CHILD NODE math()\n")); self.entrylines2 += 1

        if(self.intoken[0] == "int_literal" or "float_literal" or "string_literal"):
            self.multi()
        else:
            print("  error: math expects a literal")
            self.entryboxParse.insert(str(self.entrylines2), ("  error: math expects a literal\n")); self.entrylines2 += 1
            return

        if(self.intoken[1] == "+"):
            self.entryboxParse.insert(str(self.entrylines2), ("child node (internal) %s has token %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()
        self.multi()

        if(self.intoken[1] == ";"):
            print("parse tree building success!")
            self.entryboxParse.insert(str(self.entrylines2), ("parse tree building success!\n")); self.entrylines2 += 1
        else:
            print("there are unhandled elems in line, spaces, or ; not found")
            self.entryboxParse.insert(str(self.entrylines2), ("there are unhandled elems in line, spaces, or ; not found\n")); self.entrylines2 += 1

    # exp()
    def exp(self):
        # initialize, begin processing queue
        print("--parse tree building process--")
        print("PARENT NODE exp()")
        self.entryboxParse.insert(str(self.entrylines2), ("--------parse tree building process--------\n")); self.entrylines2 += 1
        self.entryboxParse.insert(str(self.entrylines2), ("PARENT NODE exp()\n")); self.entrylines2 += 1

        if(self.intoken[0] == "keyword"):
            self.entryboxParse.insert(str(self.entrylines2), ("child node (internal) %s has token %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            print("child node (internal) %s has token %s\n" %(self.intoken[0], self.intoken[1]))
            self.accept_token()
        # token type
        if(self.intoken[0] == "id"):
            self.entryboxParse.insert(str(self.entrylines2), ("child node (internal) %s has token %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            print("child node (internal) %s has token %s\n" %(self.intoken[0], self.intoken[1]))
            self.accept_token()
        else:
            self.entryboxParse.insert(str(self.entrylines2), "    identifier is always expected as first elem of expression!!\n"); self.entrylines2 += 1
            print("     identifier is always expected as first elem of expression!!\n")
            # return

        if(self.intoken[1] == "="):
            self.entryboxParse.insert(str(self.entrylines2), ("child node (internal) %s has token %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            print("child node (internal) %s has token %s\n" %(self.intoken[0], self.intoken[1]))
            self.accept_token()
        else:
            self.entryboxParse.insert(str(self.entrylines2), ("  expect = as second element of expression!\n")); self.entrylines2 += 1
            print("  expect = as second element of expression!")
            # return

        self.math()

    def if_exp(self):
        print("--parse tree building process--")
        print("PARENT NODE if_exp()")
        print("child node (internal): %s" %(self.intoken[0]))   # this if check was done in main/tokenizer
        print("  keyword has child node (token): %s" %(self.intoken[1]))
        self.entryboxParse.insert(str(self.entrylines2), ("--------parse tree building process--------\n")); self.entrylines2 += 1
        self.entryboxParse.insert(str(self.entrylines2), ("PARENT NODE if_exp()\n")); self.entrylines2 += 1
        self.entryboxParse.insert(str(self.entrylines2), ("child node (internal): %s\n" %(self.intoken[0]))); self.entrylines2 += 1
        self.entryboxParse.insert(str(self.entrylines2), ("  keyword has child node (token): %s\n" %(self.intoken[1]))); self.entrylines2 += 1
        
        self.accept_token()
        if(self.intoken[1] == "("):
            self.intoken = self.lsttokens.pop(0)    # left parenthesis seperator/ irrelevant to BNF
            print("child node (internal): comparison_exp()\n")
            self.entryboxParse.insert(str(self.entrylines2), ("child node (internal): comparison_exp()\n\n")); self.entrylines2 += 1
            self.comparison_exp()                   # get comparison tokens
            self.intoken = self.lsttokens.pop(0)     # right parathesis seperator/ irrelevant to BNF

        # close off if_exp() by handling colon end
        print("back to PARENT NODE if_exp()")
        self.entryboxParse.insert(str(self.entrylines2), ("back to PARENT NODE if_exp()")); self.entrylines2 += 1
        if(self.intoken[1] == ":"):
            print("child node (internal): %s" %(self.intoken[0]))
            print("  %s has child node (token): %s" %(self.intoken[0], self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("child node (internal): %s\n" %(self.intoken[0]))); self.entrylines2 += 1
            self.entryboxParse.insert(str(self.entrylines2), ("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1

            self.accept_token()     # accept colon seperator
            
        print("if statement parse tree success!")
        self.entryboxParse.insert(str(self.entrylines2), ("if statement parse tree success!\n")); self.entrylines2 += 1

    def comparison_exp(self):
        print("CHILD NODE comparison_exp()")
        self.entryboxParse.insert(str(self.entrylines2), ("CHILD NODE comparison_exp()\n")); self.entrylines2 += 1
        # first identifier
        if(self.intoken[0] == "id"):
            print("child node (token): %s" %(self.intoken[0]))
            print("  %s has child node (token): %s" %(self.intoken[0], self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("child node (token): %s\n" %(self.intoken[0]))); self.entrylines2 += 1
            self.entryboxParse.insert(str(self.entrylines2), ("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()
        # comparison operator, will need to adapt tokenizer for ==, <=, >=, !=
        if(self.intoken[0] == "operator" and self.intoken[1] == "<" or ">"):
            print("child node (token): %s" %(self.intoken[0]))
            print("  %s has child node (token): %s" %(self.intoken[0], self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("child node (token): %s\n" %(self.intoken[0]))); self.entrylines2 += 1
            self.entryboxParse.insert(str(self.entrylines2), ("  %s has child node (token): %s\n" %(self.intoken[0], self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()
        # second identifier
        if(self.intoken[0] == "id"):
            print("child node (token): %s" %("id"))
            print("  identifier has child node (token): %s" %(self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("child node (token): %s\n" %("id"))); self.entrylines2 += 1
            self.entryboxParse.insert(str(self.entrylines2), ("  identifier has child node (token): %s\n" %(self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()

    def print_exp(self):
        print("--parse tree building process--")
        print("PARENT NODE print_exp()")
        print("child node (internal): %s" %(self.intoken[0]))   # this if check was done in main/tokenizer
        print("  keyword has child node (token): %s" %(self.intoken[1]))
        self.entryboxParse.insert(str(self.entrylines2), ("--------parse tree building process--------\n")); self.entrylines2 += 1
        self.entryboxParse.insert(str(self.entrylines2), ("PARENT NODE print_exp()\n")); self.entrylines2 += 1
        self.entryboxParse.insert(str(self.entrylines2), ("child node (internal): %s\n" %(self.intoken[0]))); self.entrylines2 += 1
        self.entryboxParse.insert(str(self.entrylines2), ("  keyword has child node (token): %s\n" %(self.intoken[1]))); self.entrylines2 += 1

        self.accept_token()
        self.intoken = self.lsttokens.pop(0)    # skip the parenthesis sep
        if(self.intoken[1] == "\"" or "“"):
            print("child node (token): %s" %(self.intoken[0]))
            print("  sep has child node (token): %s" %(self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("child node (token): %s\n" %(self.intoken[0]))); self.entrylines2 += 1
            self.entryboxParse.insert(str(self.entrylines2), ("  sep has child node (token): %s\n" %(self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()
        if(self.intoken[0] == "string_literal"):
            print("child node (token): %s" %(self.intoken[0]))
            print("  string_literal has child node (token): %s" %(self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("child node (token): %s\n" %(self.intoken[0]))); self.entrylines2 += 1
            self.entryboxParse.insert(str(self.entrylines2), ("  string_literal has child node (token): %s\n" %(self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()
        if(self.intoken[1] == "\"" or "”"):
            print("child node (token): %s" %(self.intoken[0]))
            print("  sep has child node (token): %s" %(self.intoken[1]))
            self.entryboxParse.insert(str(self.entrylines2), ("child node (token): %s\n" %(self.intoken[0]))); self.entrylines2 += 1
            self.entryboxParse.insert(str(self.entrylines2), ("  string_literal has child node (token): %s\n" %(self.intoken[1]))); self.entrylines2 += 1
            self.accept_token()

        self.intoken = self.lsttokens.pop(0)    # skip closing parenthesis sep

        print("print statement tree building success!")
        self.entryboxParse.insert(str(self.entrylines2), ("print statement tree building success!\n")); self.entrylines2 += 1
    def bQuit(self):
        print("window closed")
        self.master.destroy()   # close window

if __name__ == '__main__':
    myTkRoot = Tk()

    my_gui = HW7GUI(myTkRoot)
    myTkRoot.mainloop()