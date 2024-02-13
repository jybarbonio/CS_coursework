.data
	ItemArr: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	CouponArr: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	strPrompt1: .asciiz "Please enter the number of items you are purchasing:\n"
	strPrompt2: .asciiz "Please enter the number of coupons that you want to use.\n"
	strPromptI: .asciiz "Please enter the price of item "
	strPromptC: .asciiz "Please enter the amount of coupon "
	strColon: .asciiz ": "
	strResult: .asciiz "Your total charge is:	$"
	strClrf: .asciiz "\n"
	strRetailEmployee: .asciiz "Thank you for shopping with us.\n"
	
	strPriceRngErr: .asciiz "ERROR: Invalid price inputted. Please try again.\n"
	strCouponRngErr: .asciiz "ERROR: This coupon is unacceptable. Coupon is valued as 0.\n"
	
	strItemErr: .asciiz "ERROR: Too many items being purchased or invalid number!\n"
	strCouponErr: .asciiz "ERROR: Invalid or too many coupons! Please try again.\n"
.text
	
main:
	la $a0, strPrompt1		# prompt user for amt of purchased items
	li $v0, 4
	syscall
	
	li $v0, 5			# user input call
	syscall
	
	blt $v0, $0, ErrItemAmt		# checks if amt of purchased items isn't negative
	bgt $v0, 20, ErrItemAmt		# checks if amt of purchased items doesn't exceed 20
	add $s0, $v0, $0		# save amt of items to purchase to $s0
	
	la $a0, ItemArr			# pass array pointer
	add $a1, $s0, $0		# load amt of purchased items to be passed to FillPriceArray
	jal FillPriceArray
	add $t1, $v1, $0		# return subtotal, storing to $t0
	
	la $a0, strPrompt2
	li $v0, 4
	syscall
	
	li $v0, 5			# get coupon count
	syscall				
	add $t0, $v0, 0			# save coupon count param to $t0
	
	blt $v0, 0, ErrCouponAmt	# checks if amt of coupons isn't negative
	bgt $v0, $s0, ErrCouponAmt		# checks if amt of coupons doesn't exceed 20
	
	la $a0, CouponArr		# pass coupon arr ptr
	la $a1, ItemArr			# pass item arr ptr
	add $a2, $0, $t0		# pass counter param
	jal FillCouponArray
	add $t0, $v0, 0			# get price with savings param that was returned
	
	la $a0, strResult		# print prompt for result
	li $v0, 4
	syscall
	
	add $a0, $t0, $0		# print result num that was returned from FillCouponArray
	li $v0, 1
	syscall
	
	la $a0, strClrf			# nextline print
	li $v0, 4
	syscall	
	
	la $a0, strRetailEmployee	# print thank you for shopping
	li $v0, 4
	syscall
	
	li $v0, 10			# program exit
	syscall
	
FillPriceArray:
	add $t0, $a0, $0		# save arr ptr param that was passed
	add $t1, $a1, $0		# save count param that was passed
	li $t2, 0			# local counter to count up to $t1 param
	add $t3, $0, 0			# holds subtotal or total of all inputted prices before tex
	add $t4, $0, 0			# hold counter
	j AddPriceElem
	
	AddPriceElem:
		beq $t2, $t1, PriceRet
		
		la $a0, strPromptI		# prompt user for price of item
		li $v0, 4
		syscall
		
		la $a0, 1, ($t2)		# print index of array so user knows what item is being priced, 1++ because of human readability
		li $v0, 1
		syscall
		
		la $a0, strColon		# colon
		li $v0, 4
		syscall	
		
		li $v0, 5			# get user input for item price
		syscall
		
		blt $v0, $0, ErrPriceRng	# price of item cannot be negative, will default to 0 (free item) if input is negative
		
		sw $v0, 0($t0)			# add element to array, does not empty $v0
		add $t3, $t3, $v0		# add to subtotal, using element retained in $v0, empties $v0
		addi $t2, $t2, 1		# increment counter
		addi $t0, $t0, 4		# increment pointer
		j AddPriceElem
	PriceRet:
		mult $t1, $4			# multiply count by byte to reset ItemArr ptr back to front
		mfhi $t1
		sub $t0, $t0, $t1		# reset $t0 ItemArr ptr back to front
		
		add $v1, $t3, $0		# return subotal
		jr $ra
	ErrPriceRng:
		la $a0, strPriceRngErr
		li $v0, 4
		syscall
		
		j AddPriceElem
		
FillCouponArray:
	add $t0, $a0, $0		# save coupon arr ptr param that was passed
	add $t1, $a1, $0		# save item arr ptr param that was passed
	add $t2, $a2, $0		# save count value param that was passed
	li $t3, 0			# counter for number of items up to $t1
	add $t4, $0, 0			# used to hold item arr price for subtraction
	add $t5, $0, 0			# total with savings
	j AddCouponElem
	
	AddCouponElem:
		beq $t3, $t2, CouponRet
		
		la $a0, strPromptC		# prompt user for coupon savings value
		li $v0, 4
		syscall
		
		la $a0, 1, ($t3)		# print index of array so user knows what item is being priced, 1++ because of human readability
		li $v0, 1
		syscall
		
		la $a0, strColon		# colon
		li $v0, 4
		syscall	
		
		li $v0, 5			# get user input of coupon value
		syscall
		
		blt $v0, 0, ErrCouponRng	# savings cannot be lower than zero
		beq $v0, $t1, ErrCouponRng	# savings must not equal price
		bgt $v0, $t1, ErrCouponRng	# savimgs cannot be greater than price
		bgt $v0, 10, ErrCouponRng	# savings cannot be greater than 10
		
		sw $v0, 0($t0)			# save user input into coupon arr index
		add $t4, $v0, 0			# save coupon savings to $t4
		lw $v0, 0($t1)			# get price from item arr ptr
		
		sub $t4, $v0, $t4		# modify price array with coupon savings, putting result in $t5 in case normal price is to not be modified
		add $t5, $t5, $t4		# add index price with savings to total
		add $t0, $t0, 4			# increment coupon arr ptr
		add $t1, $t1, 4			# increment item arr ptr
		add $t3, $t3, 1			# increment counter
		j AddCouponElem
	ErrCouponRng:
		la $a0, strCouponRngErr
		li $v0, 4
		syscall
		
		li $v0, 0			# set coupon savings to 0 due to invalid input
		
		sw $v0, 0($t0)			# save user input into coupon arr index
		add $t4, $v0, 0			# save coupon savings to $t4
		lw $v0, 0($t1)			# get price from item arr ptr
		
		sub $t4, $v0, $t4		# modify price array with coupon savings, putting result in $t5 in case normal price is to not be modified
		add $t5, $t5, $t4		# add index price with savings to total
		add $t0, $t0, 4			# increment coupon arr ptr
		add $t1, $t1, 4			# increment item arr ptr
		add $t3, $t3, 1			# increment counter
	
		j AddCouponElem
	CouponRet:
		add $v0, $t5, 0
		jr $ra
ErrItemAmt:
	la $a0, strItemErr
	li $v0, 4
	syscall
	j main
ErrCouponAmt:
	la $a0, strCouponErr
	li $v0, 4
	syscall
	j main