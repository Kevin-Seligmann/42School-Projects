%include "ft_list.h"

; void	ft_list_sort(t_list **begin_list, int (*cmp)())

global ft_list_sort
ft_list_sort:
	cmp rdi, 0
	je .return
	cmp rsi, 0
	je .return

	push r11 ; comparing function
	push r12 ; s_list*, iteration head
	push r13 ; s_list*, iteration node
	push r14 ; aux for looping/sorting
	push r15 ; aux for swapping

	mov r11, rsi ; save cmp()
	mov r12, [rdi] ; iteration_head = *begin_list
.outer_loop:
	cmp r12, 0 ; if iteration_head == 0, breaks
	je .outer_loop_end

	mov r13, r12; iteration_node = iteration_head
	.inner_loop:
		mov r14, [r13 + s_list.next] ; aux = iteration_node->next
		cmp r14, 0 ; if iteration_node->next == 0, breaks
		je .inner_loop_end

		; Compare
		; cmp(iteration_node->data, iteration_node->next->data) 
		mov rdi, [r13 + s_list.data] ; arg1 = iteration_node->data
		mov rsi, [r14 + s_list.data] ; arg2 = iteration_node->next->data
		call r11 ; comparing function
		cmp eax, 0 ; If (int) > 0, sort (Swap data)
		jg .swap_data
		.data_swapped:

		mov r13, [r13 + s_list.next] 
		jmp .inner_loop
	.inner_loop_end:

	mov r12, [r12 + s_list.next] ; interation_head = iteration_head->next
	jmp .outer_loop
.outer_loop_end:

	pop r15
	pop r14
	pop r13
	pop r12
	pop r11

.return:
	ret

.swap_data:
	mov r15, [r13 + s_list.data] ; aux = iteration_node->data
	mov rax, [r14 + s_list.data] ; aux2 = iteration_node->next->data
	mov [r13 + s_list.data], rax ; iteration_node->data = iteration_node->next->data
	mov [r14 + s_list.data], r15 ; iteration_node->next->data = iteration_node->data
	jmp .data_swapped
