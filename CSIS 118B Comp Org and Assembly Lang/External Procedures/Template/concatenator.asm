INCLUDE Irvine32.inc

ExitProcess proto,dwExitCode:dword

.data 		
	
     prompt BYTE "Enter a string below", 0dh, 0ah, 0
     MAX = 100
     DMAX = 200
     str1 BYTE MAX+1 DUP (?)
     str2 BYTE MAX+1 DUP (?)
     str3 BYTE DMAX+1 DUP (?)

.code  		
strCat proc uses edi esi ebp

	mov edx, OFFSET prompt
     call WriteString
     mov edx, 0
     mov edx, OFFSET str1
     call StrLength
     mov ecx, MAX
     call ReadString
     mov edx, OFFSET str2
     call ReadString
     mov edx, 0
     push OFFSET str1
     push OFFSET str2
     
     push ebp
     mov ebp, esp
     mov edi, [ebp + 1]
     mov esi, [ebp + 2]
     MOVSB
     call WriteString
     mov edx, edi
     pop ebp

	ret
strCat endp
end