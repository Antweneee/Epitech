bits 64
section .text
global memset

memset:
        xor rax, rax
        jmp .loop

.loop:
    cmp rdx, 0
    je .exit
    mov byte[rdi], sil
    inc rdi
    dec rdx
    jmp .loop

.exit:
    ret