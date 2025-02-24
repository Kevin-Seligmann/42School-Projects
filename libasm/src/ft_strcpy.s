; char *ft_strcpy(char *dst, char *src)

section .text
global ft_strcpy
ft_strcpy:
	mov rax, rdi; Moving dst for return value
	cmp rdi, 0; NULL Protection
	jz null_safe; Jump to returning null if 0
	cmp rsi, 0; NULL Protection
	jz null_safe; Jump to returning null if 0
loop: ; Copy bytes from src to dst until a null byte is found
	cmp byte [rsi], 0; *src,
	jz end; Jump out of loop if *src=0
	mov cl, byte [rsi]; Made byte by byte but also can be made by packs of 8 bytes
	mov byte [rdi], cl
	inc rdi; Increase pointer position (dst)
	inc rsi; Increase pointer position (src)
	jmp loop ; Jumps to the loop label
null_safe:
	mov rax, 0; Returning a null pointer.
	ret
end:
    ret
