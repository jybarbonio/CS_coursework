.data
	#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: Fills an array with x amount of int variables, then prints the array in reverse order"
	myDate: .asciiz "Creation Date: 09/26/21\n"
	#------------------------------------------------------------------------------------------------
	
	arr: .word 0,0,0,0,0,0,0,0,0,0	# 10 element array
	strPrompt: .asciiz "Enter the number of elements:\n"
	strPrompt2: .asciiz "The reverse order of the array is:\n"
	strClrf: .asciiz "\n"
	strRangeError: .asciiz "ERROR: Range must be a positive number between 0 and 10.\n"
	
	# $t0 is used for manipulated counter
	# $t1 used for temp array int to print
	# $t2 gives number of bytes to shift pointer to rear to count backwards
	# $s0 is used for counter (constant)
	# $s1 is used for array
	
.text
main:
	la $a0, strPrompt
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
	
	j inLoop
errorBound:
	la $a0, strRangeError
	li $v0, 4
	syscall
	j main
inLoop:
	li $v0, 4

	beq $t0, $0, done
	li $v0, 5
	syscall
	
	sw $v0, 0($s1)
	addi $t0, $t0, -1
	addi $s1, $s1, 4
	j inLoop
done:
	la $s1, arr
	
	mul $t2, $s0, 4		# multiply the total by the pointer byte shift (4)
	mflo $t2		# load the product into $t2
	sub $t2, $t2, 4		# $t2 minus 4 making the sure the pointer is at the rear, and not out of bounds
	add $s1, $s1, $t2	# add $t2 to the address pointing to $s1
	li $t0, 0		# start the $t0 count from zero to max (Ss0) see below

	la $a0, strPrompt2
	li $v0, 4
	syscall
outLoop:
	beq $s0, $t0, exit
	lw $t1, 0($s1)
	li $v0, 1
	
	li $v0, 1
	add $a0, $0, $t1
	syscall
	
	la $a0, strClrf
	li $v0, 4
	syscall
	
	addi $s1, $s1, -4	# decrement pointer
	addi $t0, $t0, 1	# print contents of array
	j outLoop
exit:
	li $v0, 10
	syscall
