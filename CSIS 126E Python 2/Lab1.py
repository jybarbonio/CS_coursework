# LAB1.PY

'''
Name: John Barbonio
ID: 0518876
Date: 19 March 2020
Desc: P2 Assignment 1 A Simple Class
'''

class Lab1(object):
# init not needed as there aren't any variables to keep/initialize within it
	def sumNums(self, n):
		sum = 0
		while (n > 0):
			sum += n % 10
			n //= 10 # // is strict integer only division
		return sum

	def reverseNums(self, n):
		reverse = ""
		while (n > 0):
			reverse += str(n % 10)	# concatenates digits, reverse could alternatively use list type with reverse.append
			n //= 10
		return int(reverse)

	def getList(self, n):
		numList = []
		while (n > 0):
			numList.append(n % 10)
			n //= 10
		numList.reverse()	# if the num is 123, it will print 1 2 3 instead of 3 2 1.
		return numList
