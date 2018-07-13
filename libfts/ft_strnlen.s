; proto: rax	ft_strnlen(rdi, rsi)

section .text
	global _ft_strnlen
	extern _ft_strlen

_ft_strnlen:
	call _ft_strlen
	cmp rax, rsi
	jle _exit
	mov rax, rsi

_exit:
	ret
