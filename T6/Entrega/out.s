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
	## TAC_EQ
	movl	_TRUE(%rip), %edx
	cmpl	_TRUE(%rip), %edx
	je		_1label_0
	# TAC_MOVE
	movl	_0(%rip), %eax
	movl	%eax, _1temp_0(%rip)
	## TAC_JUMP
	jmp		_1label_1
	## TAC_LABEL
_1label_0:
	# TAC_MOVE
	movl	_1(%rip), %eax
	movl	%eax, _1temp_0(%rip)
	## TAC_LABEL
_1label_1:
	# TAC_JFALSE
	cmpl	$0, _1temp_0(%rip)
	je		_1label_2
## TAC_PRINT_STRING
	leaq	_string_6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	## TAC_JUMP
	jmp		_1label_3
	## TAC_LABEL
_1label_2:
## TAC_PRINT_STRING
	leaq	_string_7(%rip), %rdi
	movb	$0, %al
	callq	_printf
	## TAC_LABEL
_1label_3:
## TAC_PRINT_STRING
	leaq	_string_8(%rip), %rdi
	movb	$0, %al
	callq	_printf
## TAC_ADD
	movl	_5.2(%rip), %eax
	addl	_3.2(%rip), %eax
	movl	%eax, _1temp_1(%rip)
## TAC_PRINT_FLOAT
	leaq	printfloatstr(%rip), %rdi
	movss	_1temp_1(%rip), %esi
	cvtss2sd	%xmm0, %xmm0
	movb	$1, %al
	callq	_printf
## TAC_FEND
	popq	%rbp
	retq
## DATA SECTION
	.section	__DATA,__data

_0:	.long	0
_1:	.long	1
_3.2:	.long	1078460416
_5.2:	.long	1084489728
_string_8: .asciz	"Concluiu\n"
_string_7: .asciz	"Diferente\n"
_TRUE:	.long	1
_string_6: .asciz	"IGUAL\n"
_FALSE:	.long	0
_1temp_0:	.long	0
_1temp_1:	.long	0
_f:	.long	0
