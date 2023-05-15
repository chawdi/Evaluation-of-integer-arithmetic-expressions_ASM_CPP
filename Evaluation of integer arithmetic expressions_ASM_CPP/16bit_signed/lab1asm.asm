; nasm -f elf64 name.asm
; ld -o name name.o
; lab 1, variant 18: (c*149+b*b)/(a+b-117)

section .data
extern a, b, c, num, denum, result

section .text
global calculate_asm

calculate_asm:
	mov ax, [c]
	imul ax, 149 ; ax = c*149

	mov bx, [b]
	imul bx,bx ; bx = b*b
	add ax,bx ; ax = b*b + c*149
	mov [num], ax
	
	mov cx, [a]
	add cx, [b]
	sub cx, 117 ; cx = a + b - 117
	mov [denum], cx
	
	cwd ; convert ax (word) to dx:ax (dword)
	idiv cx ; divide DX:AX by CX ; now ax = result

	mov [result], ax
	
	ret ; ret returns to main()
