section	.text
global	_ft_strcpy

_ft_strcpy:
			xor		rax, rax			; initializing rax with 0
while:
			mov		cl, [rsi + rax]		; moving byte by byte from rsi to rdi using buffer
			mov		[rdi + rax], cl		; changing pointer using rax as a counter and index
			test	cl, cl				; verifies if cl is 0 byte
			je		return				; returning string if made full copy
			inc		rax					; incrementing counter while not the end of string
			jmp		while				; starting while section from the begining
return:
			lea		rax, [rdi]			; returning string to the output
			ret