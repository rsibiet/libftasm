; proto: rax	ft_isalnum(rdi)

section .text
	extern   _ft_isalpha
	extern   _ft_isdigit
	global _ft_isalnum

_ft_isalnum:
	mov rax, 0
	call     _ft_isalpha
	cmp rax, 1
	je	_exit
	call     _ft_isdigit

_exit:
	ret
