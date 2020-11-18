	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15, 6	sdk_version 10, 15, 6
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2               ## -- Begin function ff
LCPI0_0:
	.long	1069547520              ## float 1.5
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_ff
	.p2align	4, 0x90
_ff:                                    ## @ff
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movss	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
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
	subq	$16, %rsp
	movss	_d(%rip), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -4(%rbp)         ## 4-byte Spill
	callq	_ff
	movss	-4(%rbp), %xmm1         ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	divss	%xmm0, %xmm1
	cvtss2sd	%xmm1, %xmm0
	leaq	L_.str(%rip), %rdi
	movb	$1, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%ecx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_d                      ## @d
	.p2align	2
_d:
	.long	1067030938              ## float 1.20000005

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%f"

.subsections_via_symbols
