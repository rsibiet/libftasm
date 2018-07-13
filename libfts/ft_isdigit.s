; proto: rax	ft_isdigit(rdi)

section .text
	global _ft_isdigit

_ft_isdigit:
	mov rax, 0
	cmp rdi, '0'
	jae _less_than_nine
	jmp _exit

_less_than_nine:
	cmp rdi, '9'
	jna _change_ret
	ret

_change_ret:
	mov rax, 1

_exit:
	ret
