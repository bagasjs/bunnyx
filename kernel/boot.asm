bits 32
section .multiboot
    align 4
    dd 0x1BADB002 ;; Magic number
    dd 0x00 ;; FLAGS
    dd - (0x1BADB002 + 0x00) ;; CHECKSUM

section .text
global _start
extern kernel_main

_start:
    cli
    mov esp, stack_top
    call kernel_main
    hlt

section .bss
stack_bottom:
resb 16384
stack_top:
