; proto: rax	ft_puts(rdi)

%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

section .data
null:
	.string db "(null)"
	.len equ $ - null.string

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	cmp rdi, 0x0
	je _is_null
	push rdi
	call _ft_strlen
	mov rdx, rax
	pop rsi
	mov rdi, STDOUT
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	jmp _exit

_is_null:
	mov rdi, STDOUT
	lea rsi, [rel null.string]
	mov rdx, null.len
	mov rax, MACH_SYSCALL(WRITE)
	syscall

_exit:
	push 10
	mov rsi, rsp
	mov rdi, STDOUT
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rax
	ret
