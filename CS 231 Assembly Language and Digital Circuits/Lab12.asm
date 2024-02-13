.data
	#--------------------------------------------------------------------------------------------------------
	myName: .asciiz "John Barbonio\n"
	myDesc: .asciiz "Program Desc: gets user input from user and converts from Celsius to Fahrenheit"
	myDate: .asciiz "Creation Date: 10/14/21\n"
	#------------------------------------------------------------------------------------------------

	strPromptC: .asciiz "Please input a temperature in Celsius:\n"
	strResultF: .asciiz "The temperature in Fahrenheit is:\n"
	fdiv: .float 1.8
	fadd: .float 32.0
.text

main:
	la $a0, strPromptC		# load in prompt to user
	li $v0, 4
	syscall
	
	li $v0, 5			# get int user input, single precision
	syscall
	
	add $t0, $v0, $0		# load user input int into $t0
	mtc1 $t0, $f0			# move from main processor to co-processor
	cvt.s.w $f0, $f0		# convert from integer to float
	
	l.s $f1, fdiv			# load 1.8f into $f1
	l.s $f2, fadd			# add 32 to $f2
	mul.s $f0, $f0, $f1		# multiply user input by 1.8
	add.s $f0, $f0, $f2		# add 32 to user input
	
	la $a0, strResultF		# load in result string
	li $v0, 4
	syscall
	
	li $v0, 2			# printing float
	mov.s $f12, $f0			# load user input in $f12 to be printed, in printed in co-processor
	syscall

exit:
	li $v0, 10
	syscall
