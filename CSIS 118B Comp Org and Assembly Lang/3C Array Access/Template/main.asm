;// John Barbonio
;// CSIS-118B-4463
;// 2/4/2018
;// 3C Array Access

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 	
	myArray WORD 4 DUP(?)
     prompt BYTE "Enter a number: ", 0ah, 0dh, 0
     aPrompt BYTE "Please enter a number between 0 and 3", 0ah, 0dh, 0
     index WORD ?

.code  
main proc
     mov eax, 0
	mov edx, OFFSET prompt
     call WriteString
     call ReadInt
     mov myArray[0 * SIZEOF WORD], ax

     call WriteString
     call ReadInt
     mov myArray[1 * SIZEOF WORD], ax

     call WriteString
     call ReadInt
     mov myArray[2 * SIZEOF WORD], ax

     call WriteString
     call ReadInt
     mov myArray[3 * SIZEOF WORD], ax

     mov edx, OFFSET aPrompt
     call WriteString
     call ReadInt
     mov index, ax
     mov myArray, ax

     mov ax, myArray
     call WriteInt
     call Crlf

     
     exit
	invoke ExitProcess,0
main endp
end main