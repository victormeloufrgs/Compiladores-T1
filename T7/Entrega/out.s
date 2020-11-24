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
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_0(%rip)
# TAC_LABEL
_1label_0:
# TAC_JEQ
	movl	_1temp_0(%rip), %edx
	cmpl	_3(%rip), %edx
	je		_1label_1
# TAC_LE
	movl	_1temp_0(%rip), %edx
	cmpl	_3(%rip), %edx
	jle		_1label_1
# TAC_PRINT
	movl	_1(%rip), %esi
	leaq	L_.str.0(%rip), %rdi
	callq	_printf
# TAC_ADD
	movl	_1temp_0(%rip), %eax
	addl	_10(%rip), %eax
	movl	%eax, _1temp_0(%rip)
# TAC_JUMP
	jmp		_1label_0
# TAC_LABEL
_1label_1:
# TAC_FEND
	popq	%rbp
	retq
	.cfi_endproc
# DATA SECTION
	.section	__DATA,__data

_3:	.long	3
_2:	.long	2
_E:	.long	14
_A:	.long	10
_0:	.long	0
_1:	.long	1
_10:	.long	16
_1temp_0:	.long	0
_var_10:	.long	10
_var_14:	.long	14
_var_2:	.long	2
_i:	.long	1
L_.str.0: .asciz	"%d\n"
