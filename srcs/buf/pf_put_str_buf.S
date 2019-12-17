	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	__Z14pf_put_str_bufv    ## -- Begin function _Z14pf_put_str_bufv
	.p2align	4, 0x90
__Z14pf_put_str_bufv:                   ## @_Z14pf_put_str_bufv
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
	mov	r14, qword ptr [rip + _g_data_len@GOTPCREL]
	cmp	qword ptr [r14], 0
	je	LBB0_3
## %bb.1:
	xor	ebx, ebx
	mov	r15, qword ptr [rip + _g_data_ptr@GOTPCREL]
	.p2align	4, 0x90
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [r15]
	movsx	edi, byte ptr [rax + rbx]
	call	__Z13pf_put_ch_bufc
	add	rbx, 1
	cmp	qword ptr [r14], rbx
	ja	LBB0_2
LBB0_3:
	add	rsp, 8
	pop	rbx
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__Z14pf_put_str_bufm    ## -- Begin function _Z14pf_put_str_bufm
	.p2align	4, 0x90
__Z14pf_put_str_bufm:                   ## @_Z14pf_put_str_bufm
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
	mov	r14, rdi
	mov	rax, qword ptr [rip + _g_data_len@GOTPCREL]
	mov	rax, qword ptr [rax]
	cmp	rax, rdi
	cmovb	r14, rax
	test	r14, r14
	je	LBB1_3
## %bb.1:
	xor	ebx, ebx
	mov	r15, qword ptr [rip + _g_data_ptr@GOTPCREL]
	.p2align	4, 0x90
LBB1_2:                                 ## =>This Inner Loop Header: Depth=1
	mov	rax, qword ptr [r15]
	movsx	edi, byte ptr [rax + rbx]
	call	__Z13pf_put_ch_bufc
	add	rbx, 1
	cmp	r14, rbx
	ja	LBB1_2
LBB1_3:
	add	rsp, 8
	pop	rbx
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__Z14pf_put_str_bufPKcm ## -- Begin function _Z14pf_put_str_bufPKcm
	.p2align	4, 0x90
__Z14pf_put_str_bufPKcm:                ## @_Z14pf_put_str_bufPKcm
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
	test	rsi, rsi
	je	LBB2_3
## %bb.1:
	mov	r15, rsi
	mov	r14, rdi
	xor	ebx, ebx
	.p2align	4, 0x90
LBB2_2:                                 ## =>This Inner Loop Header: Depth=1
	movsx	edi, byte ptr [r14 + rbx]
	call	__Z13pf_put_ch_bufc
	add	rbx, 1
	cmp	r15, rbx
	jne	LBB2_2
LBB2_3:
	add	rsp, 8
	pop	rbx
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
