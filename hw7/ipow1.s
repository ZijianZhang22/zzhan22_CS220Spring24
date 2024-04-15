.arch armv8-a

.global ipow

.text
.align 2

//ipow: 计算 x 的 y 次幂
ipow:
    // 函数入口，保存帧指针和链接寄存器到栈上
    stp x29, x30, [sp, #-16]!

    // 检查 y 是否为 0
    cbz x1, base_case

    // 递归计算 x^(y/2)
    asr x1, x1, #1        // y = y / 2
    bl ipow                // 递归调用 ipow 计算 x^(y/2)

    // 结果存储在 x0 中，现在计算 x^y = (x^(y/2)) * (x^(y/2))
    mul x0, x0, x0         // 计算 x^(y/2) * x^(y/2)

    // 检查 y 是否为奇数
    tst x1, #1
    b.ne multiply_x        // 如果 y 为奇数，需要额外乘以 x

    // 函数返回前恢复栈
    ldp x29, x30, [sp], #16
    ret

base_case:
    // 基本情况：y 等于 0，返回 1
    mov x0, #1             // 将结果 1 存储在 x0 中

    // 函数返回前恢复栈
    ldp x29, x30, [sp], #16
    ret

multiply_x:
    // 如果 y 是奇数，再乘以 x
    mul x0, x0, x2         // 计算 x^y = (x^(y/2) * x^(y/2)) * x

    // 函数返回前恢复栈
    ldp x29, x30, [sp], #16
    ret
