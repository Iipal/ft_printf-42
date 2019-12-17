	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_vsnprintf           ## -- Begin function ft_vsnprintf
	.p2align	4, 0x90
_ft_vsnprintf:                          ## @ft_vsnprintf
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r15
	push	r14
	push	rbx
	push	rax
	.cfi_offset rbx, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	mov	rbx, rsi
	mov	r14, rdi
	mov	rdi, rdx
	mov	rsi, rcx
	call	_internal_vprintf
	test	eax, eax
	je	LBB0_1
## %bb.2:
	movsxd	rcx, eax
	cmp	rcx, rbx
	cmovb	ebx, eax
	mov	rax, qword ptr [rip + _g_buf@GOTPCREL]
	mov	rsi, qword ptr [rax]
	movsxd	r15, ebx
	mov	rdi, r14
	mov	rdx, r15
	call	_ft_strncpy
	mov	byte ptr [r14 + r15], 0
	jmp	LBB0_3
LBB0_1:
	xor	ebx, ebx
LBB0_3:
	mov	rdi, qword ptr [rip + _g_buf@GOTPCREL]
	call	_ft_strdel
	mov	eax, ebx
	add	rsp, 8
	pop	rbx
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
