; proto: rax	ft_strcat(rdi, rsi)

section .text
	global _ft_strcat

_ft_strcat:
	push rdi

_cat:
	cmp BYTE[rdi], 0x0
	je  _cat_rsi
	inc rdi
	jmp  _cat

_cat_rsi:
	cmp BYTE[rsi], 0x0
	je  _exit
	movsb
	jmp  _cat_rsi

_exit:
	mov BYTE[rdi], 0x0
	pop rax
	ret
