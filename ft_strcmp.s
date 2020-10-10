section	.text
global	_ft_strcmp

_ft_strcmp: 
			xor		rax, rax			; initializing rax with 0
			xor		cl, cl				; initializing al with 0
			jz		while				; always true
increment:		
			inc		rax					; increment counter to place pointer to the next character
while:		
			mov		cl, [rsi + rax]		; moving byte by byte from rsi to al
			cmp		cl, [rdi + rax]		; compare characters
			jg		greater				; jump greater
			jl		less				; jump less
			and		cl, [rdi + rax]		; end of strings verification
			jnz		increment			; jump to increment while not the end of strings
			xor		rax, rax			; return 0 in case of equal / end of strings
			ret
greater:		
			mov		rax, -1				; return -1 in case of string2 is greater than string1
			ret
less:		
			mov		rax, 1				; return 1 in case of string2 is less than string1
			ret
