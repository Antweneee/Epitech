bits 64
section .text
global memcpy

memcpy: ;memcpy(void *dest, void *src, size_t)
    xor rax, rax
    xor r9, r9
    jmp .loop

.loop:
    cmp rdx, 0
    je .exit
    mov r8b, [rsi + r9]
    mov [rdi + r9], r8b
    inc r9
    dec rdx
    jmp .loop

.exit:
    mov rax, rdi
    ret