; proto: rax	ft_memset(rdi, rsi, rdx)
; 		 void	*ft_memset(void *b, int c, size_t len)


section .text
	global _ft_memset

_ft_memset:
	push rdi

_mem:
	cmp rdx, 0
	je _exit
	mov rcx, rdx
	mov rax, rsi
	rep stosb

_exit:
	pop rax
	ret
