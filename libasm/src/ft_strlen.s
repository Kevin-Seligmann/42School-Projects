; int ft_strlen(char *str)
; https://www.ired.team/miscellaneous-reversing-forensics/windows-kernel-internals/linux-x64-calling-convention-stack-frame Functions calls

section .text
global ft_strlen
ft_strlen:
	mov rax, 0; Move 0 to RAX (Counter)
	cmp rdi, 0; NULL Protection
	jz end; quits
loop: ; Loops until a char is 0, adding to the counter
	cmp byte [rdi], 0; If RDI (A char * dereferenced) is 0
	jz end; quit
	inc rdi; Increase pointer position
	inc rax; Increase counter
	jmp loop ; Jumps to the loop label
end:
    ret ; Returns
