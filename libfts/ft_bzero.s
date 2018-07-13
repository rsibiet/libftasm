; proto: ft_bzero(rdi, rsi)

section .text
	global _ft_bzero

_ft_bzero:
	cmp rsi, 1
	jl  _exit
	cmp rdi, BYTE 0x0
	je _exit
	mov [rdi], BYTE 0x00
	inc rdi
	dec rsi
	jmp  _ft_bzero

_exit:
	ret
