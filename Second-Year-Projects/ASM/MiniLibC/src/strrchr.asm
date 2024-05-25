bits 64
section .text
global strrchr

strrchr:
    xor rax, rax
    cmp rdi, 0
    je .exit
    jmp .loop

.loop:
    cmp byte[rdi], 0
    je .exit
    cmp [rdi], sil
    je .succes
    inc rdi
    jmp .loop

.succes:
    mov rax, rdi
    inc rdi
    jmp .loop

.exit:
    ret
