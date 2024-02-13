Include Irvine32.inc

.data
     MAX = 100                ;ecx string size number
 
     str1 DWORD ?             ;undefined dword
     str2 DWORD ?             ;undefined dword
     lgth DWORD ?             ;undefined dword
.code
strCat proc

     mov edx, OFFSET str1     ;loads str1 into edx to get user inputted string
     mov ecx, MAX             ;sets a base char max for string (100)
     call ReadString          ;gets user input
     call StrLength           ;gets string length for string in edx
     mov lgth, eax            ;moves the first string length into the variable
     mov edx, OFFSET str2     ;loads the offset of str2 into edx to store user input
     call ReadString          ;gets user string input
     call StrLength           ;gets string length
     add lgth, eax            ;adds the second str length to the variable, intended to be ecx counter later

     mov ecx, 0
     mov ecx, lgth  ;moves into the ecx the string size

     push str1      ;pushes str1 onto stack
     push str2      ;pushes str2 onto stack
     
     push ebp       ;pushes ebp base into stack
     mov ebp, esp   ;sets up stack frame

     mov edi, [ebp + 1]  ;moves the first string into edi
     mov esi, [ebp + 2]  ;moves the second string into esi
     rep MOVSD           ;moves the memory in esi to edi, based on ecx counter
     mov edx, edi        ;moves the edi string product to edx for printing

     pop ebp             ;clears the stack frame
     pop str2            ;pops str2 variable
     pop str1            ;pops str1 variable
     

     ret                 ;returns to main.asm

strCat endp
end