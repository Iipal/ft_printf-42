	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_pf_address             ## -- Begin function pf_address
	.p2align	4, 0x90
_pf_address:                            ## @pf_address
	.cfi_startproc
## %bb.0:
	movsxd	rcx, dword ptr [rdi]
	cmp	rcx, 40
	ja	LBB0_2
## %bb.1:
	mov	rax, rcx
	add	rax, qword ptr [rdi + 16]
	lea	ecx, [rcx + 8]
	mov	dword ptr [rdi], ecx
	jmp	LBB0_3
LBB0_2:
	mov	rax, qword ptr [rdi + 8]
	lea	rcx, [rax + 8]
	mov	qword ptr [rdi + 8], rcx
LBB0_3:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r14
	push	rbx
	.cfi_offset rbx, -32
	.cfi_offset r14, -24
	mov	rdi, qword ptr [rax]
	mov	esi, 16
	call	_ft_ltoa_base
	mov	rcx, qword ptr [rip + _g_data_ptr@GOTPCREL]
	mov	qword ptr [rcx], rax
	test	rax, rax
	je	LBB0_4
## %bb.5:
	mov	rdi, rax
	call	_ft_strlen
	mov	rcx, qword ptr [rip + _g_data_len@GOTPCREL]
	mov	qword ptr [rcx], rax
	mov	rcx, qword ptr [rip + _g_flag_width@GOTPCREL]
	mov	rbx, -2
	sub	rbx, rax
	add	rbx, qword ptr [rcx]
	test	rbx, rbx
	jle	LBB0_10
## %bb.6:
	mov	r14, qword ptr [rip + _g_flag_spec_mask@GOTPCREL]
	test	byte ptr [r14], 1
	jne	LBB0_8
## %bb.7:
	mov	edi, 32
	mov	rsi, rbx
	call	__Z13pf_put_ch_bufcm
LBB0_8:
	lea	rdi, [rip + L_.str]
	mov	esi, 3
	call	__Z14pf_put_str_bufPKcm
	call	__Z14pf_put_str_bufv
	test	byte ptr [r14], 1
	je	LBB0_11
## %bb.9:
	mov	edi, 32
	mov	rsi, rbx
	call	__Z13pf_put_ch_bufcm
	jmp	LBB0_11
LBB0_4:
	xor	eax, eax
                                        ## kill: def $al killed $al killed $eax
	pop	rbx
	pop	r14
	pop	rbp
	ret
LBB0_10:
	lea	rdi, [rip + L_.str]
	mov	esi, 3
	call	__Z14pf_put_str_bufPKcm
	call	__Z14pf_put_str_bufv
LBB0_11:
	mov	rdi, qword ptr [rip + _g_data_ptr@GOTPCREL]
	call	_ft_strdel
	mov	al, 1
                                        ## kill: def $al killed $al killed $eax
	pop	rbx
	pop	r14
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"0x"


.subsections_via_symbols
