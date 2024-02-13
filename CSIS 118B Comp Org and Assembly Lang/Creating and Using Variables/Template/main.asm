;// John Barbonio
;// CSIS-118B-4463
;// 2/12/2018
;// Assignment 1: Creating and 

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		
     prompt BYTE "Enter a number: ", 0dh, 0ah, 0
     ansPrompt BYTE "The sum is: ", 0dh, 0ah, 0

     num1 WORD ?    ;unsigned 16-bit int
     num2 WORD ?    ;unsigned 16-bit int
     num3 DWORD ?   ;unsigned 32-bit int
     num4 DWORD ?   ;unsigned 32-bit int
     
	 

.code  		
main proc
     mov ax, 0                ;setting eax to 0 so I don't get garbage
     mov edx, OFFSET prompt   ;moves string into edx
     call WriteString         ;writes edx to console
     call ReadInt             ;reads one instance of keyboard input
     mov num1, ax             ;can only be ax because eax is too big
     
     mov ax, 0 
     mov edx, OFFSET prompt   
     call WriteString    
     call ReadInt        
     mov num2, ax             ;num2 is still a 16-bit int

     mov eax, 0               ;need a 32-bit address to address DWORD num3, num4
     mov edx, OFFSET prompt   
     call WriteString    
     call ReadInt        
     mov num3, eax            ;needs 32-bit int space

     mov eax, 0               ;32-bit int space register
     mov edx, OFFSET prompt   
     call WriteString    
     call ReadInt        
     mov num4, eax            ;needs 32-bit int space

     mov edx, OFFSET ansPrompt     ;switch to ansprompt to notify answer
     call WriteString              ;notifies user of asnwer number
     mov ax, num1
     call Crlf
     add ax, num2                  ;adds these variables to the e/ax register
     add eax, num3                 ;adds to eax as a whole to address 32-bit size
     add eax, num4
     
     call WriteInt
     call Crlf      ;these crlfs are just to separate outputs
     call Crlf

     mov eax, num4  ;manual printing order of variables in reverse
     call WriteInt
     call Crlf
     
     mov eax, num3
     call WriteInt
     call Crlf

     mov ax, num2
     call WriteInt
     call Crlf

     mov ax, num1
     call WriteInt
     call Crlf

	invoke ExitProcess,0
main endp
end main