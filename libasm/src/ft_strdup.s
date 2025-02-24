; char *ft_strdup(const char *s);

section .text
extern malloc
global ft_strdup
ft_strdup:
	; If rdi (input) is 0 (NULL), exits.
	cmp rdi, 0
	jz null_protection

	; Count the length of the string:
	mov rax, 0; ; rax will be used as an argument for malloc. So will be the loop counter.
length: ; Loops until a char is 0, adding to the counter
	cmp byte [rdi + rax], 0; if *(s + counter) is 0, exits
	jz length_end;
	inc rax; Increase counter
	jmp length ; Jumps back
length_end:

	; call mallooc
	mov r13, rdi ; Moves s to r13
	mov rdi, rax ; Moves counter to rdi (To malloc argument)
	mov r12, rax ; Moves counter to r12 (To preserve it. r12 and r13 are safe registers to call malloc and keep their values intact)
	call [rel malloc wrt ..got] ; Now rax containes the new pointer, call it dst
	cmp rax, 0 ; Null protection
	jz malloc_error

	; Rax = DST, r13 = SRC, R12 = counter
	inc r12 ; To copy /0 too...
copy:
	cmp r12, 0 ; Exits when the counter reaches 0 (Copying from end to start)
	jz copy_end
	dec r12 ; counter --
	mov dl, byte [r13 + r12] ; Moves *(s + counter) to a 1-byte sized register
	mov byte [rax + r12], dl ; Copies that value in *(dst + counter)
	jmp copy ; Jumps back
copy_end:
	ret ; rax already hold the correct pointer

	; Malloc already sets errno, nothing to do but return NULL
malloc_error:
	mov rax, 0
	ret

	; Returns NULL
null_protection:
	mov rax, 0
	ret
