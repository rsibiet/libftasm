; proto: rax	ft_abs(rdi)

section .text
	global _ft_abs

_ft_abs:
	mov rax, rdi
	cmp eax, 0
	jnl _exit
	neg rax

_exit:
	ret
