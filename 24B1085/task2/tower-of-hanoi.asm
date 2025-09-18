section .data
    shifted_disk db "Shifted disk "
    from_str db " from "
    to_str db " to "
    a_rod db 'A'
    b_rod db 'B'
    c_rod db 'C'
    newline db 10
    shifted_len equ 13
    from_len equ 6
    to_len equ 4
    buffer db 100 dup(0) ; Output buffer for result string

section .bss
    input_buf resb 20  ; Reserve 20 bytes for input
    num resq 1         ; 64-bit integer

section .text
    global printNum
    global hanoi
    global _start 
    global printFromAndTo

printNum:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to print an arbitary number stored in rax
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
add bl,'0'
mov [input_buf],bl
mov rax,1
mov rdi,1
mov rsi,input_buf
mov rdx,1
syscall 
ret
printFromAndTo:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to print " from " *rax " to " *rdi
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
push rdi
push rax

mov rsi,from_str
mov rdx,from_len
mov rdi,1
mov rax,1
syscall

pop rax

mov [input_buf],al
mov rsi,input_buf
mov rax,1
mov rdi,1
mov rdx,1
syscall

mov rsi,to_str
mov rdx,to_len
mov rdi,1
mov rax,1
syscall

pop rdi

mov bl,dil
mov [input_buf],bl
mov rsi,input_buf
mov rax,1
mov rdi,1
mov rdx,1
syscall

mov rsi,newline
mov rdx,1
mov rdi,1
mov rax,1
syscall

ret

hanoi:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; C code for function
;;;; void hanoi(int n, char from, char to, char aux) {
;;;;     if (n == 1) {
;;;;         printf("Shifted disk 1 from %c to %c\n", from, to);
;;;;         return;
;;;;     }
;;;;     hanoi(n - 1, from, aux, to);
;;;;     printf("Shifted disk %d from %c to %c\n", n, from, to);
;;;;     hanoi(n - 1, aux, to, from);
;;;; }
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    cmp rbx,1
    je .recurse

    push rax
    push rdi
    push rcx
    push rbx

    sub rbx,1
    mov r9,rcx
    mov rcx,rdi
    mov rdi,r9

    call hanoi

    mov rsi,shifted_disk
    mov rdx,shifted_len
    mov rdi,1
    mov rax,1
    syscall

    pop rbx
    push rbx

    call printNum
    
    pop rbx
    pop rcx
    pop rdi
    pop rax

    push rax
    push rdi
    push rcx
    push rbx

    call printFromAndTo

    pop rbx
    pop rcx
    pop rdi
    pop rax

    mov r9,rcx
    mov rcx,rax
    mov rax,r9

    push rax
    push rdi
    push rcx
    push rbx

    sub rbx,1

    call hanoi

    pop rbx
    pop rcx
    pop rdi
    pop rax

    jmp .return
.recurse:
    push rax
    push rdi
    push rcx
    push rbx

    mov rsi,shifted_disk
    mov rdx,shifted_len
    mov rdi,1
    mov rax,1
    syscall

    pop rbx
   
    mov rbx,1
    call printNum

    pop rcx
    pop rdi
    pop rax

    call printFromAndTo 
.return:
    ret

_start:
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Start of your code ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Write code to take in number as input, then call hanoi(num, 'A','B','C')
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  End of your code  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 mov rax,0
    mov rsi,input_buf
    mov rdi,0
    mov rdx,20
    syscall

    xor rax,rax
    xor rcx,rcx

.convert1:
    movzx rcx, byte [rsi] ; load byte
    cmp rcx, 10           ; check for newline
    je .done
    sub rcx, '0'          ; convert ASCII to digit
    imul rax, rax, 10
    add rax, rcx
    inc rsi
    jmp .convert1

.done:
    mov rbx,rax
    mov al,[a_rod]
    mov dil ,[b_rod]
    mov cl,[c_rod]
    call hanoi
    mov     rax, 60         ; syscall: exit
    xor     rdi, rdi        ; status 0
    syscall