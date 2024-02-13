;// John Barbonio
;// CSIS-118B-4463
;// 1/28/2018
;// The General Purpose Registers

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		;// write your data in this section
	

.code  		;// write your program here
main proc
     ;BYTE, WORD, DWORD

	mov EAX, SIZEOF BYTE
     call WriteInt            ;This Irvine procedure only outputs what's in EAX
     call Crlf                ;carriage return in console output window
     mov EAX, SIZEOF WORD
     call WriteInt
     call Crlf
     mov EAX, SIZEOF DWORD
     call WriteInt
     call Crlf
     ;prints 1, 2, and 4 bytes respectively. Using other regs with WriteInt results in random garbage numbers.

     mov BL, SIZEOF BYTE      ;BYTE = 8-bit unsigned reg so fits in BL/BH register
     mov BX, SIZEOF WORD      ;16-bit unsigned int p.74 therefore AX p.74
     mov EBX, SIZEOF DWORD    ;32-bit unsigned int D meaning double p.74

	invoke ExitProcess,0
main endp
end main