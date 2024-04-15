.global fib

fib:
    // 函数开头
    cmp x0, #1          // 检查输入参数是否为1
    b.le factorial_end  // 如果输入参数 <= 1，跳转到结束

    // 递归调用
    sub sp, sp, #16     // 分配栈空间
    str x0, [sp]        // 保存输入参数 n
    sub x0, x0, #1      // 计算 n - 1
    bl fib        // 递归调用 factorial(n - 1)
    ldr x1, [sp]        // 恢复保存的 n
    add sp, sp, #16     // 恢复栈空间

    // 计算阶乘
    mul x0, x1, x0      // x0 = n * factorial(n - 1)

factorial_end:
    ret

