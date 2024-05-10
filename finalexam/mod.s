arch armv8-a

.global mod

.text
.align 2

mod:
	mov x2, x0
	udiv x3,x2,x1
	mul x3,x1,x3
	sub x0, x2,x3
	ret
