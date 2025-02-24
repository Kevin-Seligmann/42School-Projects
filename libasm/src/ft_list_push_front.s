; void	ft_list_push_front(t_list **begin_list, void *data)

%include "ft_list.h"

section .text
extern malloc
global ft_list_push_front
ft_list_push_front:

    cmp rdi, 0
    je .return

    mov r15, rdi ; Address of an address of a s_list
    mov r14, rsi ; Address representing any data

    mov rdi, 16 ; Size of two pointers (s_list)
    call [rel malloc wrt ..got]
    cmp rax, 0
    je .return

    ; Moves the data into the new node
    mov [rax + s_list.data], r14

    ; Moves the address of the previous first node, to the new node
    mov r13, [r15]
    mov [rax + s_list.next], r13

    ; Moves the new node to * (**begin_list)
    mov [r15], rax

.return:
    ret
