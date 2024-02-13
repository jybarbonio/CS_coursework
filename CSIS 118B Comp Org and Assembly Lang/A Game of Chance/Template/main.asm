;// John Barbonio
;// CSIS-118B-4463
;// 4/1/2018
;// A Game of Chance

INCLUDE Irvine32.inc

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		;// write your data in this section

caseTable BYTE 'y'
EntrySize = ($ - CaseTable)
     DWORD random
     BYTE 'n'
     DWORD close

     NoOfEntries = ($ - caseTable) / EntrySize
	
     prompt BYTE "Welcome to the dice game. Would you like to play? (Y/N)", 0dh, 0ah, 0
     guessPrompt BYTE "Please enter a number: ", 0dh, 0ah, 0
     win BYTE "You win! $100 has been added to your account.", 0dh, 0ah, 0
     lose BYTE "You lose! Please try again.", 0dh, 0ah, 0
     rollAgain BYTE "Please roll again.", 0dh, 0ah, 0
     Y_select BYTE "You have pressed Yes. Please guess a dice roll between 1 and 6: ", 0dh, 0ah, 0
     retryInput BYTE "Try again. You entered an invalid number or input.", 0dh, 0ah, 0
     bank DWORD 10
     Balance BYTE "Your balance is: ", 0

.code  		;// write your program here
main proc

     call chooseProc

	invoke ExitProcess,0
main endp
chooseProc proc
     
     mov ecx, NoOfEntries
     mov ebx, OFFSET CaseTable
     
     mov edx, OFFSET prompt
     call WriteString

Start:
     
     mov edx, OFFSET Balance
     call WriteString	
     mov eax, bank
     call WriteInt

     call Crlf
     
     call ReadChar

L1:
     cmp al, [ebx]
     jne L2
     call NEAR PTR [ebx + 1]
     jc quit
L2:
     add ebx, EntrySize
     loop L1
     jmp Start
     
quit:
     ret  

chooseProc endp
random proc

     mov edx, OFFSET Y_Select
     call WriteString

     dec bank

Retry:

     call ReadInt
     mov esi, eax        ;esi will be used to store guess number
     call Randomize      ;seeds pseudo-random int by PC time
     mov  eax, 5         ;get random number equivalent to dice sides (0-6)
     call RandomRange    ;call a random number between 0-5
     inc  eax            ;makes the range 1 to 6 (there is no zero on dice)
     mov edi, eax        ;stores the dice roll into the edi

     cmp esi, 7      ;checking for invalid inputs that are over 6
     jae RetryMsg
     cmp esi, edi
     je IS_EQUAL
     mov edx, OFFSET lose
     call WriteString
     mov eax, bank
     jmp Retry
     ret

IS_EQUAL:
     add bank, 100
     mov edx, OFFSET win
     call WriteString
     mov eax, bank
     call Crlf
     call WriteInt
     call Crlf

RetryMsg:
     mov edx, OFFSET retryInput
     call WriteString
     call Crlf
     jmp Retry

random endp
close proc
     
     stc
     ret

close endp
end main