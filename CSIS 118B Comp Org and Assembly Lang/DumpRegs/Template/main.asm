;// John Barbonio
;// CSIS-118B-4463
;// 1/29/2018
;// Lab 2B Dump Regs

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		;// write your data in this section
	

.code  		;// write your program here
main proc
	call Clrscr
     call DumpRegs  ;eax would be random numbers at this point
     mov al, 22h
     call DumpRegs  ;prints 22 in hex replacing the first two numbers of garbage (AL)
     mov ax, 2222h
     call DumpRegs  ;prints 2222 in AX register
     mov ah, 33h
     call DumpRegs  ;prints 33 over 22 in AH register
     mov eax, 4444h
     call DumpRegs ;prints 4444 over four numbers on the EAX register
     ;the value is not ok as previous numbers in the register linger because they are not cleared
     ;resetting the registers to 0     

     exit

	invoke ExitProcess,0
main endp
end main