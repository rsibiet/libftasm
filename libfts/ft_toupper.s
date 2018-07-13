; proto: rax	ft_toupper(rdi)

section .text
	global _ft_toupper

_ft_toupper:
	mov rax, rdi
	cmp rdi, 'a'
	jae _less_than
	jmp _exit

_less_than:
	cmp rdi, 'z'
	jna _change_ret
	ret

_change_ret:
	sub rax, 32

_exit:
	ret
