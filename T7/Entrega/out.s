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
# TAC_PRINT
	leaq	_string_9(%rip), %rsi
	leaq	L_.str.0(%rip), %rdi
	callq	_printf
# TAC_ADD
	movl	_var_14(%rip), %eax
	addl	_var_10(%rip), %eax
	movl	%eax, _1temp_0(%rip)
# TAC_PRINT
	movl	_1temp_0(%rip), %esi
	leaq	L_.str.1(%rip), %rdi
	callq	_printf
# TAC_SUB
	movl	_var_14(%rip), %eax
	subl	_var_10(%rip), %eax
	movl	%eax, _1temp_1(%rip)
# TAC_PRINT
	movl	_1temp_1(%rip), %esi
	leaq	L_.str.2(%rip), %rdi
	callq	_printf
# TAC_MULT
	movl	_var_14(%rip), %eax
	imull	_var_2(%rip), %eax
	movl	%eax, _1temp_2(%rip)
# TAC_PRINT
	movl	_1temp_2(%rip), %esi
	leaq	L_.str.3(%rip), %rdi
	callq	_printf
# TAC_DIV_INT
	movl	_var_14(%rip), %eax
	cltd
	idivl	_var_2(%rip)
	movl	%eax, _1temp_3(%rip)
# TAC_PRINT
	movl	_1temp_3(%rip), %esi
	leaq	L_.str.4(%rip), %rdi
	callq	_printf
# TAC_PRINT
	leaq	_string_10(%rip), %rsi
	leaq	L_.str.5(%rip), %rdi
	callq	_printf
# TAC_AND
	movl	_TRUE(%rip), %eax
	movl	_TRUE(%rip), %edx
	andl	%edx, %eax
	movl	%eax, _1temp_4(%rip)
# TAC_PRINT
	movl	_1temp_4(%rip), %esi
	leaq	L_.str.6(%rip), %rdi
	callq	_printf
# TAC_AND
	movl	_TRUE(%rip), %eax
	movl	_FALSE(%rip), %edx
	andl	%edx, %eax
	movl	%eax, _1temp_5(%rip)
# TAC_PRINT
	movl	_1temp_5(%rip), %esi
	leaq	L_.str.7(%rip), %rdi
	callq	_printf
# TAC_OR
	movl	_TRUE(%rip), %eax
	movl	_FALSE(%rip), %edx
	orl		 %edx, %eax
	movl	%eax, _1temp_6(%rip)
# TAC_PRINT
	movl	_1temp_6(%rip), %esi
	leaq	L_.str.8(%rip), %rdi
	callq	_printf
# TAC_OR
	movl	_FALSE(%rip), %eax
	movl	_FALSE(%rip), %edx
	orl		 %edx, %eax
	movl	%eax, _1temp_7(%rip)
# TAC_PRINT
	movl	_1temp_7(%rip), %esi
	leaq	L_.str.9(%rip), %rdi
	callq	_printf
# TAC_NOT
	movb	_TRUE(%rip), %cl
	xorb	$-1, %cl
	andb	$1, %cl
	movb	%cl, _1temp_8(%rip)
# TAC_PRINT
	movl	_1temp_8(%rip), %esi
	leaq	L_.str.10(%rip), %rdi
	callq	_printf
# TAC_NOT
	movb	_FALSE(%rip), %cl
	xorb	$-1, %cl
	andb	$1, %cl
	movb	%cl, _1temp_9(%rip)
# TAC_PRINT
	movl	_1temp_9(%rip), %esi
	leaq	L_.str.11(%rip), %rdi
	callq	_printf
# TAC_PRINT
	leaq	_string_13(%rip), %rsi
	leaq	L_.str.12(%rip), %rdi
	callq	_printf
# TAC_GE
	movl	_25(%rip), %edx
	cmpl	_3(%rip), %edx
	jge		_1label_0
# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_10(%rip)
# TAC_JUMP
	jmp		_1label_1
# TAC_LABEL
_1label_0:
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_10(%rip)
# TAC_LABEL
_1label_1:
# TAC_PRINT
	movl	_1temp_10(%rip), %esi
	leaq	L_.str.13(%rip), %rdi
	callq	_printf
# TAC_GT
	movl	_25(%rip), %edx
	cmpl	_3(%rip), %edx
	jg		_1label_2
# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_11(%rip)
# TAC_JUMP
	jmp		_1label_3
# TAC_LABEL
_1label_2:
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_11(%rip)
# TAC_LABEL
_1label_3:
# TAC_PRINT
	movl	_1temp_11(%rip), %esi
	leaq	L_.str.14(%rip), %rdi
	callq	_printf
# TAC_LE
	movl	_25(%rip), %edx
	cmpl	_3(%rip), %edx
	jle		_1label_4
# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_12(%rip)
# TAC_JUMP
	jmp		_1label_5
# TAC_LABEL
_1label_4:
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_12(%rip)
# TAC_LABEL
_1label_5:
# TAC_PRINT
	movl	_1temp_12(%rip), %esi
	leaq	L_.str.15(%rip), %rdi
	callq	_printf
# TAC_LT
	movl	_25(%rip), %edx
	cmpl	_3(%rip), %edx
	jl		_1label_6
# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_13(%rip)
# TAC_JUMP
	jmp		_1label_7
# TAC_LABEL
_1label_6:
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_13(%rip)
# TAC_LABEL
_1label_7:
# TAC_PRINT
	movl	_1temp_13(%rip), %esi
	leaq	L_.str.16(%rip), %rdi
	callq	_printf
# TAC_EQ
	movl	_25(%rip), %edx
	cmpl	_3(%rip), %edx
	je		_1label_8
# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_14(%rip)
# TAC_JUMP
	jmp		_1label_9
# TAC_LABEL
_1label_8:
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_14(%rip)
# TAC_LABEL
_1label_9:
# TAC_PRINT
	movl	_1temp_14(%rip), %esi
	leaq	L_.str.17(%rip), %rdi
	callq	_printf
# TAC_DIF
	movl	_25(%rip), %edx
	cmpl	_3(%rip), %edx
	jne		_1label_10
# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_15(%rip)
# TAC_JUMP
	jmp		_1label_11
# TAC_LABEL
_1label_10:
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_15(%rip)
# TAC_LABEL
_1label_11:
# TAC_PRINT
	movl	_1temp_15(%rip), %esi
	leaq	L_.str.18(%rip), %rdi
	callq	_printf
# TAC_EQ
	movl	_25(%rip), %edx
	cmpl	_25(%rip), %edx
	je		_1label_12
# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_16(%rip)
# TAC_JUMP
	jmp		_1label_13
# TAC_LABEL
_1label_12:
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_16(%rip)
# TAC_LABEL
_1label_13:
# TAC_PRINT
	movl	_1temp_16(%rip), %esi
	leaq	L_.str.19(%rip), %rdi
	callq	_printf
# TAC_DIF
	movl	_25(%rip), %edx
	cmpl	_25(%rip), %edx
	jne		_1label_14
# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_17(%rip)
# TAC_JUMP
	jmp		_1label_15
# TAC_LABEL
_1label_14:
# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_17(%rip)
# TAC_LABEL
_1label_15:
# TAC_PRINT
	movl	_1temp_17(%rip), %esi
	leaq	L_.str.20(%rip), %rdi
	callq	_printf
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
_25:	.long	37
_1temp_10:	.long	0
_1temp_11:	.long	0
_1temp_12:	.long	0
_1temp_13:	.long	0
_1temp_14:	.long	0
_1temp_15:	.long	0
_1temp_16:	.long	0
_1temp_17:	.long	0
_TRUE:	.long	1
_string_9: .asciz	"\nOperações aritméticas:\n"
_FALSE:	.long	0
_string_13: .asciz	"\n Operações relacionais com números: \n"
_1temp_0:	.long	0
_1temp_1:	.long	0
_1temp_2:	.long	0
_1temp_3:	.long	0
_1temp_4:	.long	0
_1temp_5:	.long	0
_1temp_6:	.long	0
_1temp_7:	.long	0
_1temp_8:	.long	0
_1temp_9:	.long	0
_string_10: .asciz	"\nOperações booleanas: \n"
_var_10:	.long	10
_var_14:	.long	14
_var_2:	.long	2
L_.str.0: .asciz	"%s\n"
L_.str.1: .asciz	"%d\n"
L_.str.2: .asciz	"%d\n"
L_.str.3: .asciz	"%d\n"
L_.str.4: .asciz	"%d\n"
L_.str.5: .asciz	"%s\n"
L_.str.6: .asciz	"%d\n"
L_.str.7: .asciz	"%d\n"
L_.str.8: .asciz	"%d\n"
L_.str.9: .asciz	"%d\n"
L_.str.10: .asciz	"%d\n"
L_.str.11: .asciz	"%d\n"
L_.str.12: .asciz	"%s\n"
L_.str.13: .asciz	"%d\n"
L_.str.14: .asciz	"%d\n"
L_.str.15: .asciz	"%d\n"
L_.str.16: .asciz	"%d\n"
L_.str.17: .asciz	"%d\n"
L_.str.18: .asciz	"%d\n"
L_.str.19: .asciz	"%d\n"
L_.str.20: .asciz	"%d\n"
