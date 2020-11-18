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
# TAC_ARG
	movl	_2(%rip), %eax
	movl	%eax, _b(%rip)
# TAC_ARG
	movl	_3(%rip), %eax
	movl	%eax, _a(%rip)
# TAC_FCALL
	callq	_mfunction
# TAC_PRINT
	movl	_1temp_0(%rip), %esi
	leaq	L_.str.0(%rip), %rdi
	callq	_printf
# TAC_RET
	movl	_1(%rip), %eax
# TAC_FEND
	popq	%rbp
	retq
	.cfi_endproc
# TAC_FBEGIN
_mfunction:
	.cfi_startproc
	pushq %rbp
	movq	%rsp, %rbp
# TAC_ADD
	movl	_a(%rip), %eax
	addl	_4(%rip), %eax
	movl	%eax, _1temp_0(%rip)
# TAC_RET
	movl	_1temp_0(%rip), %eax
# TAC_FEND
	popq	%rbp
	retq
	.cfi_endproc
# DATA SECTION
	.section	__DATA,__data

_4:	.long	4
_3:	.long	3
_2:	.long	2
_0:	.long	0
_1:	.long	1
_1temp_0:	.long	0
_d:	.long	0
L_.str.0: .asciz	"%d\n"
_a: .long	0
_b: .long	0
