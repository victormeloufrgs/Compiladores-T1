## FIXED INIT
	.section	__TEXT,__cstring,cstring_literals
	printintstr: .asciz	"%d\n"
	printstringstr: .asciz	"%s\n"

	.section	__TEXT,__text,regular,pure_instructions
## TAC_FBEGIN
	.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp
## TAC_PRINTINT
	leaq	printintstr(%rip), %rdi
	movl	_1temp_1(%rip), %esi
	movb	$0, %al
	callq	_printf
## TAC_FEND
	popq	%rbp
	retq
## DATA SECTION
	.section	__DATA,__data

_1temp_0:	.long	0
_1temp_1:	.long	0
