'''
Name: John Barbonio
ID: 0518876
Date: 09 February 2020
Desc: Assignment 8 The While loop
'''
import random

print("You start with 10 points and lose 2 for each wrong guess")
guess = int(input("Guess a number between 1 and 10: "))	#must be between 1 and 10

while(guess < 2 or guess > 9) :
	guess = int(input("Error, not in range of between 1 to 10. Please input a number within the proper range:\n"))

random.seed()
num = random.randint(2, 9)
score = 10
tries = 1

while(guess != num) :
	score -= 2
	print("Wrong! Minus 2 points, your score is now", score, ".Try again")
	guess = int(input("Guess another number between 1 and 10: "))
	while(guess < 2 or guess > 9) :
		guess = int(input("Error, not in range of between 1 to 10. Please input a number within the proper range:\n"))
	tries += 1

print("It took", tries, "to guess correctly. Your final score is", score, "points")