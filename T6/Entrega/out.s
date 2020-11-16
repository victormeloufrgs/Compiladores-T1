## FIXED INIT
	.section	__TEXT,__cstring,cstring_literals
	printintstr: .asciz	"%d\n"
	printfloatstr: .asciz	"%f\n"
	printstringstr: .asciz	"%s\n"

	.section	__TEXT,__text,regular,pure_instructions
## TAC_FBEGIN
	.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp
## TAC_ADD
	movl	_5(%rip), %eax
	addl	_2(%rip), %eax
	movl	%eax, _1temp_0(%rip)
## TAC_PRINT_INT
	leaq	printintstr(%rip), %rdi
	movl	_1temp_0(%rip), %esi
	movb	$0, %al
	callq	_printf
## TAC_SUB
	movl	_5(%rip), %eax
	subl	_2(%rip), %eax
	movl	%eax, _1temp_1(%rip)
## TAC_PRINT_INT
	leaq	printintstr(%rip), %rdi
	movl	_1temp_1(%rip), %esi
	movb	$0, %al
	callq	_printf
## TAC_MUL
	movl	_5(%rip), %eax
	imull	_2(%rip), %eax
	movl	%eax, _1temp_2(%rip)
## TAC_PRINT_INT
	leaq	printintstr(%rip), %rdi
	movl	_1temp_2(%rip), %esi
	movb	$0, %al
	callq	_printf
## TAC_DIV_FLOAT
	movss	_5.0(%rip), %xmm0
	divss	_2.0(%rip), %xmm0
	cvtss2sd %xmm0, %xmm0
	movss	%xmm0, _1temp_3(%rip)
## TAC_PRINT_FLOAT
	leaq	printfloatstr(%rip), %rdi
	movl	_1temp_3(%rip), %esi
	movb	$1, %al
	callq	_printf
## TAC_FEND
	popq	%rbp
	retq
## DATA SECTION
	.section	__DATA,__data

_2:	.long	2
_5:	.long	5
_0:	.long	0
_1:	.long	1
_10:	.long	16
_2.0:	.long	1073741824
_5.0:	.long	1084227584
_1temp_0:	.long	0
_1temp_1:	.long	0
_1temp_2:	.long	0
_1temp_3:	.long	0
_f:	.long	16
