;// John Barbonio
;// CSIS-118B-4463
;// 5/11/2018
;// 2D Arrays

INCLUDE Irvine32.inc

fill2DArray PROTO,
     myArray: PTR DWORD,
     cLength: DWORD,
     rLength: DWORD

print2DArray PROTO,
     myArray: PTR DWORD,
     cLength: DWORD,
     rLength: DWORD

sumOddEven PROTO,
     myArray: PTR DWORD,
     cLength: DWORD,
     rLength: DWORD,
     oddNum: DWORD,
     evenNum: DWORD

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		;// write your data in this section
	
     array DWORD 20 DUP(?)

.code  		;// write your program here
main proc
	
     invoke fill2DArray,
          addr array,
          5,
          4
     invoke print2DArray,
          addr array,
          5,   
          4

     invoke SumOddEven,
          addr array,
          5,   
          4


	invoke ExitProcess,0
main endp
fill2DArray PROC,
     myArray: PTR DWORD,
     cLength: DWORD,
     rLength: DWORD,

     mov ecx, rLength
     mov edi, myArray
ROW:
     push ecx            ;save row length
     mov ecx, cLength    ;initialise loop with column size
COL:
     mov eax, 100        ;value between 0 and 99
     call RandomRange    ;puts a random number into eax
     add eax, 1          ;scales up to 1 - 100
     mov [edi], eax      ;store value in the array
     add edi, 4          ;move by one dword
     loop COL
     pop ecx             ;restore row length
     loop ROW
     ret                 ;returns to main

fill2DArray ENDP
print2DArray PROC,
     myArray: PTR DWORD,
     cLength: DWORD,
     rLength: DWORD,

     mov ecx, rLength
     mov edi, myArray
ROW:
     push ecx            ;popped so it can be restored later
     mov ecx, cLength
COL:
     mov eax, [edi]
     call WriteDec
     mov al, 09h         ;ASCII tab char
     call WriteChar      ;writes ASCII tab to console   
     add edi, 4          ;increaes pointer by a dword
     loop COL            ;loops col subproc
     pop ecx             ;to restore ROW count
     call Crlf           ;divider between row and column
     loop ROW            ;loops row subproc
     ret                 ;returns to main
print2DArray ENDP
sumOddEven PROC,
     myArray: PTR DWORD,
     cLength: DWORD,
     rLength: DWORD,
     oddNum: DWORD,
     evenNum: DWORD

     mov ecx, rLength
     mov edi, myArray
ROW:
     push ecx            ;popped so it can be restored later
     mov ecx, cLength

ODDS:
     mov eax, [edi]
     div eax, 2          ;divides by two then checks the split
                         ;this is no excuse but I shouldn't have taken 5 classes while working
     add edi, 4          ;increaes pointer by a dword
     loop COL            ;loops col subproc
     pop ecx             ;to restore ROW count
     call Crlf           ;divider between row and column
     loop ROW            ;loops row subproc

EVENS:
     
     ret                 ;returns to main
     
sumOddEven ENDP
end main