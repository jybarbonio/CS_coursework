;// John Barbonio
;// CSIS-118B-4463
;// 2/4/2018
;// 3B Variables

INCLUDE c:\Irvine\Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		
     prompt BYTE "Enter an number: ", 0dh, 0ah, 0

	val DWORD ?
     itm DWORD ?    ;intermediate variable

.code  		
main proc
     mov edx, OFFSET prompt
     call WriteString
     call ReadInt
     mov itm, eax
     mov eax, 0
     ;call DumpRegs     

     call WriteString
     call ReadInt
     mov val, eax
     mov eax, itm
     sub eax, val
     call WriteInt
     call Crlf

     ;call DumpRegs


	invoke ExitProcess,0
main endp
end main