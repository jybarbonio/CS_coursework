import re

def regFloat():
    strTemps = "The temperature is 72.5555555 and 32.98876 today."
    pattern = re.compile('\d+.\d+')
    search = pattern.search(strTemps)
   
    if(pattern.search(strTemps)):
        print("The first float number is %s. It starts at index %s ends at index %s" %(search.group(), search.start(), search.end()))
    else:
        print("No float number found!")

def regFloatfirst():
    strTemps = "66.6 The temperature is 72.55555 and 32.986 today."
    pattern = re.compile('\d+.\d+')
    search = pattern.search(strTemps)
   
    if(pattern.search(strTemps)):
        print("This string starts with a float number is %s. It starts at index %s ends at index %s" %(search.group(), search.start(), search.end()))
        print(search.group())
    else:
        print("This string does not start with a float.")

if __name__ == '__main__':
    # regFloat()
    regFloatfirst()