; proto: rax	ft_memalloc(rdi)
; proto: 		ft_bzero(rdi, rsi)

section .text
	global _ft_memalloc
	extern _malloc
	extern _ft_bzero

_ft_memalloc:
	push	rdi
	call	_malloc
	cmp 	rax, 0
	je		_exit		 ; return null if malloc failed
	pop		rdi
	mov		rsi, rdi
	mov		rdi, rax
	push	rdi
	call	_ft_bzero

_exit:
	pop		rdi
	ret
