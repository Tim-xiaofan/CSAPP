	.file	"main.c"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	pushq	%rbp # 保存调用者栈帧基址
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, -4(%rbp)
	movl	$1, -8(%rbp)
	movl	-4(%rbp), %eax # 设置局部变量a为0
	cmpl	-8(%rbp), %eax # 设置局部变量b为1
	jne	.L2 # 不相等则跳转
	addl	$1, -4(%rbp)
	jmp	.L1
.L2:
	addl	$1, -8(%rbp)
.L1:
	popq	%rbp # 恢复调用者栈基址
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
