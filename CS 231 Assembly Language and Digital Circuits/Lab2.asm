.data
	msgProgramDesc: .asciiz "Program Description: A simple program to output string and integer\n"
	msgAuthor: .asciiz "Author: John Barbonio\n"
	msgSlash: .asciiz "/"
	msgCourseNumb: .asciiz "The Course number "
	msgTenureYear: .asciiz "The year in program "
	msgCLRF: .asciiz "\n"
	wDay: .word 09
	wMonth: .word 08
	wYear: .word 2021
	wClassNumb: .word 231
	wCourseYear: .word 3
	
.text
	li $v0, 4
	la $a0, msgProgramDesc
	syscall
	
	la $a0, msgAuthor
	syscall
	
	li $v0, 1
	lw $a0, wDay
	syscall
	
	li $v0, 4
	la $a0, msgSlash
	syscall
	
	li $v0, 1
	lw $a0, wMonth
	syscall
	
	li $v0, 4
	la $a0, msgSlash
	syscall
	
	li $v0, 1
	lw $a0, wYear
	syscall
	
	li $v0, 4
	la $a0, msgCLRF
	syscall
	
	la $a0, msgCourseNumb
	syscall
	
	li $v0, 1
	lw $a0, wClassNumb
	syscall
	
	li $v0, 4
	la $a0, msgCLRF
	syscall
	
	la $a0, msgTenureYear
	syscall
	
	li $v0, 1
	lw $a0, wCourseYear
	syscall
	
	#alternatively could store msgs in other registers and pull from there, but here is just rewriting the $a0 register