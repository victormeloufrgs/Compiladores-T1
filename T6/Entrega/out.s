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
## TAC_FEND
	popq	%rbp
	retq
## DATA SECTION
	.section	__DATA,__data

_b:	.long	0
