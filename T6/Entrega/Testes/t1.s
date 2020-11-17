	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15, 6	sdk_version 10, 15, 6
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	xorl	%eax, %eax

	movb	_b(%rip), %cl
	xorb	$-1, %cl
	andb	$1, %cl
	movb	%cl, _c(%rip)


	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_b                      ## @b
_b:
	.byte	1                       ## 0x1

	.globl	_c                      ## @c
_c:
	.byte	1                       ## 0x1

.subsections_via_symbols
