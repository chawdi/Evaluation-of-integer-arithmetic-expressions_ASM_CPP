; nasm -f elf64 name.asm
; ld -o name name.o
; lab 1, variant 18: (c*149+b*b)/(a+b-117)

section .data
extern a, b, c, num, denom, result

section .text
global calculate_asm

calculate_asm:
	mov al, 149 ; al = 149
	imul byte [c] ; ax = c*149

	mov cx, ax ; save ax in cx
	
	mov al, [b] ; al = b
	imul al ; ax = b*b
	
	add ax, cx ; ax = b*b + c*149
	mov [num], ax
	
	mov bl, [a]
	add bl, [b]
	sub bl, 117 ; bl = a + b - 117
	mov [denom], bl ; save denominator

	idiv bl ; divide ax by bl; al = result
	mov [result], al
	
	ret ; ret returns to main()
