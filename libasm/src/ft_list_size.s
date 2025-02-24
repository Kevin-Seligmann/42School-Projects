
%include "ft_list.h"

; int ft_list_size(t_list *begin_list);

; rax = counter
; rdi = list node
; r15 = aux
global ft_list_size
ft_list_size:
	mov rax, 0

.loop:
	cmp rdi, 0
	je .end
	inc rax
	mov r15, [rdi + s_list.next]
	mov rdi, r15
	jmp .loop
.end:
	ret
