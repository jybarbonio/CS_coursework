import os
import pathlib

dir_coursework = os.walk('C:/Users/itzdu/Desktop/CS coursework')
lst_extensions = ['.dwm', '.asm', '.cpp', '.h', '.py', '.java']
lst_todelete = []

def parsedirectory(dir_coursework):
    for subpath in dir_coursework:
        # keep walking into folders until non-directory is encountered
        print('Now in:', subpath[0])
    
        result = os.path.join(subpath[0]).replace("\\","/")

        # if it's a directory, do not assess suffix and walk further into path
        if (os.path.isdir(result)):
            print("yes is path", result)
        
        # if it is not a sub-directory, check if its a valid code file
        else:
            print("no is not path", result)

            if pathlib.Path(result).suffix not in lst_extensions:
                lst_todelete.append(result)

    for i in lst_todelete:
        print(i)

parsedirectory(dir_coursework)