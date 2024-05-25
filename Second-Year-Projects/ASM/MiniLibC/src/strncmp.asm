bits 64
section .text
global strncmp

strncmp: ;strcmp(char const *s1,  char const *s2)
    xor rax, rax
    jmp .loop

.loop:
    cmp rdx, 0
    je .end
    mov r10b, byte[rdi]
    mov r11b, byte[rsi]
    cmp r10b, 0
    je .end
    cmp r10b, r11b
    jne .end
    jmp .continue

.continue:
    inc rdi
    inc rsi
    dec rdx
    jmp .loop

.end:
    sub r10b, r11b
    movsx rax, r10b
    jmp .exit

.exit:
    ret

