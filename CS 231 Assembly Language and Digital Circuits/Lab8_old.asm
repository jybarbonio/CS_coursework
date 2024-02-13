.data
	#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: Fills an array and searches for and prints largest input in array"
	myDate: .asciiz "Creation Date: 09/28/21\n"
	#------------------------------------------------------------------------------------------------

	arr: .word 0,0,0,0,0,0,0,0,0,0	# 10 element array
	strPrompt1: .asciiz "How many elements: \n"
	strPrompt2: .asciiz "The largest element is: \n"
	strHey: .asciiz "HEY\n"
	strClrf: .asciiz "\n"
	strRangeError: .asciiz "ERROR: Range must be a positive number among range 1 to 10.\n"
	
	# $t0 is used for manipulated counter
	# $t1 used for temp array int to print
	# $t2 is initialized to 0 and compares to array element and equals said element if it is higher that present value
	# $s0 is used for counter (constant)
	# $s1 is used for array	
.text

main:
	la $t2, 0

	la $a0, strPrompt1
	li $v0, 4
	syscall
	
	# move array size to s0 register for count later
	li $v0, 5
	syscall
	
	# bounds for array size
	blt $v0, 1, errorBound	# go to param error if user input is not above 0
	bgt $v0, 10, errorBound	# go to param error if user input is over 10

	# save array to $t0 and $s0 (constant) and load array
	add $s0, $0, $v0	
	add $t0, $0, $v0
	
	la $s1, arr
	jal inLoop
	la $s1, arr
	jal parseArray
	jal FindMax
errorBound:
	la $a0, strRangeError
	li $v0, 4
	syscall
	j main
	
FindMax:
	la $a0, strPrompt2
	li $v0, 4
	syscall

	li $v0, 1
	add $a0, $0, $t2
	syscall
	j exit

	inLoop:
		li $v0, 4

		beq $t0, $0, ret
		li $v0, 5
		syscall
	
		sw $v0, 0($s1)
		addi $t0, $t0, -1
		addi $s1, $s1, 4
		j inLoop
		
	parseArray:
		beq $s0, $t0, ret
		lw $t1, 0($s1)	# move into $t1 what the pointer is pointing to in $s1
	
		add $a0, $0, $t1
		li $v0, 1
		syscall
		
		la $a0, strClrf
		li $v0, 4
		syscall 
	
		addi $s1, $s1, 4	# increment pointer
		addi $t0, $t0, 1	# print contents of array
		bgt $t1, $t2, isLarger
		
		j parseArray
	isLarger:
		add $t2, $0, $t1
		j parseArray
	ret:
		jr $ra
exit:
	li $v0, 10
	syscall
