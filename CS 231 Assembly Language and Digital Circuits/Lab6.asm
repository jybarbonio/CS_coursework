.data
	#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: Finds the product of a power function X^y, X being base number and y being exponent\n"
	myDate: .asciiz "Creation Date: 09/21/21\n"
	#------------------------------------------------------------------------------------------------
	strQuery1: .asciiz "Please give the base number\n"
	strQuery2: .asciiz "Please give the power/exponential to go to\n"
	strFailmsg1: .asciiz "# ERROR: user input is out of bounds. Must be in range 1 to 11 inclusive\n"
	strResult: .asciiz "The product is:\n"
	
	# $t0 will be the count
	# $t1 holds base number
	# $t2 holds the product/power of result
	# $s0 holds exponent/power
.text
# initialization of counters and temp storage vars
	li $t0, 0	# initialize count to zero
	li $t2, 1	# set t2 to one, as we are working solely with positive base nums
# retrieve base num first variable
read1:
	la $a0, strQuery1
	li $v0, 4
	syscall
	
	li $v0, 5		# set $v0 to take a user int base num to be power multiplied
	syscall			# call for user input for int
	
	blt $v0, 1, errorparam1		# go to param error 1 if user input is not above one
	bgt $v0, 11, errorparam1	# go to param error 1 if user input is over 11
	
	add $t1, $0, $v0
	j read2
# retrieve exponent second variable
read2:
	la $a0, strQuery2
	li $v0, 4
	syscall
	
	li $v0, 5		# set $v0 to take a user int base num to be power multiplied
	syscall			# call for user input for int
	
	blt $v0, 0, errorparam2		# go to param error 1 if user input is not above one
	bgt $v0, 11, errorparam2	# go to param error 1 if user input is over 11
	
	add $s0, $0, $v0		# move exponential constant to $s0 storage register (is not modified)
	j loopExponent
# error for first input read1 fail
errorparam1:
	la $a0, strFailmsg1
	li $v0, 4
	syscall
	
	j read1
# error for second input read2 fail
errorparam2:
	la $a0, strFailmsg1
	li $v0, 4
	syscall
	
	j read2
# after num range checks pass for base num and exponent, proceed to recursive exponential addition loop
loopExponent:
	beq $s0, $t0, end	# $t0 = 0, while $t0 != $s0, $t0++
	mult $t2, $t1		# product is multiplied by power constant
	mflo $t2
	addi $t0, $t0, 1
	
	j loopExponent
# end loop prints result and exits program
end:
	la $a0, strResult	# load result string
	li $v0, 4
	syscall

	add $a0, $0, $t2	# load and print result of t2, which shows product of base num and exponent recursion
	li $v0, 1
	syscall

	li $v0, 10		# close program
	syscall
