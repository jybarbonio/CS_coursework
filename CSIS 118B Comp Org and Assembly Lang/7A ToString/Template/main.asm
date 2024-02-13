;// John Barbonio
;// CSIS-118B-4463
;// 4/15/18
;// 7A ToString

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		;// write your data in this section
	
     myArray BYTE 25 DUP(?)
     divisor WORD 10          ;to div by 10
     count BYTE 0             ;create a counter
     prompt BYTE "please enter a number: ", 0dh, 0ah, 0

     intArray BYTE 6 DUP(?)
     stArray BYTE "123", 0dh, 0ah, 0
     stSize BYTE ?

.code  		;// write your program here
main proc
	
     mov eax, 9
     mov esi, OFFSET myArray
     call ToString
     mov edx, OFFSET myArray
     call WriteString
     call Crlf

	invoke ExitProcess,0
main endp
ToString proc
     push edx
     push ebx
     push ecx

     mov ebx, 0
     mov edx, 0
     mov ecx, 0
L1:
     mov edx, 0     ;remainder is in edx. clear it for now
     cmp ax, 10     ;if less than 10 we are done
     jc DONE
     div divisor    ;divide eax by 10
     or dx, 3030h   ;adds 48 to the divisor
     mov dh, 0      ;clears upper part of dx
     push dx        ;push char onto the stack
     inc cx         ;increment count of chars pushed
     jmp L1         ;loop to top

DONE:
     mov ah, 0      ;clear upper register
     or al, 30h     ;add 48 to character
     mov [esi], al  ;add to front of array
     mov bx, 1      ;setup index into the array
     inc esi        ;mov to next item in array
L2:
     mov dx, 0      ;clear the upper register
     pop dx         ;pop top of stack into the dx
     mov [esi], dl  ;move character to the array
     inc esi        ;increments to move to the next value
     loop L2        ;jump to top of loop
     mov dl, 0      ;we are done. null terminate
     mov [esi], dl  ;add null to end

     pop ecx
     pop ebx
     pop edx
     ret

ToString endp
ToInt proc
     push edx
     push ebx
     push ecx

     mov ebx, 0
     mov edx, 0
     mov ecx, 0
L1:
     mov esi, [SIZEOF stArray * BYTE]
     mov ebp, OFFSET intArray
     mov edi, OFFSET stArray
     mov al, [esi]
     cmp al, 48
     jb INVALID
     cmp al, 57
     ja INVALID
     sub al, 48
     mul divisor
     add divisor, 10
     push ax
     loop L1

INVALID:
     
L2:
     mov ax, 0
     pop ax
     mov [ebp], ax
     inc ebp
     loop L2
     mov al, 0
     mov [ebp], al

     pop ecx
     pop ebx
     pop edx
     ret
ToInt endp
end main