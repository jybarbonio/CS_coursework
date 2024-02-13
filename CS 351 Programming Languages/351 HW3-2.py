# John Barbonio
# Professor Jiang
# 11 February 2022
# CS 351-01
import re

def regFloat(lstStr):
    pattern = re.compile('\d+\.\d+')
    search = pattern.search(lstStr)
   
    if(pattern.search(lstStr)):
        print("The first float number is %sf. It starts at index %s ends at index %s" %(search.group(), search.start(), search.end()))
    else:
        print("No float number found!")

def regFloatfirst(lstStr):
    pattern = re.compile('^\d+.\d+')
    search = pattern.search(lstStr)
   
    if(pattern.search(lstStr)):
        print("This string starts with a float number is %s. It starts at index %s ends at index %s" %(search.group(), search.start(), search.end()))
        print(search.group())
    else:
        print("This string does not start with a float.")

def regexMatchList(lstStr, lstRegexArgs):
    
    for i in lstStr:
        for j in lstRegexArgs:
            pattern = re.compile(j)
            if(pattern.search(i)):
                print("regex %s matches string %s" %(i, j))
            else:
                print("regex %s doesn't match string %s" %(i, j))

def regexMatchCases(lstStr):
    cases = ['\d+\.\d+', '\d+\.\d\d', '\d+']
    for i in lstStr:
        for j in cases:
            pattern = re.compile(j)
            if(pattern.search(i)):     # 1 or more digists left and right of decimal
                print("%s matches the pattern: A float consists of 1 or more digits before and after decimal point." %(i))
            elif(pattern.search(i)):  # exactly two digits after decimal point
                print("%s matches the pattern: A float with exactly 2 digits afer the decimal point" %(i))
            elif(pattern.search(i)):
                print("%s is an integer" %(i))
            else:
                print("%s matches nothing" %(i))

def purgeStr(strExample):
    p = re.compile('\d+')
    search = p.search(strExample)

    if(p.search(strExample)):
        strExample = strExample.replace(search.group(), '')
        print("found integer %s at the beginning of this string, starting at index %s and ending at index %s. The rest is: %s" %(search.group(), search.start(), search.end(), strExample))

if __name__ == '__main__':
    print("********QUESTION 1********")
    lstStr = ["22.11","23","66.7f", "123abcde","Case44", "Happy","78", "66.7", "yes123", "Book111"]

    for i in lstStr:    # for element i index (i meaning the str elem itself) in lstStr, not an index integer
        regFloat(i)

    print("********QUESTION 2********")
    lstRegexArgs = [
      "\d\d\.\d\d"
    , "\d\d"
    , "\d\d\.f"
    , "[A-Za-z]+\d\d"
    , "[A-Z][a-z]+"
    , "\d\d"
    , "\d\d\.\d"
    , "\w\w\w\d\d\d"
    , "[A-Z]\w\w\w\d\d\d"
    ]
    print(lstRegexArgs)

    print("********QUESTION 3********")
    regexMatchCases(lstStr)

    print("********QUESTION 4********")
    strExample = "88 miles per hour!"    # remove that 7 from str
    purgeStr(strExample)