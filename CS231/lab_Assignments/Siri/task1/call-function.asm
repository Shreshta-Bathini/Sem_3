section .data
    msg db "Hello, syscall!", 10
    len equ $ - msg

section .text
    global func_callee
    global func_caller
    global _start

func_callee: ; func_callee(a,b) -> a + b
    ; This function is called by the caller
    ; It can modify caller-saved registers
    ; but must preserve callee-saved registers
    push rbp
    push rsp
    push rbx
    push r12
    push r13
    push r14
    push r15

    add rax, rdi ; rax = rax + rdi (a + b)
    mov rdi, 5 ; mess around with random caller saved register
    mov rsi, 10 ; mess around with another caller saved register
    mov rdx, 15 ; mess around with another caller saved register   
    mov rcx, 20 ; mess around with another caller saved register
    mov r8, 25  ; mess around with another caller saved register
    mov r9, 30  ; mess around with another caller saved register
    mov r10, 35 ; mess around with another caller saved register
    mov r11, 40 ; mess around with another caller saved register

    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    pop rsp
    pop rbp
    ret

func_caller: ; func_caller() -> calls func_callee
    push rbp
    push rsp
    push rbx
    push r12
    push r13
    push r14
    push r15

    mov rax, 5
    mov rdi, 10 ; first argument (a)

    ; save all caller-saved registers

    
    push    rdi
    push    rsi
    push    rdx
    push    rcx
    push    r8
    push    r9
    push    r10
    push    r11


    call func_callee ; call the callee function

    ; restore all caller-saved registers

    
    pop    rdi
    pop    rsi
    pop    rdx
    pop    rcx
    pop    r8
    pop    r9
    pop    r10
    pop    r11

    nop ; rax should have 15, every other register should be unchanged

    pop r15
    pop r14
    pop r13
    pop r12
    pop rbx
    pop rsp
    pop rbp
    ret

_start:
    call func_caller
    mov     rax, 60         ; syscall: exit
    xor     rdi, rdi        ; status 0
    syscall


