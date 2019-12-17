	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_internal_vprintf       ## -- Begin function internal_vprintf
	.p2align	4, 0x90
_internal_vprintf:                      ## @internal_vprintf
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r15
	push	r14
	push	r12
	push	rbx
	.cfi_offset rbx, -48
	.cfi_offset r12, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	mov	r14, rsi
	mov	r15, rdi
	call	_refresh_all_global_data
	mov	bl, 1
	mov	r12, qword ptr [rip + _g_fmt_i@GOTPCREL]
	.p2align	4, 0x90
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [r12]
	lea	rcx, [rax + 1]
	mov	qword ptr [r12], rcx
	movzx	eax, byte ptr [r15 + rax + 1]
	cmp	al, 37
	je	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	test	al, al
	je	LBB0_7
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movsx	edi, al
	call	__Z13pf_put_ch_bufc
	test	bl, 1
	jne	LBB0_1
	jmp	LBB0_8
	.p2align	4, 0x90
LBB0_4:                                 ##   in Loop: Header=BB0_1 Depth=1
	mov	rdi, r15
	call	_pf_flag_parser
	test	al, al
	je	LBB0_8
## %bb.5:                               ##   in Loop: Header=BB0_1 Depth=1
	mov	rdi, r14
	call	_pf_get_processing_func
	mov	ebx, eax
	test	bl, 1
	jne	LBB0_1
LBB0_8:
	xor	eax, eax
	jmp	LBB0_9
LBB0_7:
	mov	rax, qword ptr [rip + _g_buf_i@GOTPCREL]
	mov	eax, dword ptr [rax]
LBB0_9:
	pop	rbx
	pop	r12
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
