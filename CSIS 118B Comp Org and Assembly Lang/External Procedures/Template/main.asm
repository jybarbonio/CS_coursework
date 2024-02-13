;// First and last name
;// CSIS-118B-4463
;// 4/29/2018
;// External Procedures

INCLUDE Irvine32.inc
strCat PROTO

;// .386
;// .model flat,stdcall
;// .stack 4096
ExitProcess proto,dwExitCode:dword

.data 		



.code  		
main proc
	
     push ebp
     call strCat
     call WriteString

     pop ebp  

	invoke ExitProcess,0
main endp
end main