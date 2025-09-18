section .data
    msg db "Hello, syscall!", 10
    len equ $ - msg

section .text
    global _start

_start:
    ; Initialize all caller-saved registers with known values
    mov     rax, 0x1111111111111111
    mov     rdi, 0x2222222222222222
    mov     rsi, 0x3333333333333333
    mov     rdx, 0x4444444444444444
    mov     rcx, 0x5555555555555555
    mov     r8,  0x6666666666666666
    mov     r9,  0x7777777777777777
    mov     r10, 0x8888888888888888
    mov     r11, 0x9999999999999999

    ; Call write syscall: write(1, msg, len)
    mov     rax, 1          ; syscall number for write
    mov     rdi, 1          ; STDOUT
    lea     rsi, [rel msg]  ; buffer address
    mov     rdx, len        ; length
    syscall                 ; <--- syscall may clobber caller-saved regs

    ; Exit cleanly (exit syscall)
    mov     rax, 60         ; syscall: exit
    xor     rdi, rdi        ; status 0
    syscall
