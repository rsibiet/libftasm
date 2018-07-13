; proto: void	ft_putchar(rdi)
; write: 4 { user_ssize_t write(int fd, user_addr_t cbuf, user_size_t nbyte); } 
; -->		rax				  rdi	  rsi				rdx


%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define WRITE				4

section .text
	global _ft_putchar

_ft_putchar:
    push rbp
    mov rbp, rsp
	push rdi
	lea rsi, [rel rsp]
	mov rdi, STDOUT
	mov rdx, 1
	mov rax, MACH_SYSCALL(WRITE)
	syscall

_exit:
	leave
	ret
