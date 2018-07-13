; proto: rax	ft_isascii(rdi)

section .text
	global _ft_isascii

_ft_isascii:
	mov rax, 0
	cmp rdi, 0
	jae _less_than
	jmp _exit

_less_than:
	cmp rdi, 127
	jna _change_ret
	ret

_change_ret:
	mov rax, 1

_exit:
	ret
