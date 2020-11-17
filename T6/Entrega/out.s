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
## TAC_OR
	movl	_FALSE(%rip), %eax
	movl	_TRUE(%rip), %edx
	orl		 %edx, %eax
	movl	%eax, _1temp_0(%rip)
## TAC_PRINT_INT
	leaq	printintstr(%rip), %rdi
	movl	_1temp_0(%rip), %esi
	movb	$0, %al
	callq	_printf
## TAC_FEND
	popq	%rbp
	retq
## DATA SECTION
	.section	__DATA,__data

_0:	.long	0
_1:	.long	1
_10:	.long	16
_TRUE:	.long	1
_FALSE:	.long	0
_1temp_0:	.long	0
_f:	.long	16
