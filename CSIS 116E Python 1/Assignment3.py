'''
Name: John Barbonio
ID: 0518876
Date: 17 January 2020
Desc: Assignment 3
'''
dog_age = float(input('Enter your dog\'s age in human years: '))

if(dog_age > 2) :
    dog_age = 21 + (2 * dog_age)
elif(dog_age <= 2) :
    dog_age *= 10.5

print('Your dog is actually', str(dog_age), 'in dog years')