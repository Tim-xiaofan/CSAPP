	.file	"main.c"
	.comm	my_global_var,4,4
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	pushq	%rbp # 保存原栈基址
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp # 令栈指针指向新的基址
	.cfi_def_cfa_register 6
	movl	$1, -4(%rbp) # 局部变量赋值
	movl	$2, my_global_var(%rip) # 全局变量赋值
	movl	my_global_var(%rip), %eax # 设置返回值
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-16)"
	.section	.note.GNU-stack,"",@progbits
