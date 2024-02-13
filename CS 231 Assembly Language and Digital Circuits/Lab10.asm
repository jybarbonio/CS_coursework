# John Barbonio
# 10/6/21
# Lab 10: Create an array where user inputs n elements between 2 and 11,
# 	fills the array with said elements in subroutine and returns the
#	sums back to main to be displayed

.data
	strCount: .asciiz "How many numbers would you like to enter?\n"
	strRng: .asciiz "Please enter a number between two and eleven:\n"
	strRngErr: .asciiz "ERROR: Number must be between 2 and 11, not inclusive!\n"
	strResult: .asciiz "The sum of the array is:\n"

	arr: .word 0,0,0,0,0,0,0,0,0,0
.text
main:
	la $a0, strCount
	li $v0, 4
	syscall
	
	li $v0, 5
	syscall
	
	blt $v0, 3, RangeError		# make sure count is above two
	bgt $v0, 10, RangeError		# 	and less than eleven
	
	la $a1, arr		#  pass array pointer
	add $a2, $0, $v0	# pass number of elements counter
	
	jal FillArray
	
	la $a0, strResult	# print string result
	li $v0, 4
	syscall
	
	li $v0, 1		# set to print integers
	add $a0, $0, $v1	# add sum returned from FillArray func for display result
	syscall
	
	li $v0, 10		# close program
	syscall

FillArray:
	add $t0, $0, $a1	# pass array pointer
	add $t1, $0, $a2	# pass loop count to function to t1 for addElement loop
	add $t3, $0, 0		# gets element from array
	add $t4, $0, 0		# loop count for print function
	add $t5, $0, 0		# holds sum of array
	
	AddElement:
		beq $t1, $0, SumArray	# loop counter, decrementing to zero
		li $v0, 5		# get user input for element
		syscall
		
		sw $v0, 0($t0)		# add user input to array index
		addi $t0, $t0, 4	# increment array pointer to next array by 4 bytes
		addi $t1, $t1, -1	# decrement loop counter until zero
		addi $t4, $t4, 1	# fill up counter to decrement in print
		j AddElement
	SumArray:
		beq $t4, $0, ret	# t1 was counter and is now zero, count back up to defined array size (10)
		addi $t0, $t0, -4
		lw $t3, 0($t0)		
		add $t5, $t5, $t3
		
		addi $t4, $t4, -1	# decrement counter
		
		j SumArray
	ret:
		add $v1, $0, $t5	# pass sum back to main (return) via $v1
		jr $ra
RangeError:
	la $a0, strRngErr
	li $v0, 4
	syscall
	j main
