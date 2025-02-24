%include "ft_list.h"

; void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))

; Inputs
; rdi list_begin
; rsi data
; rdx cmp
; rcx free_f

section .text
extern free
global ft_list_remove_if
ft_list_remove_if:
	; If list, cmp, or free_fct are null, return
	cmp rdi, 0
	je .return
	cmp rdx, 0
	je .return
	cmp rcx, 0
	je .return

	; Variables
	; r15 'next' node
	; r14 'prev' node
	; r13 'current' 'node'
	; r12 'beging_list'
	; rbx 'data_ref'
	; rsp[+ 0] 'cmp'
	; rsp[+ 16] 'free_fct'

	; Saving callee-saved
	push r15
	push r14
	push r13
	push r12
	push rbx

	; Storing variables
	sub rsp, 32			; Two variables of 16 bits
	mov rbx, rsi		; data_ref
	mov r12, rdi		; list_begin
	mov [rsp], rdx		; cmp
	mov [rsp + 16], rcx	; free_fct

	; Main program
	mov r13, [r12]	; current_node = *being_list
	mov r14, 0 		; prev_node = NULL
.loop:
	cmp r13, 0 ; if node ==  0, break
	je .end
	mov r15, [r13 + s_list.next] ; next_node = current_node->next
	mov rdi, [r13 + s_list.data] ; arg1 = current_node->data
	mov rsi, rbx	; arg2 = data_ref
	call [rsp]		; cmp(current_node->data, data_ref)
	cmp rax, 0		; cmp(current_node->data, data_ref) == 0
	je .free_node	; If 0: free current_node
	mov r14, r13	; Else: prev_node = current_node
	.loop_continuation:
	mov r13, r15	; current_node = next_node
	jmp .loop
.end:
	; Restoring stack
	add rsp, 32 ; Two variables of 16 bits
	pop rbx
	pop r12
	pop r13
	pop r14
	pop r15
.return:
	ret

.free_node:
	mov rdi, [r13 + s_list.data]; arg1 = current_node->data
	call [rsp + 16]				; free_fct(current_node->data)
	mov rdi, r13				; arg1 = current_node
	call [rel free wrt ..got]	; free(current_node)
	cmp r13, [r12]				; if current_node = begin_list
	je .replace_head			; If equal, replace node_begin
	mov [r14 + s_list.next], r15; else prev_node->next = next
jmp .loop_continuation

.replace_head:
	mov [r12], r15 ; *begin_list = next 
jmp .loop_continuation

; Equivalent C code:
; {			
; 	node = *begin_list;
; 	prev = NULL;
; 	while (node)
; 	{
; 		next = node->next;
; 		if (cmp(node->data, data_ref) == 0)
; 		{
; 			free_fct(node->data);
; 			free(node);
; 			if (node == *begin_list)
; 				*begin_list = next;
; 			else
; 				prev->next = next;
; 		}
; 		else
; 			prev = node;
; 		node = next;
; 	}
; }





