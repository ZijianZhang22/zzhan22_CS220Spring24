.arch armv8-a

.global digit_freq

.text
.align 2

digit_freq:
    mov x5,#0
    bl clear
    mov x2,#5
    mov x3, #8
    str x2, [x1]

clear:
    cmp x5,#10
    beq digit_freq
    lsl x4, x5,#3
    mov x4,#0
    str x4,[x1]
    add x1, x4,x1
    add x5,x5,#1
    bl  clear
