.arch armv8-a

.global ipow

.text
.align 2

mov x2, x0
mov x5, #2
ipow:
    stp x29, x30, [sp, #-16]!   // 将 x29 (帧指针) 和 x30 (lr) 压栈，同时更新栈指针
    mov x29, sp
    cmp x1, #0
    beq  base_case// 检查 y 是否为 0
    // 如果 y 是奇数，递归调用自身计算 x^(y-1)      // y = y - 1
    udiv x6, x1,x5
    mul x6, x6,x5
    cmp x6, x1          // 测试 y 的最低位，判断奇偶性
    bne odd_case       // 如果 y 是奇数，跳转到 odd_case 处处理d
    // 如果 y 是偶数，递归调用自身计算 x^(y/2)
    udiv x1, x1, x5   // y = y / 2，右移一位相当于除以 2
    bl ipow          // 递归调用自身计算 x^(y/2)      // 计算 x^y = (x^(y/2)) * (x^(y/2))    // 从栈中弹出并恢复 x29 和 x30，同时更新栈指针
    mul x0, x0, x0
    b end
odd_case:
    sub x1, x1, #1
    bl ipow          // 递归调用自身计算 x^(y-1)      // 计算 x^y = (x^(y-1)) * x    // 从栈中弹出并恢复 x29 和 x30，同时更新栈指针
    mul x0, x0, x2
    b end
base_case:
    // 基本情况：y 为 0，返回 1          // 将结果 1 存储在 x0 
    // 从栈中弹出并恢复 x29 和 x30，同时更新栈指针
    mov x0, #1
    b end

end:
    ldp x29, x30, [sp], #16
    ret

