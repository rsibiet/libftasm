; proto: rax	ft_strchr(rdi, rsi)

section .text
	global _ft_strchr
	extern _ft_strlen

_ft_strchr:
	push rdi
	call _ft_strlen
	cmp rax, 0
	je _exit_null
	mov rcx, rax
	pop rdi

_while:
	cmp [rdi], sil
	je _exit
	inc rdi
	cmp rcx, 0
	je _exit_null
	sub rcx, 1
	jmp _while

_exit_null:
	mov rax, 0
	ret

_exit:
    mov rax, rdi
	ret
