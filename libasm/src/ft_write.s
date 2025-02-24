; ssize_t ft_write(int fd, const void buf[.count], size_t count);

section .text
extern __errno_location
global ft_write
ft_write:
	; Calls write
	mov rax, 1
	syscall

	; Returns from sys_write are:
	; < 0 indicates an error (errno)
	; >= 0 bytes written.

	; Jump if less than 0
	cmp rax, 0
	js error
	; Return the written bytes
	ret

error:
	; Stores and negates the return value
	mov rcx, rax
	neg rcx
	; Calls __erno_location
	call [rel  __errno_location wrt ..got]
	; Stores the error value in the rax pointed address (Which should've returned by _errno_location)
	mov [rax], rcx
	; Returns -1
	mov rax, -1
	ret
