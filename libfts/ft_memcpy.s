; proto: rax	ft_memcpy(rdi, rsi, rdx)

section .text
	global _ft_memcpy

_ft_memcpy:
	mov rcx, rdx
	mov rax, rdi

_cpy:
	cmp rdx, 0
	je  _exit
	rep movsb

_exit:
	ret
