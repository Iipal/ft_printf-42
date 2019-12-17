	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_pf_decimal             ## -- Begin function pf_decimal
	.p2align	4, 0x90
_pf_decimal:                            ## @pf_decimal
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
	mov	r14, qword ptr [rip + _g_flag_spec_mask@GOTPCREL]
	mov	r15d, dword ptr [r14]
	call	_pf_get_signed_data
	mov	rcx, qword ptr [rip + _g_data_ptr@GOTPCREL]
	mov	qword ptr [rcx], rax
	test	rax, rax
	je	LBB0_1
## %bb.2:
	mov	ebx, r15d
	and	ebx, 2
	mov	rdi, rax
	call	_ft_strlen
	mov	r12, qword ptr [rip + _g_data_len@GOTPCREL]
	mov	qword ptr [r12], rax
	mov	ecx, dword ptr [r14]
	test	cl, 1
	je	LBB0_5
## %bb.3:
	test	ebx, ebx
	jne	LBB0_5
## %bb.4:
	call	__Z14pf_put_str_bufv
	mov	rax, qword ptr [r12]
LBB0_5:
	mov	rcx, qword ptr [rip + _g_flag_width@GOTPCREL]
	mov	rsi, qword ptr [rcx]
	sub	rsi, rax
	jbe	LBB0_7
## %bb.6:
	shl	bl, 3
	or	bl, 32
	movzx	edi, bl
	call	__Z13pf_put_ch_bufcm
LBB0_7:
	test	r15b, 2
	jne	LBB0_9
## %bb.8:
	mov	eax, dword ptr [r14]
	and	eax, 1
	jne	LBB0_10
LBB0_9:
	call	__Z14pf_put_str_bufv
LBB0_10:
	mov	rdi, qword ptr [rip + _g_data_ptr@GOTPCREL]
	call	_ft_strdel
	mov	al, 1
	jmp	LBB0_11
LBB0_1:
	xor	eax, eax
LBB0_11:
                                        ## kill: def $al killed $al killed $eax
	pop	rbx
	pop	r12
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
