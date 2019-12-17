	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_vfprintf            ## -- Begin function ft_vfprintf
	.p2align	4, 0x90
_ft_vfprintf:                           ## @ft_vfprintf
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r14
	push	rbx
	.cfi_offset rbx, -32
	.cfi_offset r14, -24
	mov	r14, rdi
	mov	rdi, rsi
	mov	rsi, rdx
	call	_internal_vprintf
	mov	ebx, eax
	test	eax, eax
	je	LBB0_2
## %bb.1:
	mov	rax, qword ptr [rip + _g_buf@GOTPCREL]
	mov	rdi, qword ptr [rax]
	mov	rax, qword ptr [rip + _g_buf_i@GOTPCREL]
	mov	rdx, qword ptr [rax]
	mov	esi, 1
	mov	rcx, r14
	call	_fwrite
LBB0_2:
	mov	rdi, qword ptr [rip + _g_buf@GOTPCREL]
	call	_ft_strdel
	mov	eax, ebx
	pop	rbx
	pop	r14
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
