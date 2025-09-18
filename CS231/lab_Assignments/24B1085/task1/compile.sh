nasm -f elf64 caller-callee.asm -o caller-callee.o
ld caller-callee.o -o caller-callee

nasm -f elf64 call-function.asm -o call-function.o
ld call-function.o -o call-function
