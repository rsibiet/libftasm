; proto: rax	ft_tolower(rdi)

section .text
	global _ft_tolower

_ft_tolower:
	mov rax, rdi
	cmp rdi, 'A'
	jae _less_than
	jmp _exit

_less_than:
	cmp rdi, 'Z'
	jna _change_ret
	ret

_change_ret:
	add rax, 32

_exit:
	ret
