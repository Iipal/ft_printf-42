	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_vprintf             ## -- Begin function ft_vprintf
	.p2align	4, 0x90
_ft_vprintf:                            ## @ft_vprintf
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	rax, rsi
	mov	rcx, rdi
	mov	edi, 1
	mov	rsi, rcx
	mov	rdx, rax
	pop	rbp
	jmp	_ft_vdprintf            ## TAILCALL
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
