.arch armv8-a

.global dow

.text
.align 2

dow:
    mov x20, #14
    sub x3,x20,x0   // part for y0
    mov x20,#4
    mov x4,#12
    udiv x3, x3, x4
    sub x3, x2, x3

    mov x4, x3      //part for x
    udiv x5, x4,x20
    mov x20,#100
    udiv x6, x4,x20
    mov x20,#400
    udiv x7, x4, x20
    add x4,x4,x5
    add x4,x4,x7
    sub x4,x4,x6
		    //part for m0
    mov x20,#14
    sub x8,x20,x0
    mov x20,#12
    udiv x8,x8,x20
    mul x8,x8,x20
    add x8,x8,x0
    mov x20,#2
    sub x8,x8,x20
		    // part for d0
    mov x20, #31
    mul x9,x8,x20
    mov x20,#12
    udiv x9,x9,x20
    add x9,x9,x4
    add x9,x9,x1
    mov x20,#7
    udiv x10,x9,x20
    mul x11, x10,x20
    sub x12, x9,x11
		   // part for return
    mov x0,x12
    ret
