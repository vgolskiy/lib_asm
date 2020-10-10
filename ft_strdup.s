section	.text
global	_ft_strdup
extern	_ft_strlen
extern	_ft_strcpy
extern	_malloc

_ft_strdup:
			push	rsi				; we should save any additional registers, that we will use in our program

			push	rdi				; send rdi to _ft_strlen
			call	_ft_strlen		; rax gets length of duplicating string
			inc		rax				; incrementing rax to place closing 0
			mov		rdi, rax		; length - argument for malloc (char size is 1 byte, so needed memory size = number of characters)
			call	_malloc			; memory allocation
			test	rax, rax		; in case of memory was not allocated rax = 0
			jz		error			; jump in case of zero to return
			lea		rdi, [rax]		; the first argument for strcpy
			pop		rsi				; the second argument for strcpy - return rdi from stack
			call	_ft_strcpy		; copying string to new memory location

error:
			pop		rsi				; return rsi value from stack
			ret

