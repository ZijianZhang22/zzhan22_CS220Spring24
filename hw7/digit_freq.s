.arch armv8-a

.global digit_freq

.text
.align 2
// get our stack and set some constants we will use
digit_freq:
    sub sp, sp, #0x20
    str x1, [sp,#8]
    mov x3, #10
    mov x5, #0
    b clear

// the step that make sure the bad thing won't happen!!!!
clear:
    cmp x5,#10
    beq while
    lsl x4, x5,#3
    add x1, x1,x4
    mov x4, #0
    str x4,[x1]
    add x5,x5,#1
    ldr x1,[sp,#8]
    b clear
// the step we find out the freqency
while:
    ldr x1, [sp,#8]
    cmp x0, #0
    beq end
    mov x5, x0
    udiv x4, x0, x3
    udiv x0, x0, x3
    mul x4, x3, x4
    sub x4, x5,x4
    lsl x4, x4, #3
    add x1, x4, x1
    ldr x6, [x1]
    add x6, x6, #1
    str x6, [x1]
    ldr x1, [sp,#8]
    b while
// the end
end:
    add sp,sp,#32
    mov x0,x1
    ret
