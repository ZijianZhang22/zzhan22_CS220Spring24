.arch armv8-a

.global ipow

.text
.align 2
ipow:
stp fp, lr, [sp, -16]! // save frame pointer and lr in stack
mov fp, sp // create new stack frame
str x19, [sp, -16]! // push x19 on stack
adds x2, x0, x1 // test if both x and y are 0
beq return1 // if so, return 1
cmp x0, 0 // if x == 0
beq return0 // return 0
cmp x1, 0 // if y < 0
bge else1
return0:
mov x2, 0 // return 0
b powerEnd
else1:
cmp x1, 0 // if y == 0
bne else2
return1:
mov x2, 1 // return 1
b powerEnd
else2:
mov x19, x0 // save x in x19
sub x1, x1, 1 // calculate y - 1
bl ipow // recurse power(x, y - 1)
mul x2, x2, x19 // multiply x * power(x, y - 1)
powerEnd:
ldr x19, [sp], 16 // pop x19 from stack
ldp fp, lr, [sp], 16 // restore frame pointer and lr from stack
ret
