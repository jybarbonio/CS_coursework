;// John Barbonio
;// CSIS-118B-4463
;// 3/31/2018
;// 6A Conditional Jumps

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		;// write your data in this section
	
     prompt BYTE "Enter a number: ", 0ah, 0dh, 0
     oddMsg BYTE "Odd Number", 0ah, 0dh, 0
     evenMsg BYTE "Even Number", 0ah, 0dh, 0

.code  		;// write your program here
main proc

     mov edx, OFFSET prompt   ;prompts user for a number
     call WriteString         ;writes string to console
     call ReadInt             ;listens for a number input

     call CheckEven           ;goes to checkEven proc to evaluate number inputted (eax)

     cmp eax, 0               ;compares eax and 0 akin to if statement
     jnz EVENLABEL            ;if != 0 -> EVENLABEL
     mov edx, OFFSET oddMsg   ;else -> load oddMsg to edx
     call WriteString         ;writes string to console
     jmp EXITOUT              ;unconditional jump to exit, needed to close program properly

EVENLABEL:                    ;sub proc for even message
     mov edx, OFFSET evenMsg  ;loads string stating number is even
     call WriteString         ;writes string to console

EXITOUT:                      ;sub proc for terminating program
     invoke ExitProcess,0     ;terminates program
main endp
checkEven proc

     mov edx, 0     ;sets edx to zero
     mov ebx, 2     ;sets ebx to 2 for dividing next line
     div ebx        ;divides ax by bx
     cmp edx, 0     ;compares edx to 0
     jz IF_EVEN     ;even number jmp
     mov eax, 0     ;sets eax to zero to indicate odd number (mock boolean)
     jmp RETURN     ;goes to return sub proc

IF_EVEN:
     mov eax, 1     ;sets eax to one to signal the number was even (mock boolean)

RETURN:             ;returns to main method
     ret            ;returns to where proc was called
checkEven endp      ;end of checkEven proc
end main