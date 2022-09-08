	.file	"main.c"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	addl	$1, -4(%rbp)
.L2:
	cmpl	$99, -4(%rbp)
	jle	.L3
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.globl	foo1
	.type	foo1, @function
foo1:
.LFB1:
	.cfi_startproc
	pushq	%rbp # 保存调用者栈基址
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp # 令栈指针指向新基址指针
	.cfi_def_cfa_register 6
	movl	$0, -4(%rbp) # 设置局部变量的i的值为0
	jmp	.L5
.L6:
	addl	$1, -4(%rbp)
.L5:
	cmpl	$99, -4(%rbp)
	jle	.L6
	popq	%rbp # 恢复调用者栈基址
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	foo1, .-foo1
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
