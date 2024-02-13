# P2Assignment14.py

'''
Name: John Barbonio
ID: 0518876
Date: 10 May 2020
Desc: P2 Assignment 14 Collections
'''

from Random import Random

rnd = Random()

# seed is first parameter, min and max second and third respectively
rnd.__init__(0, 0, 50)
rnd.setRange(1, 100)

for i in range(0, 168):
	test = rnd.nextInt()
	#test = rnd.nextFloat()
	#test = rnd.nextFraction()

	print(test, "| Size:", len(rnd.randomDeck))


rnd.setDequeMinSize(900)
print(len(rnd.randomDeck))
