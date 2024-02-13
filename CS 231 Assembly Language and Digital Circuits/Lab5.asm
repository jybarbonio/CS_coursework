.data
	#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: This is a simple program to find the sum of x amount of numbers divisible by six\n"
	myDate: .asciiz "Creation Date: 09/15/21\n"
	#------------------------------------------------------------------------------------------------
	strQuery: .asciiz "How many positive numbers that are divisible by 6 do you want to add?\n"
	strQuery2: .asciiz "Enter a number: "
	strCrlf: .asciiz "\n"
	strResult: .asciiz "The sum of the positive numbers between 1 and 100 that are divisible by 6 is: "
	strResult2: .asciiz " is divisible by "
	strFail0: .asciiz "==> ERROR: "
	strFail1: .asciiz " is not a positive number. Please enter another, positive number.\n"
	strFail2: .asciiz " is not in the range of 1 to 100. Please input another number within that parameter.\n"
	strFail3: .asciiz " is not divisible by 6. Please enter a number divisible by 6.\n"
.text
	la $a0, strQuery	# load prompt for user input string
	li $v0, 4		# load prompt string
	syscall
	
	li $v0, 5		# set $v0 to take a user int
	syscall			# call for user input for an int
	
	add $t0, $0, $v0	#t0 is user input and counter MAX
	li $t1, 0		# COUNTER int starting at 0
	li $t2, 0 		# SUM RESULT int, initialized $t2 as storage for added ints from loop
	# $t3 is used as temp storage for subsequent user inputs to be tested if they can be added as sum
	# $t4 will hold the modulus of user input % 6
	li $s1, 0		# this is the greater than zero filter for use in blt conditional below
	li $s2, 99		# filter numbers over 100 or over in blt conditional
	li $s3, 6		# number 6 used to modulus user inputs to verify they div by 6
	
# adds int if it meets the requirements as specified in the check strings and loops	
loopCheckMain:
	beq $t1, $t0, exit		# while ($t0 != $t1) { loop } else { pass }
	
	la $a0, strQuery2		# load prompt for user input string
	li $v0, 4			# load prompt string
	syscall

	li $v0, 5			# set $v0 to take a user int
	syscall				# call for user input for an int
	add $t3, $0, $v0		# moves user input, saves to $t3
	
	blt $t3, $s1, chkError1	# check if number is less than 1
	beq $t3, $s1, chkError2	# check if number is over 100
	bgt $t3, $s2, chkError2	# check if number is over 100
	
	div $t3, $s3		# to get modulus of user input modulus 6
	mfhi $t4			# getting $hi which contains remainder (modulus)
	
	bne $t4, 0, chkError3	# tests if $t4 (user input % 6) is zero, if not then branch to loopChkFail3 and repeat this main loop
	
	add $a0, $0, $t3
	li $v0, 1
	syscall
	
	la $a0, strResult2
	la $v0, 4
	syscall
	
	add $a0, $0, $s3
	li $v0, 1
	syscall
	
	la $a0, strCrlf		# crlf to indent "x is divisible by 6"
	la $v0, 4
	syscall
	
	add $t2, $t2, $t3	# else, finish the loop and increment by 1, adding the sum of the verified number to the total
	addi $t1, $t1, 1	# use of addi as is faster for this case, a 1 variable to add
				# 	$t1 is counter towards $t0, the amount of user input numbers to input 
	
	j loopCheckMain
	
# warns that the number was negative, the num cannot be negative to be added to sum
chkError1:
	la $a0, strFail0
	la $v0, 4
	syscall
	
	add $a0, $0, $t3
	li $v0, 1
	syscall
	
	la $a0, strFail1
	la $v0, 4
	syscall
	
	j loopCheckMain		# jump back to loopCheckMain start, and check bne conditional again
	
# warns that the number was not between 0 and 100 to be added to sum
chkError2:
	la $a0, strFail0
	la $v0, 4
	syscall
	
	add $a0, $0, $t3
	li $v0, 1
	syscall
	
	la $a0, strFail2
	la $v0, 4
	syscall
	
	j loopCheckMain		# jump back to loopCheckMain start, and check bne conditional again
	
# warns that the number is not divisible by 6 (user input % 6 != 0)	
chkError3:
	la $a0, strFail0
	la $v0, 4
	syscall

	add $a0, $0, $t3
	li $v0, 1
	syscall
	
	la $a0, strFail3	# print string number was not divisible by 6
	la $v0, 4
	syscall
	
	j loopCheckMain		# jump back to loopCheckMain start, and check bne conditional again
	
exit:
	la $a0, strResult	# load answer result string
	li $v0, 4		# print string to console
	syscall
	
	add $a0, $0, $t2	# move sum from $t2 to $a0 to be printed
	li $v0, 1		# set $a0 to print an int
	syscall

	li $v0, 10		# close program
	syscall
