# John Barbonio
# Program Desc: This is a simple program to imitate a very basic calculator
# Creation Date: 09/10/21

.data
#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: This is a simple program to imitate a very basic calculator\n"
	myDate: .asciiz "Creation Date: 09/10/21\n"
	#------------------------------------------------------------------------------------------------

	strQuery: .asciiz "Please input two numbers:\n"
	strSum: .asciiz "\nThe Sum is: "
	strDifference: .asciiz "\nThe Difference is "
	strProduct: .asciiz "\nThe Product is "
	strQuotient: .asciiz "\nThe Quotient is "
	strRemainder: .asciiz "\nThe Remainder is "
	strSpace: .asciiz "\n"	# dedicated clrf as I don't like prefixing \\n in strings"

.text
main:
	# $a0 reserved for storing input and results, rapidly rewritten
	# v registers  receives and displaye input, rapidly rewritten

	la $a0, myName	# name string loaded to $a0
	li $v0, 4	# print content of $a0, 4 indicates string data type to print
	syscall		# call output
	
	la $a0, myDesc	# prog description loaded into $a0
	li $v0, 4	# print content of $a0, 4 indicates string data type to print
	syscall
	
	la $a0, myDate	# date program was created
	li $v0, 4	# load date string
	syscall
	
	la $a0, strSpace	# newline for formatting
	li $v0, 4		# load newline
	syscall
	
	la $a0, strQuery	# load prompt for user input string
	li $v0, 4		# load prompt string
	syscall
	li $v0, 5		# set $v0 to take a user int
	syscall			# call for user input for an int
	
	add $t0, $0, $v0	# moves first received input in $v0 to register $t1
	li $v0, 5		# set $v0 to take a user int again
	syscall			# call for user input for an int again
	add $t1, $0, $v0	# moves second received input in $v0 to $t1, the next available register storage
	
	la $a0, strSum		# print "The Sum is:" string
	li $v0, 4		# set v0 to receive an int
	syscall			# print string and sum to console
	
	add $a0, $t0, $t1	# move sum to dedicated memory register, away from working register (unnecessary for this program)
	li $v0, 1		# print content of %$a0 as int
	syscall			# print 
	
	la $a0, strDifference	# load subtraction string
	li $v0, 4		# load subtraction str to print to console
	syscall			
	
	sub $a0, $t0, $t1	# stores subtraction result in $a0 between $t0 and $t1
	li $v0, 1		# print content of %$a0 as int
	syscall
	
	la $a0, strProduct	# load product string
	li $v0, 4		# load $a0 data into $v0 to print to console
	syscall
	
	mult $t0, $t1		# multiply data of two registers
	mfhi $t2		# stores product of multiplication
	mflo $t3		# stores product of multiplication no. 2
	
	li $v0, 1		# print content of %$a0 as int
	add $a0, $t3, $0	# load product to $a0 register to print
	syscall
	
	la $a0, strQuotient	# load quotient result string
	li $v0, 4		# load string from $a0 register to be printed in console
	syscall
	
	div $t0, $t1		# divides data in $t0 by $t1
	
	mfhi $t0		# mfhi $t0 holds the remainder
	mflo $t1		# mflo $t1 hold the quotient
	
	li $v0, 1		# set $v0 to get int data type
	add $a0, $t1, $0	# get quotient from $a0
	syscall
	
	la $a0, strRemainder	# loads remainder string
	li $v0, 4		# load string from $a0
	syscall
	
	li $v0, 1		# print content of %$a0 as int
	add $a0, $t0, $0	# load into $a0 the remainder from $t0, itself from hi register
	syscall
	
	li $v0, 10		# CLOSE PROGRAM
	syscall			# CLOSE PROGRAM call
