; proto: ft_strlen(rdi)

section .text
	global _ft_strlen

_ft_strlen:
	mov  al, 0					;Byte to search for (NUL)
	mov  rcx, -1				;Start count at FFFFh
	cld							;Increment DI after each character
	repne scasb					;Scan string for NUL, decrementing RCX for each char
    mov  rax, -2				;RCX will be -2 for length 0, -3 for length 1, ...
    sub  rax, rcx				;Length in RAX
	ret