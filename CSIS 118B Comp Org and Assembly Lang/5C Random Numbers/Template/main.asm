;// John Barbonio
;// CSIS-118B-4463
;// 3/11/2018
;// 5C Random Numbers

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		;// write your data in this section
	prompt BYTE "This sum of all 20 variables is: ", 0ah, 0dh, 0     ;string as info with in-built Crlf
     dwArray DWORD 20 DUP(?)                                          ;DWORD (32-Bit Unsigned) with undefined variables

.code  		;// write your program here
main PROC
     mov esi, 0
     mov ebx, 0
	mov ecx, 20              ;sets ecx register to 20, it is used as a counter
     mov edx, OFFSET dwArray  ;loads dwArray into edx for receiving variables
     call randArray           ;calls randArray procedure which loads random vars into dwArray
     call printAr             ;prints the variables of dwArray
     call sumArray            ;calls procedure that adds and displays the entire index added together

     ;call DumpRegs

	invoke ExitProcess,0
main ENDP
randArray PROC                ;beginning of randArray procedure
     
     push ebx                 ;puts the value of the ebx onto the first open layer in the stack
     mov ebx, 0               ;sets ebx to zero since it is the index counter
L1:                           ;begins loop and serves as label
     mov eax, 100             ;sets eax range for random number pool 0-99
     call RandomRange         ;calls pseudo-random number
     inc eax                  ;increments eax by 1 to address 0-100 range
     mov dwArray[ebx], eax    ;stores random array variables in dwArray from eax
     add ebx, TYPE DWORD      ;increments ebx by 1 in DWORD size (32-bit U)
     loop L1                  ;loops until ecx loop count is satisfied

     pop ebx                  ;returns ebx variable from stack
     ret                      ;returns to main where randArray was called

randArray ENDP                ;end of randArray procedure
printAr PROC                  ;start of printAr proc

     push ebx
     push ecx     

L1:  
     mov eax, dwArray[ebx]     ;moves a specified index(ebx) into into eax
     call WriteInt             ;writes what's in eax to console
     call Crlf                 ;moves number result to next line for easier readability
     add ebx, TYPE DWORD       ;increments properly by using dword instead of byte

     loop L1                   ;loops until ecx number is met (20)
     ret                       ;returns to where procedure was called

     pop ecx
     pop ebx     

printAr ENDP                   ;end of printAr proc
sumArray PROC                  ;start of sumArray proc

     mov esi, 0                ;esi will be the indermediate variable
     mov ebx, 0                ;ebx is used as the index counter
     push ecx
L2:
     add esi, dwArray[ebx]     ;moves a specified index entry(ebx) into eax
     add ebx, TYPE DWORD       ;increments properly by using dword instead of byte

     loop L2                   ;loops until ecx number is met (20)

     mov eax, esi                  
     mov edx, OFFSET prompt    ;loads string of prompt into edx
     call WriteInt             ;writes sum of dwArray into console
     call Crlf                 ;moves cursor down and to the front of console
     call WriteString          ;writes edx to console

     ret                       ;returns to main where sumArray was called
     pop ecx
     
sumArray ENDP                  ;end of sumArray proc
END main                       ;program terminated