bits 64
section .text
global strcasecmp

strcasecmp:
    xor rax, rax
    cmp rdi, 0
    je .exit
    jmp .loop

.loop:
    mov r10b, byte[rdi]
    mov r11b, byte[rsi]
    jmp .rhs

.rhs:
    cmp r10b, 65
    jge .rhs2
    jmp .lhs

.rhs2:
    cmp r10b, 90
    jle .change_rhs
    jmp .lhs

.lhs:
    cmp r11b, 65
    jge .lhs2
    jmp .compare

.lhs2:
    cmp r11b, 90
    jle .change_lhs
    jmp .compare

.change_rhs:
    add r10b, 32
    jmp .lhs

.change_lhs:
    add r11b, 32
    jmp .compare

.compare:
    cmp r10b, r11b
    jne .end
    cmp byte[rdi], 0
    je .end
    cmp byte[rsi], 0
    je .end
    inc rdi
    inc rsi
    jmp .loop

.end:
    sub r10b, r11b
    movzx rax, r10b
    jmp .exit

.exit:
    ret