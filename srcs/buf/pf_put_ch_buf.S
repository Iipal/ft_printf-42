	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	__Z13pf_put_ch_bufc     ## -- Begin function _Z13pf_put_ch_bufc
	.p2align	4, 0x90
__Z13pf_put_ch_bufc:                    ## @_Z13pf_put_ch_bufc
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
	mov	ebx, edi
	mov	r15, qword ptr [rip + _g_max_buf@GOTPCREL]
	mov	rsi, qword ptr [r15]
	mov	r14, qword ptr [rip + _g_buf_i@GOTPCREL]
	mov	rcx, qword ptr [r14]
	mov	r12, qword ptr [rip + _g_buf@GOTPCREL]
	mov	rax, qword ptr [r12]
	cmp	rsi, rcx
	ja	LBB0_2
## %bb.1:
	lea	rdx, [rsi + 256]
	mov	rdi, rax
	call	_ft_memrealloc
	mov	qword ptr [r12], rax
	add	qword ptr [r15], 256
	mov	rcx, qword ptr [r14]
LBB0_2:
	lea	rdx, [rcx + 1]
	mov	qword ptr [r14], rdx
	mov	byte ptr [rax + rcx], bl
	pop	rbx
	pop	r12
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	__Z13pf_put_ch_bufcm    ## -- Begin function _Z13pf_put_ch_bufcm
	.p2align	4, 0x90
__Z13pf_put_ch_bufcm:                   ## @_Z13pf_put_ch_bufcm
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r15
	push	r14
	push	r13
	push	r12
	push	rbx
	push	rax
	.cfi_offset rbx, -56
	.cfi_offset r12, -48
	.cfi_offset r13, -40
	.cfi_offset r14, -32
	.cfi_offset r15, -24
	test	rsi, rsi
	je	LBB1_5
## %bb.1:
	mov	rbx, rsi
	mov	r14d, edi
	mov	r15, qword ptr [rip + _g_max_buf@GOTPCREL]
	mov	r12, qword ptr [rip + _g_buf_i@GOTPCREL]
	mov	r13, qword ptr [rip + _g_buf@GOTPCREL]
	.p2align	4, 0x90
LBB1_2:                                 ## =>This Inner Loop Header: Depth=1
	add	rbx, -1
	mov	rsi, qword ptr [r15]
	mov	rcx, qword ptr [r12]
	mov	rax, qword ptr [r13]
	cmp	rsi, rcx
	ja	LBB1_4
## %bb.3:                               ##   in Loop: Header=BB1_2 Depth=1
	lea	rdx, [rsi + 256]
	mov	rdi, rax
	call	_ft_memrealloc
	mov	qword ptr [r13], rax
	add	qword ptr [r15], 256
	mov	rcx, qword ptr [r12]
LBB1_4:                                 ##   in Loop: Header=BB1_2 Depth=1
	lea	rdx, [rcx + 1]
	mov	qword ptr [r12], rdx
	mov	byte ptr [rax + rcx], r14b
	test	rbx, rbx
	jne	LBB1_2
LBB1_5:
	add	rsp, 8
	pop	rbx
	pop	r12
	pop	r13
	pop	r14
	pop	r15
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
