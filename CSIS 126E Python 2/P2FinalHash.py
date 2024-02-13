# Hash.py

'''
Name: John Barbonio
ID: 0518876
Date: 16 May 2020
Desc: P2 Final Project - Some Hashing
'''

import re
import collections

class Hash(object):
    def __init__(self):
        # const tablesize = 52 consts do not exist in Python
        self.processingList = collections.deque()

    def djbHash(self, data, tablesize):
        hashVal = 5381
        for c in data:
            hashVal *= 33
            hashVal += ord(c)

        hashVal %= tablesize
        return abs(hashVal)

    def loadFile(self):
        file_h = open("names.txt", "r+")

        i = 0

        line = file_h.readline()
        name = self.parseFile(line)
        self.processingList.append( ( name, self.djbHash(name, 53)) )

        while(len(line) > 0):
            line = file_h.readline()
            name = self.parseFile(line)
            self.processingList.append( ( name, self.djbHash(name, 53)) )
            i = i + 1

        file_h.close()
        
        self.fillHashList()

    def parseFile(self, file_contents):
        find_name = re.search("[A-Za-z]+", file_contents)
        fresult = find_name.group() if find_name else "FAIL"

        return fresult

    def fillHashList(self):
        self.hashList = collections.deque()
        
        tempstr = ""
        
        for a in range(0, 53):
            # the hash index is incremented by 1 for better readability
            self.hashList.append(str(a + 1) + ". ")

        for i in range(0, len(self.processingList)):
            self.hashList[self.processingList[i][1]] = self.hashList[self.processingList[i][1]] + self.processingList[i][0] + ", "
            # print(hashList[self.processingList[i][1]])

    def printList(self):
        for i in range(0, len(self.hashList)):
            print(self.hashList[i])