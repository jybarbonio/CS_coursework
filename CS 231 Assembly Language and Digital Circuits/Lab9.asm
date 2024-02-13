.data
	#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: Converts base 10 integers (decimal) to binary (base 2)"
	myDate: .asciiz "Creation Date: 10/3/21\n"
	#------------------------------------------------------------------------------------------------

	strPrompt: .asciiz "Input a number in decimal form: "
	strLine: .asciiz "===========================================\n"
	strResult1: .asciiz "The number "
	strResult2: .asciiz " in binary is: "
.text
	# a1 and above is for passing from main to funcs
	# t0 holds user input to be deconstructed to binary
	# t1 hold 2 divider
	# t2 holds remainder
	# t3 holds quotient
	# t4 holds count for pointer increment back to end of stack

main:
	# la $a0, strLine		# println boundary
	# la $v0, 4
	# syscall

	la $a0, strPrompt	# prompt for user input
	la $v0, 4
	syscall
	
	li $v0, 5		# call for user input
	syscall
	
	# la $a0, strLine		# println boundary
	# la $v0, 4
	# syscall

	add $a1, $0, $v0	# pass user input int to $a1
	jal BaseChange

	li $v0, 10		# close program cleanly
	syscall

BaseChange:
	add $t0, $0, $a1	# pass user input from $a1 to $t0
	add $t1, $0, 2		# divide by 2
	addi $t4, $0, 32	# initialize counter as 32
	
	la $a0, strResult1	# "The number..."
	la $v0, 4
	syscall
	
	add $a0, $0, $a1
	li $v0, 1
	syscall
	
	la $a0, strResult2	# "...in binary is:"
	la $v0, 4
	syscall

	j pushBase		# basic jump to base 2, as $ra jal return address is not changed
	
	# divide until quotient is zero, puts 0 or 1 remainders into stack
	pushBase:
		beq $t4, $0, popBase
		div $t0, $t1
	
		mfhi $t2		# holds remainder result of division (0 or 1)
		mflo $t3		# holds quotient result of division
		
		addi $sp, $sp, -4	# make space in stack
		sw $t2, 0($sp)		# save result to stack
		add $t0, $0, $t3	# replace number with quotient
		addi $t4, $t4, -1	# counter for stack elements to empty, counts amound of times pushBase2 func loops
		j pushBase		# repeat until quotient ($t0) is zero
	
	# display result to user (is already oriented properly as stack pointer works backwards from end of binary loading)
	popBase:
		beq $t4, 32, ret	# while $t4 is greater than $t4, continue pulling elements from stack
		
		lw $a0, 0($sp)		# load into print register an element
		li $v0, 1		# print number
		syscall			# call to print
		
		addi $sp, $sp, 4	# increment pointer back towards back/top (to empty)
		addi $t4, $t4, 1	# increment up stack, reading backwards (or starting from front to rear), 32 positions
		
		j popBase
	ret:
		jr $ra			# return to main
		
