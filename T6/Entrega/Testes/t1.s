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
	movss	_a(%rip), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	divss	_b(%rip), %xmm0
	movss	%xmm0, _a(%rip)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_a                      ## @a
	.p2align	2
_a:
	.long	1084227584              ## float 5

	.globl	_b                      ## @b
	.p2align	2
_b:
	.long	1073741824              ## float 2

.subsections_via_symbols
