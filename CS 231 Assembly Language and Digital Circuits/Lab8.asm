.data
	#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: Fills an array and searches for and prints largest input in array"
	myDate: .asciiz "Creation Date: 09/29/21\n"
	#------------------------------------------------------------------------------------------------

	arr: .word 0,0,0,0,0,0,0,0,0,0	# 10 element array
	strPrompt1: .asciiz "How many elements: \n"
	strPrompt2: .asciiz "The largest element is: \n"
	strRangeError: .asciiz "ERROR: Range must be a positive number among range 1 to 10.\n"
.text

main:
	# $t0 is used for manipulated counter
	# $t1 holds array
	# $$t2 holds zero that holds largest elem of array

	la $a0, strPrompt1
	li $v0, 4
	syscall
	
	# call for user input
	li $v0, 5
	syscall
	
	# bounds for array size
	blt $v0, 1, errorBound	# go to param error if user input is not above 0
	bgt $v0, 10, errorBound	# go to param error if user input is over 10

	
	add $t0, $0, $v0	# save array to $t0 (constant)
	
	la $t1, arr
	add $a1, $0, $t0	# pass counter
	add $a2, $0, $t1	# pass array
	add $a3, $0, 0		# pass constant zero for decrement counter
	jal FindMax
	add $t4, $v1, $0	# get largest value obtained from FindMax
	
	la $a0, strPrompt2
	li $v0, 4
	syscall
	
	li $v0, 1
	add $a0, $v1, $0
	syscall
	
	j exit
errorBound:
	la $a0, strRangeError
	li $v0, 4
	syscall
	j main
	
FindMax:
	li $t4, 0	# holds largest number

	sub $sp, $sp, 4	# make space for return address to main func
	sw $ra, 0($sp) # save return address to main in sp register
	
	add $t0, $0, $a1	# pass counter to $t0
	add $t1, $0, $a2	# pass array to $t1
	add $t2, $0, $a3	# pass zero
	
	jal inLoop		# this will add link to $ra to return to FindMax later	
	add $t0, $0, $a1	# reinstate counter, giving it $a1 again
	la $t1, arr		# update array from global data
	jal parseArray		# ditto as above
	
	add $v1, $0, $t4	# return largest elem in array to main passing $v1
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra

	inLoop:
		li $v0, 4

		beq $t0, $0, ret
		li $v0, 5
		syscall
	
		sw $v0, 0($t1)
		addi $t0, $t0, -1	# decrement loop counter in $t0
		addi $t1, $t1, 4	# increment pointer by 4 bytes (size of each index)
		
		j inLoop
	parseArray:	
		beq $t0, $t2, ret
		lw $t3, 0($t1)		# move into $t1 what the pointer is pointing to in $s1
	
		addi $t1, $t1, 4	# increment pointer
		addi $t2, $t2, 1	# increment counter
		bgt $t3, $t4, isLarger
		
		j parseArray
	isLarger:
		add $t4, $0, $t3
		j parseArray
	ret:
		jr $ra
exit:
	li $v0, 10
	syscall
