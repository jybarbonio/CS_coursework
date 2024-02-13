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
	
	la $t0, arr
	add $t1, $0, $v0
	
	add $a1, $0, $t0	# pass array pointer
	add $a2, $0, $t1	# pass count
	jal FillArray
	# void return

	add $a1, $0, $t0	# pass array pointer
	add $a2, $0, $t1	# pass count
	jal AddElement
	add $t0, $0, $v0	# get arr ptr that was returned
	add $t1, $0, $v1	# get count that was returned
	
	
	add $a1, $0, $t0	# pass array pointer
	add $a2, $0, $t1	# pass counter
	jal SumArray
	add $t0, $0, $v0	# get sum result that was returned
	
	la $a0, strResult	# print string result
	li $v0, 4
	syscall
	
	add $a0, $0, $v1	# add sum returned from FillArray func for display result
	li $v0, 1		# set to print integers
	syscall
	
	li $v0, 10		# close program
	syscall

# void FillArray (pass array and counter, void return)
FillArray:
	add $t2, $0, $a1	# pass array pointer
	add $t3, $0, $a2	# pass count
	add $t4, $0, 0		# counter starting at zero
	add $t5, $0, 0		# gets element from array
	add $t6, $0, 0		# holds sum of array
	jr $ra
# void AddElement (no passed)
AddElement:
	add $t2, $a1, $0	# pass array pointer
	add $t3, $a2, $0	# pass count
	j loop
	loop:
		beq $t4, $t3, ret	# loop counter, decrementing to zero
		li $v0, 5		# get user input for element
		syscall
		
		sw $v0, 0($t2)		# add user input to array index
		addi $t2, $t2, 4	# increment array pointer to next array by 4 bytes
		addi $t4, $t4, 1	# increment loop counter until is equal to count
		j loop
	ret:
		add $v0, $0, $t2	# return pointer
		add $v1, $0, $t3	# return counter		
		jr $ra
# int SumArray, returning sum
SumArray:
	add $t2, $0, $a1	# pass array pointer
	add $t3, $0, $a2	# pass count
	j loop2
	loop2:
		beq $t4, $0, ret2	
		addi $t2, $t2, -4
		lw $t5, 0($t2)		
		add $t6, $t6, $t5
		
		addi $t4, $t4, -1	# inecrement counter
		
		j loop2
	ret2:
		add $v1, $0, $t6	# return with sum param
		jr $ra
RangeError:
	la $a0, strRngErr
	li $v0, 4
	syscall
	j main
