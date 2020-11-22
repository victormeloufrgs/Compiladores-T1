## FIXED INIT
	.section	__TEXT,__cstring,cstring_literals
	printintstr: .asciz	"%d\n"
	printfloatstr: .asciz	"%f\n"
	printstringstr: .asciz	"%s\n"

	.section	__TEXT,__text,regular,pure_instructions
.globl _main
# TAC_FBEGIN
_main:
	.cfi_startproc
	pushq %rbp
	movq	%rsp, %rbp
# TAC_FEND
	popq	%rbp
	retq
	.cfi_endproc
# DATA SECTION
	.section	__DATA,__data

_0:	.long	0
_1:	.long	1
