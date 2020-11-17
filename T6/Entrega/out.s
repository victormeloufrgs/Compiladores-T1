## FIXED INIT
	.section	__TEXT,__cstring,cstring_literals
	printintstr: .asciz	"%d\n"
	printfloatstr: .asciz	"%f\n"

	.section	__TEXT,__text,regular,pure_instructions
## TAC_FBEGIN
	.globl	_main
_main:
	pushq	%rbp
	movq	%rsp, %rbp
## TAC_PRINT_STRING
	leaq	_string_5(%rip), %rdi
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
_string_5: .asciz	"Victor\n"
_f:	.long	16
