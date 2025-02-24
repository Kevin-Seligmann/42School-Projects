section .comment ; Unnecesary, but ok!
; Hello !
; Sections are the units of the resulting object file.
; Here it's used to separate the data from the instructions

; write(int fd, const void buf[.count], size_t count);
; exit(int code);

; https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/ Syscall reference

section .text; Instructions
global _hello ; Label (Will be function name for C file)
_hello:

    mov rdi, 1 ; File descriptor (1) in the register
    lea rsi, [rel msg]  ; msg pointer in the register (Rel for relative) (lea to load an address (Similar to &))
    mov rdx, len  ; len in the register
    mov rax, 1 ; sys_write instruction in the register 
    syscall ; Call the kernel to execute the instruction
    mov rdi, rax ; Move result into first argument (To see bytes written with $?)
    mov rax, 60 ; Exit instruction in the eax register
    syscall ; Call the kernel to execute the instruction

section .data ; Read-write (.data1 too)
    msg        db "Hello world!", 0xa ; In the msg variable, store the data in the executable. (0xa is \n)
    len        equ $ -msg ; $ is the location of this variable on the file. msg is the location of msg on the file. Substracting them gives the length.
