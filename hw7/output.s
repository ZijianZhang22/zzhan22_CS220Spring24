	.arch armv8-a
	.file	"ipow.c"
	.text
	.align	2
	.global	ipow
	.type	ipow, %function
ipow:
.LFB0:
	.cfi_startproc
	stp	x29, x30, [sp, -48]!
	.cfi_def_cfa_offset 48
	.cfi_offset 29, -48
	.cfi_offset 30, -40
	mov	x29, sp
	str	x19, [sp, 16]
	.cfi_offset 19, -32
	str	x0, [sp, 40]
	str	x1, [sp, 32]
	ldr	x0, [sp, 32]
	cmp	x0, 0
	bne	.L2
	mov	x0, 1
	b	.L1
.L2:
	ldr	x0, [sp, 32]
	and	x0, x0, 1
	cmp	x0, 0
	bne	.L4
	ldr	x0, [sp, 32]
	lsr	x1, x0, 63
	add	x0, x1, x0
	asr	x0, x0, 1
	mov	x1, x0
	ldr	x0, [sp, 40]
	bl	ipow
	mov	x19, x0
	ldr	x0, [sp, 32]
	lsr	x1, x0, 63
	add	x0, x1, x0
	asr	x0, x0, 1
	mov	x1, x0
	ldr	x0, [sp, 40]
	bl	ipow
	mul	x0, x19, x0
	b	.L1
.L4:
	ldr	x0, [sp, 32]
	cmp	x0, 0
	and	x0, x0, 1
	csneg	x0, x0, x0, ge
	cmp	x0, 1
	bne	.L5
	ldr	x0, [sp, 32]
	sub	x0, x0, #1
	mov	x1, x0
	ldr	x0, [sp, 40]
	bl	ipow
	mov	x1, x0
	ldr	x0, [sp, 40]
	mul	x0, x1, x0
	b	.L1
.L5:
.L1:
	ldr	x19, [sp, 16]
	ldp	x29, x30, [sp], 48
	.cfi_restore 30
	.cfi_restore 29
	.cfi_restore 19
	.cfi_def_cfa_offset 0
	ret
	.cfi_endproc
.LFE0:
	.size	ipow, .-ipow
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
