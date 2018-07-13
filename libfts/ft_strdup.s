; proto: rax	ft_strdup(rdi)
; proto: rax	ft_memcpy(rdi, rsi, rdx)

section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen

_ft_strdup:
    push rbp
    mov rbp, rsp
	push	rbx
	mov 	rbx, rdi		; rbx = src
	call	_ft_strlen
	add		rax, 1
	mov 	rdi, rax
	push	rdi
	call 	_malloc
	pop		rdi
	cmp 	rax, 0 		 ; rax = dest ; rdi = len;
	je		_exit		 ; return null if malloc failed
    mov     rcx, rdi     ; pass len to rcx
    mov     rdi, rax     ; pass dest to rdi
    mov     rsi, rbx     ; pass src to rsi
	rep movsb

_exit:
    leave
	ret
