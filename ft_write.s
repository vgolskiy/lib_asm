section	.text
global	_ft_write
extern	___error

_ft_write:
			mov			rax, 0x02000004	; system call for write
			syscall						; invoke operating system to do the write
			jc			error			; rax overflow verification (ALL addresses that correspond to negative integers in x86_64 are reserved for the kernel or invalid -- user addresses will always be in the range 0..247-1. So for x86_64 you need only check the sign bit (top bit) of rax)
			ret
error:
			push		rax				; send error code to external function (__error)
			call		___error		; call for external function
			pop			rdx				; getting error number
			mov			[rax], rdx		; put error number to the output
			mov			rax, -1
			ret
