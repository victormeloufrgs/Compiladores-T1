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
# TAC_MULT
	movss	_2.5(%rip), %xmm0
	mulss	_2.5(%rip), %xmm0
	movss	%xmm0, _1temp_0(%rip)
# TAC_PRINT_NOT_LIT_FLOAT
	leaq	printfloatstr(%rip), %rdi
	cvtss2sd	%xmm0, %xmm0
	movb	$1, %al
	callq	_printf
# TAC_FEND
	popq	%rbp
	retq
	.cfi_endproc
# TAC_FBEGIN
_mfunction:
	.cfi_startproc
	pushq %rbp
	movq	%rsp, %rbp
# TAC_RET
	movss	_5.2(%rip), %xmm0
# TAC_FEND
	popq	%rbp
	retq
	.cfi_endproc
# DATA SECTION
	.section	__DATA,__data

_0:	.long	0
_1:	.long	1
_5.2:	.long	1084489728
_2.5:	.long	1075052544
_1temp_0:	.long	0
L_.str.0: .asciz	"\n"
