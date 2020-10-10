section	.text
global	_ft_strlen

_ft_strlen:
			push		r8						; we should save any additional registers, that we will use in our program
			push		rcx

			mov			r8, rdi					; r8 = rdi (saving start if string)
			xor			al, al					; sacsb uses al as the byte that will be compared, setting it to is zero - end of string (equal to mov al, 0)
			mov			rcx, 0xffffffffffffffff	; the maximum number of repeats or bytes that will be scanned before stopping REPNE (maximal number in lu)
			repne		scasb					; while [rdi] != al, keep scanning
			sub			rdi, r8					; length = dist2 - dist1 (substraction of saved and rewinded pointers)
			cmp			rdi, 0xffffffffffffffff
			je			return
			dec			rdi						; scasb putted rdi to the index of string end, so we need to decrease index to the last char
return:			
			mov			rax, rdi				; rax - returning register, putting resulting length there
			mov			rdi, r8					; recover rdi of changes made

			pop			rcx						; restore the values of saved registers
			pop			r8

			ret									; return resulting length from rax
			