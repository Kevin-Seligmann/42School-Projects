; int	ft_atoi_base(char *str, char *base)
; \f\t\n\v\r

section .data
	invalid_base_chars db " +-", 0
	space_chars db " ", 0
	plus_and_minus db "+-", 0

section .text


; input
; str = rdi
; base = rsi

; local

; r11 = size, base length
; r12 = char *str
; r13 = char *base
; r14 = index.
; r15 = sign (-1 or 1)

; r9 = adding aux.
; r10 = partial answer.
global ft_atoi_base
ft_atoi_base:
	; Null protection
	cmp rdi, 0
	je .return_zero
	cmp rsi, 0
	je .return_zero

	; Saving input in callee-save registers
	mov r12, rdi
	mov r13, rsi

	; Checks if the base is valid (eg. not repeated characters).
	mov rdi, r13 ; give base as argument
	call valid_base
	cmp rax, 0
	je .return_zero ; if == 0 (invalid). Return 0.

	; A valid base must have length greater than 2.
	mov rdi, r13
	call base_len
	cmp rax, 1
	jle .return_zero ; If <= 1. Return 0.
	mov r11, rax; Storing the size of the base.

	; Spaces must be skipped
	mov r14, 0 ; ind1 = 0
	lea rdi, [rel space_chars] ; To call on the loop (Arg 1 of strsrearch)
.skip_spaces_loop:
	movsx rsi, byte [r12 + r14]
	call pos_strsearch ; if (str[ind] == any spaces)
	cmp rax, 0 ; if < 0. (Not Found) jump to the end.
	js .skip_spaces_loop_end
	inc r14
	jmp .skip_spaces_loop
.skip_spaces_loop_end:

	; + and - should be skipped. If a - is found, flip sign.
	mov r15, 1 ; sign = 1.
	lea rdi, [rel plus_and_minus] ; To call on the loop (Arg 1 of strsrearch)
.skip_sign_loop:
	movsx rsi, byte [r12 + r14]
	call pos_strsearch ; if (str[ind] == + or -)
	cmp rax, 0 ; if < 0. (Not Found) jump to the end.
	js .skip_sign_loop_end
	cmp byte [r12 + r14], '-' ; If str[ind1] == '-'; Should flip the sign.
	je .flip_sign
	.sign_flipped:
	inc r14
	jmp .skip_sign_loop
.skip_sign_loop_end:

	; Lastly, the final value should be calculated
	mov rdi, r13 ; arg1 of strsearch = base.
	mov r10, 0 ; answer = 0
.add_loop_start:
	movsx rsi, byte [r12 + r14]; arg2 of strsearch = str[ind]
	call pos_strsearch ; rax will be the position of the char in the base (The actual value of the char on that base)
	cmp rax, 0; If no more base's characters found, ends.
	js .add_loop_end
	mov r9, r10 ; aux = answer
	imul r9, r11; aux = answer * size
	add r9, rax ; aux = answer * size + pos_in_base(base, str[ind])
	mov r10, r9 ; ans = ans * size + pos_in_base(str[ind], base); This is equivalent, for example, to 42 = 40 * 10 + 2.
	; calculate ans * size, add pos in base. Add that to answer
	inc r14
	jmp .add_loop_start
.add_loop_end:
	imul r10, r15 ; Multiplying result by sign.
	movsx rax, r10d ; return = answer; (return an int). Move with sign.
	ret

.return_zero:
	mov rax, 0
	ret

.flip_sign:
	neg r15
	jmp .sign_flipped

; Checks for invalid (+, -, spaces) or repeated characters.
; rdi = char *
; rax = return (0 = invalid, 1 = valid)

; local:
; r9 = aux for indexing.
; r10 = aux for comparing bytes.
; r11 = base
; r12 = ind1
; r13 = ind2
static valid_base
valid_base:
	; Save in stack
	push r9
	push r10
	push r11
	push r12
	push r13

	mov r11, rdi ; Moved to callee-save register to call strsearch easier
	lea rdi, [rel invalid_base_chars] ; invalid characters = arg2. This will be used later and can be stored here just once.

	mov r12, 0; ind1 = 0
.outer_loop_start: ; Loop characters of base until null.
	cmp byte [r11 + r12], 0 ; base[ind1] == 0 then break.
	je .outer_loop_end

	; If an invalid character is found on the base, returns 0.
	movsx rsi, byte [r11 + r12] ; base[ind1] = arg2 ; arg1 stored.
	call pos_strsearch
	cmp rax, 0 ; if returns > 0, an invalid character has been found.
	jns .invalid

	mov r13, 1; ind2 = 1
	.inner_loop_start: ; Loop characters of base[ind1 + ind2] until null, or a repeated character is found.
		lea r9, [r12 + r13]; Index auxiliar
		mov r10, 0
		mov r10b, byte [r11 + r9]; aux = base[ind1 + ind2]
		cmp r10b, 0 ; if base[ind1 + ind2] == 0, breaks.
		je .inner_loop_end
		cmp r10b, byte [r11 + r12] ; if  base[ind1 + ind2] = base[ind1], returns error
		je .invalid
		inc r13 ; ind2 ++, go back.
		jmp .inner_loop_start
	.inner_loop_end:

	inc r12 ; ind1 ++, go back.
	jmp .outer_loop_start
.outer_loop_end:
	mov rax, 1
	jmp .return
.invalid:
	mov rax, 0
.return:
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	ret

; Given a char and a char *, return the position of the string (0-indexed), or -1 if not found.
; rdi = char *str
; rsi = char c, to find
; rax = return
; r8 = byte auxiliar
static pos_strsearch
pos_strsearch:
	mov rax, 0 ; Init ind
.loop:
	movsx r8, byte [rdi + rax]
	cmp r8, 0 ; if str[ind] == 0, returns invalid.
	je .not_found
	cmp r8, rsi ; if str[ind] == c, returns valid
	je .found
	inc rax ; Jumps to start of loop
	jmp .loop
.not_found: ; Returns -1
	mov rax, -1
.found: ; Returns the counter
	ret

; Calculates length of string.
; rax = return value
; rdi = char* str
static base_len
base_len:
	mov rax, 0; Move 0 to RAX (Counter)
.loop: ; Loops until a char is 0, adding to the counter
	cmp byte [rdi + rax], 0; If RSI (A char * dereferenced) is 0
	jz .end; quit
	inc rax; Increase counter
	jmp .loop ; Jumps to the loop label
.end:
    ret ; Returns
