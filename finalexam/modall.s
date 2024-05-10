.arch armv8-a
.global modall
.align 2
.text
modall:
        mov x3, #0
while:
        cmp x3, x2 // i < n
        bge endwhile
        lsl x4, x3, #3 // offset is i*8 or i << 3
        add x4, x0, x4 // vec +(i*8)
	mov x6,x4
        ldr x4, [x4,#0]// x4 = vec[i]
        udiv x5,x4,x1
        mul x5,x5,x1
        sub x4,x4,x5
	str x4,[x6,#0]
        add x3, x3, #1 // i++
        b while
endwhile:
        ret

