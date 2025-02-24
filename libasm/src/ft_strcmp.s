; int ft_strcmp(char *str1, char *str2)

section .text
global ft_strcmp
ft_strcmp:
	cmp rdi, 0; NULL Protection
	jz null_safe; Jump to returning null if 0
	cmp rsi, 0; NULL Protection
	jz null_safe; Jump to returning null if 0
loop: ; Compare two strings untill either null or different
	mov al, [rdi]
	cmp al, [rsi]; If *str1 is different from *str2, end
	jne end; Jump out of loop if different
	cmp byte [rdi], 0; If str1 is 0, end (No need to do it for str2, since this being not 0 and str2 being 0 would've jumped before)
	jz end; Jumo out of loop if 0
	inc rdi; Increase pointer position (str1)
	inc rsi; Increase pointer position (str2)
	jmp loop ; Jumps to the loop label
end: ; Returns *str1 - *str2
	movsx rax, byte [rdi]; Moving *str1 to rax, conserving sing and clearing
	movsx rcx, byte [rsi]; Moving *str2 to rcx, conserving sing and clearing
	sub eax, ecx; Calculating *str1 - *str2
    ret ; Returns
null_safe:
	mov rax, 0; Returning a null pointer.
	ret ; Returns

; movsx allows to move a small type (1 byte) to a larger type (8 bytes), conservating the sing.
; Substraction is done with eax and ecx registers to manage int overflows (Correcly return an int, shouldn't really matter in this case)
; But for example, substracting on the 1-byte register '0 - 1' would result in 255 instead of -1.
