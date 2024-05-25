bits 64
section .text
global strlen

strlen:
	xor rax, rax
	cmp BYTE[RDI], 0x00
	je exit
	jmp .loop

.loop:
	inc rdi
	inc rax
	cmp BYTE[rdi], 0x00
	jne .loop
	jmp exit

exit:
	ret
