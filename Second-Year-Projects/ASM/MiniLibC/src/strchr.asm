bits 64
section .text
global strchr

strchr:
    xor rax, rax
    cmp rdi, 0x00
    je .exit
    jmp .loop

.loop:
    cmp [rdi], sil
    je .succes
    cmp byte[rdi], 0x00
    je .exit
    inc rdi
    jmp .loop

.succes:
    mov rax, rdi
    jmp .exit

.exit:
    ret
