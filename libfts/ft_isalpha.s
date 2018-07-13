; proto: rax	ft_isalpha(rdi)

section .text
	global _ft_isalpha

_ft_isalpha:
	mov rax, 0
	cmp rdi, 'a'
	jae _islow
	cmp rdi, 'A'
	jae _isup
	jmp _exit

_islow:
	cmp rdi, 'z'
	jna _change_ret
	ret

_isup:
	cmp rdi, 'Z'
	jna _change_ret
	ret

_change_ret:
	mov rax, 1

_exit:
	ret
