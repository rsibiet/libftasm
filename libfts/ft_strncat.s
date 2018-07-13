; proto: rax	ft_strncat(rdi, rsi, rdx)

section .text
	global _ft_strncat

_ft_strncat:
	push rdi

_ncat:
	mov	rcx, 0
	cmp BYTE[rdi], 0x0
	je  _cat_rsi
	inc rdi
	jmp  _ncat

_cat_rsi:
	cmp rdx, rcx
	je _return
	cmp BYTE[rsi], 0x0
	je _exit
	movsb
	add rcx, 1
	jmp _cat_rsi

_return:
	mov BYTE[rdi], 0x0

_exit:
	pop rax
	ret
