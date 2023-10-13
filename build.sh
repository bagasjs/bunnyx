if [ ! -d ./build ]; then
    mkdir ./build/
fi

if [ ! -d ./build/isodir ]; then
    mkdir ./build/isodir
fi

if [ ! -d ./build/isodir/boot ]; then
    mkdir ./build/isodir/boot
fi

if [ ! -d ./build/isodir/boot/grub ]; then
    mkdir ./build/isodir/boot/grub
fi

set -xe

nasm -f elf32 -o ./build/boot.o ./kernel/boot.asm
gcc -m32 -c -o ./build/bunnyx.o ./kernel/bunnyx.c \
    -std=gnu99 -ffreestanding -O2
gcc -m32 -c -o ./build/kernel.o ./kernel/kernel.c \
    -std=gnu99 -ffreestanding -O2
ld -m elf_i386 -T ./kernel/linker.ld -o \
    ./build/isodir/boot/bunnyx.bin ./build/boot.o ./build/kernel.o \
    ./build/bunnyx.o
cp ./kernel/grub.cfg ./build/isodir/boot/grub

if grub-file --is-x86-multiboot ./build/isodir/boot/bunnyx.bin; then
    echo "Multiboot confirmed"
    grub-mkrescue -o ./build/bunnyx.iso ./build/isodir
else
    echo "Not Multiboot"
fi

qemu-system-i386 ./build/bunnyx.iso
