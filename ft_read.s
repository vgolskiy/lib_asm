section	.text
global	_ft_read
extern	___error

_ft_read:
			mov			rax, 0x02000003	; system call for read
			syscall						; invoke operating system to do the read
			jc			error			; rax overflow verification (ALL addresses that correspond to negative integers in x86_64 are reserved for the kernel or invalid -- user addresses will always be in the range 0..247-1. So for x86_64 you need only check the sign bit (top bit) of rax)
			ret
error:
			push		rax				; send error code to external function (__error)
			call		___error		; call for external function
			pop			rdx				; getting error number
			mov			[rax], rdx		; put error number to the output
			mov			rax, -1
			ret