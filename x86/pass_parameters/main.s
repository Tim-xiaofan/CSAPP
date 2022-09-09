	.file	"main.c"
	.text
	.globl	fun1
	.type	fun1, @function
fun1:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp) # 取参数1
	movl	%esi, -24(%rbp) # 取参数2
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movl	%r9d, -40(%rbp)
	movl	$10, -4(%rbp) # 赋值c
	movl	-24(%rbp), %eax
	movl	-20(%rbp), %edx
	addl	%eax, %edx # 加2
	movl	-28(%rbp), %eax
	addl	%eax, %edx # 加3
	movl	-32(%rbp), %eax
	addl	%eax, %edx # 加4
	movl	-36(%rbp), %eax
	addl	%eax, %edx # 加5
	movl	-40(%rbp), %eax
	addl	%eax, %edx # 加6
	movl	16(%rbp), %eax
	addl	%eax, %edx # 加7
	movl	24(%rbp), %eax
	addl	%eax, %edx # 加8
	movl	-4(%rbp), %eax
	addl	%edx, %eax # 加c
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fun1, .-fun1
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$8, 8(%rsp) # 参数8
	movl	$7, (%rsp)
	movl	$6, %r9d
	movl	$5, %r8d
	movl	$4, %ecx
	movl	$3, %edx
	movl	$2, %esi
	movl	$1, %edi #  参数1
	call	fun1
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
