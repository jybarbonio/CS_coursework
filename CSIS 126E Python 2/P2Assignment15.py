# P2Assignment15.py

'''
Name: John Barbonio
ID: 0518876
Date: 16 May 2020
Desc: P2 Assignment 15 Linked Lists
'''

from LinkedList import LinkedList

ll = LinkedList()

ll.addNode('a')
ll.addNode('b')
ll.addNode('c')
ll.addNode('d')
ll.addNode('e')

#delete 'c' from the list
ll.deleteNode('c')
ll.printList()
print('')
#insert 'c' back into the list
ll.insert('b', 'c')
ll.printList()