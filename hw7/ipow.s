.arch armv8-a
.global ipow

.text
.align 2

ipow:
    mov x3,x0
    stp x29, x30, [sp, #-16]!   // save lr sp
    mov x29, sp
    // check if  y = 0
    cbz x1, base_case

    // check if y is odd
    lsr x2, x1,#1
    lsl x2, x2,#1
    cmp x1,x2
    bne odd_case

    // the situation y is even
    lsr x1, x1, #1
    bl ipow
    mul x0, x0, x0
    b end

odd_case:
    // situation y is odd
    sub x1, x1, #1
    bl ipow
    mul x0, x0, x3   // x0 中保存了递归调用的结果，与 x2 相乘得到 x^y
    b end

base_case:
    // base case
    mov x0, #1
    b end
end:
    ldp x29, x30, [sp], #16   // reset our lr and sp
    ret
