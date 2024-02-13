# CardException.py

'''
Name: John Barbonio
ID: 0518876
Date: 26 April 2020
Desc: P2 Assignment 10 Exceptions
'''

class CardException(Exception):
	def __init__(self, msg):	# msg is the error message
		super(CardException, self).__init__(msg)
		self.msg = "Card loading or creation error at: \"" + msg + "\""

	def __str__(self):
		return repr(self.msg)
