;// John Barbonio
;// CSIS-118B-4463
;// 2/3/2018
;// 3A Data Types

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data
     
	

.code
main proc
     call Clrscr         ;clear screen
     mov ebx, 50         ;move 50 into ebx address
     mov eax, ebx        ;move ebx into eax
     call WriteInt       ;write value of eax to string
     call Crlf           ;write a linefeed to screen

     ;write 55 in binary to screen
     
     mov ebx, 0
     mov ebx, 110111b    ;55 in binary is 110111b
     mov eax, ebx
     call WriteInt
     call Crlf

     ;write 32 in hex to the screen
     
     mov eax, 0
     mov eax, 20h        ;32 hex is 20h (16 x 2 + 0)
     call WriteInt
     call Crlf

     ;write 20 in octal to the screen
     
     mov eax, 0
     mov eax, 24o        ;24 in octal is 20o (base 8: 10 = 8, 20 = 16, 24 = 20)
     call WriteInt
     call Crlf
     
     
     

	invoke ExitProcess,0
main endp
end main