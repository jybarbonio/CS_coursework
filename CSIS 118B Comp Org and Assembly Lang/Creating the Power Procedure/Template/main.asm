;// John Barbonio
;// CSIS-118B-4463
;// 3/4/2018
;// 5B Creating the Power Procedure

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		;// write your data in this section
	


.code  		;// write your program here
main proc
	
     mov eax, 3          ;holds base number for raising to a power
     call power          ;invokes the power procedure
     call WriteDec       ;writes the decimal after the power proc does its thing
     call Crlf           ;carriage return line feed for neatness

	invoke ExitProcess,0
main endp

power PROC

     push ebx            ;pushes ebx onto stack
     push ecx            ;pushes ecx onto next free stack slot

     mov ebx, 3          ;specifies to what power you want the base to be
     mov ecx, ebx        ;ecx is loop counter and will hold power to raise base (eax)
     dec ecx             ;subtracts the power under it stops at zero
     mov ebx, eax        ;need an intermediate or else eax just multiplies by too much x2, x4, x8
L1:
     mul ebx             ;multiplies eax by register or memory location, ebx is the register in this case
     loop L1             ;loops L1 under ecx count is met
     
     pop ecx             ;pop in reverse order from how they were pushed
     pop ebx             ;pop in reverse order from how they were pushed (this was the first push)

     ret
power ENDP

end main