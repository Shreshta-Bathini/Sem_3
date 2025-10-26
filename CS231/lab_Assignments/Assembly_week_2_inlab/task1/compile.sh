nasm -f elf64 print_cmplx.asm -o print_cmplx.o
gcc print_cmplx.o -o print_cmplx -no-pie
rm *.o