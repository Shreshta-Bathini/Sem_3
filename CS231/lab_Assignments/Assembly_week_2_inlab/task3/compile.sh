nasm -f elf64 ../task1/print_cmplx.asm -o ./print_cmplx.o
objcopy --redefine-sym main=print_main print_cmplx.o
nasm -f elf64 adv_cmplx_arith.asm -o ./adv_cmplx_arith.o
gcc adv_cmplx_arith.o print_cmplx.o -o adv_cmplx_arith -no-pie
rm *.o