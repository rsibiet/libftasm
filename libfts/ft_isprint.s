; proto: rax	ft_isprint(rdi)

section .text
	global _ft_isprint

_ft_isprint:
	mov rax, 0
	cmp rdi, 32
	jae _less_than
	jmp _exit

_less_than:
	cmp rdi, 126
	jna _change_ret
	ret

_change_ret:
	mov rax, 1

_exit:
	ret
