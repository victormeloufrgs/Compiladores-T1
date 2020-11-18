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
# TAC_ADD
	movl	_var_14(%rip), %eax
	addl	_var_10(%rip), %eax
	movl	%eax, _1temp_0(%rip)
# TAC_PRINT
	movl	_1temp_0(%rip), %esi
	leaq	L_.str.0(%rip), %rdi
	callq	_printf
# TAC_SUB
	movl	_var_14(%rip), %eax
	subl	_var_10(%rip), %eax
	movl	%eax, _1temp_1(%rip)
# TAC_PRINT
	movl	_1temp_1(%rip), %esi
	leaq	L_.str.1(%rip), %rdi
	callq	_printf
# TAC_MULT
	movl	_var_14(%rip), %eax
	imull	_var_2(%rip), %eax
	movl	%eax, _1temp_2(%rip)
# TAC_PRINT
	movl	_1temp_2(%rip), %esi
	leaq	L_.str.2(%rip), %rdi
	callq	_printf
# TAC_DIV_INT
	movl	_var_14(%rip), %eax
	cltd
	idivl	_var_2(%rip)
	movl	%eax, _1temp_3(%rip)
# TAC_PRINT
	movl	_1temp_3(%rip), %esi
	leaq	L_.str.3(%rip), %rdi
	callq	_printf
# TAC_FEND
	popq	%rbp
	retq
	.cfi_endproc
# DATA SECTION
	.section	__DATA,__data

_2:	.long	2
_E:	.long	14
_A:	.long	10
_0:	.long	0
_1:	.long	1
_1temp_0:	.long	0
_1temp_1:	.long	0
_1temp_2:	.long	0
_1temp_3:	.long	0
_var_10:	.long	10
_var_14:	.long	14
_var_2:	.long	2
L_.str.0: .asciz	"%d\n"
L_.str.1: .asciz	"%d\n"
L_.str.2: .asciz	"%d\n"
L_.str.3: .asciz	"%d\n"
