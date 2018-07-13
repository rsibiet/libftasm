; proto: void	ft_cat(int fd)
; --> 	 		ft_cat(rdi)
; read: 3 { user_ssize_t read(int fd, user_addr_t cbuf, user_size_t nbyte); }
; -->		rax				  rdi	  rsi				rdx
; write: 4 { user_ssize_t write(int fd, user_addr_t cbuf, user_size_t nbyte); } 


%define MACH_SYSCALL(nb)	0x2000000 | nb
%define STDOUT				1
%define READ				3
%define WRITE				4
%assign BUFSIZE				0x2000

section .bss
	buffer	resb	BUFSIZE

section .text
	global _ft_cat

_ft_cat:
	push rbp
	mov rbp, rsp

_read_fd:
	lea		rsi, [rel buffer]
	mov 	rdx, BUFSIZE
	mov 	rax, MACH_SYSCALL(READ)
	syscall
	jc		_exit
	cmp 	rax, 0
	jle		_exit
	push 	rdi
	mov 	rdi, STDOUT
	mov 	rdx, rax
	mov 	rax, MACH_SYSCALL(WRITE)
	syscall
	cmp 	rax, -1
	je 		_exit
	pop 	rdi
	jmp 	_read_fd

_exit:
	leave
	mov		rax, 0
	ret