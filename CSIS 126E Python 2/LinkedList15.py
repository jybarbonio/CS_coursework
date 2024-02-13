# LinkedList.py

'''
Name: John Barbonio
ID: 0518876
Date: 16 May 2020
Desc: P2 Assignment 15 Linked Lists
'''

class Node(object):
	def __init__(self, data, next = None):
		self.data = data
		self.next = next

class LinkedList(object):
	def __init__(self):
		self.Head = None	# front/head of the list?, head is None type

	def insert(self, position, data):
		node = self.Head
		while(node.next.data != position):
			node = node.next

		new_node = Node(data)
		new_node.next = node.next
		node.next = new_node

	def addNode(self, data):

		if(self.Head == None):
			self.Head = Node(data)
			self.Head.next = None
		else:
			node = self.Head
			while(node.next != None):
				node = node.next

			n = Node(data)
			n.next = None            
			node.next = n    

	# handles two jobs, deletes node and of course accompanying data with it
	def deleteNode(self, search):
		node = self.Head
		while(node.next.data != search):	# while loop pauses at point previous the node with the data to be removed
			node = node.next

		delRef = node.next
		node.next = node.next.next
		delRef = None

	def printList(self):
		node = self.Head
		while(node != None):
			print(node.data)
			node = node.next