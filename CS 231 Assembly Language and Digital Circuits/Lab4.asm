# John Barbonio
# Program Desc: This is a simple program add even numbers among a set of user input numbers
# Creation Date: 09/13/21

.data
	#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: This is a simple program add even numbers among a set of user input numbers\n"
	myDate: .asciiz "Creation Date: 09/13/21\n"
	#------------------------------------------------------------------------------------------------
	strQuery: .asciiz "How many numbers would you like to add together? "
	strResult: .asciiz "The sum of the even numbers is "
.text
	la $a0, strQuery	# load prompt for user input string
	li $v0, 4		# load prompt string
	syscall
	
	li $v0, 5		# set $v0 to take a user int
	syscall			# call for user input for an int
	
	add $t1, $0, $v0
	li $t0, 0		# COUNTER int starting at 0
	li $s0, 0 		# initialize $s0 as storage for added ints from loop
	li $s1, 2		# modulus for checking if user input is even
	
loopSum:
	bne $t0, $t1, exit	# while ($t0 != $t1) { loop } else { pass }
	addi $t0, $t0, 1	# use of addi as is faster for this case, a 1 variable to add

	li $v0, 5		# set $v0 to take a user int
	syscall			# call for user input for an int
	j loopIsEven
	
loopIsEven:
	div $v0, $s1		# user integer modulus 2
	mfhi $t2		# move remainder to $t2
	bne $t2, 0, loopSum
	

	add $s0, $s0, $v0	# add input int from $v0 to $s0
	li $v0, 1
	j loopSum		# jump back to loopSum start, and check beq conditional again

exit:
	la $a0, strResult	# load answer result string
	li $v0, 4		# print string to console
	syscall
	
	add $a0, $0, $s0	# move sum from $s0 to $a0 to be printed
	li $v0, 1		# set $a0 to print an int
	syscall

	li $v0, 10		# close program
	syscall
