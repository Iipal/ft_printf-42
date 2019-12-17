	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_pf_unsigned            ## -- Begin function pf_unsigned
	.p2align	4, 0x90
_pf_unsigned:                           ## @pf_unsigned
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
	mov	esi, 10
	call	_pf_get_unsigned_data
	mov	rcx, qword ptr [rip + _g_data_ptr@GOTPCREL]
	mov	qword ptr [rcx], rax
	mov	rdi, rax
	call	_ft_strlen
	mov	rcx, qword ptr [rip + _g_data_len@GOTPCREL]
	mov	qword ptr [rcx], rax
	mov	r14, qword ptr [rip + _g_flag_spec_mask@GOTPCREL]
	mov	r15d, dword ptr [r14]
	mov	ecx, r15d
	and	ecx, 2
	mov	r12d, ecx
	shl	r12b, 3
	or	r12b, 32
	mov	rdx, qword ptr [rip + _g_flag_width@GOTPCREL]
	mov	rbx, qword ptr [rdx]
	cmp	rbx, rax
	cmovbe	rbx, rax
	sub	rbx, rax
	test	r15b, 1
	je	LBB0_3
## %bb.1:
	test	ecx, ecx
	jne	LBB0_3
## %bb.2:
	call	__Z14pf_put_str_bufv
LBB0_3:
	movzx	edi, r12b
	mov	rsi, rbx
	call	__Z13pf_put_ch_bufcm
	test	r15b, 2
	jne	LBB0_5
## %bb.4:
	mov	eax, dword ptr [r14]
	and	eax, 1
	jne	LBB0_6
LBB0_5:
	call	__Z14pf_put_str_bufv
LBB0_6:
	mov	rdi, qword ptr [rip + _g_data_ptr@GOTPCREL]
	call	_ft_strdel
	mov	al, 1
	pop	rbx
	pop	r12
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
