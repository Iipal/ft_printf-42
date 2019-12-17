	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_pf_get_signed_data     ## -- Begin function pf_get_signed_data
	.p2align	4, 0x90
_pf_get_signed_data:                    ## @pf_get_signed_data
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	rax, qword ptr [rip + _g_flag_type_mask@GOTPCREL]
	mov	ecx, dword ptr [rax]
	movsxd	rax, dword ptr [rdi]
	test	ecx, ecx
	je	LBB0_2
## %bb.1:
	and	ecx, 34
	jne	LBB0_2
## %bb.6:
	cmp	eax, 40
	ja	LBB0_8
## %bb.7:
	mov	rcx, rax
	add	rcx, qword ptr [rdi + 16]
	lea	eax, [rax + 8]
	mov	dword ptr [rdi], eax
	mov	rdi, qword ptr [rcx]
	pop	rbp
	jmp	_ft_ltoa                ## TAILCALL
LBB0_2:
	cmp	eax, 40
	ja	LBB0_4
## %bb.3:
	mov	rcx, qword ptr [rdi + 16]
	add	rcx, rax
	add	eax, 8
	mov	dword ptr [rdi], eax
	mov	edi, dword ptr [rcx]
	pop	rbp
	jmp	_ft_itoa                ## TAILCALL
LBB0_4:
	mov	rcx, qword ptr [rdi + 8]
	lea	rax, [rcx + 8]
	mov	qword ptr [rdi + 8], rax
	mov	edi, dword ptr [rcx]
	pop	rbp
	jmp	_ft_itoa                ## TAILCALL
LBB0_8:
	mov	rcx, qword ptr [rdi + 8]
	lea	rax, [rcx + 8]
	mov	qword ptr [rdi + 8], rax
	mov	rdi, qword ptr [rcx]
	pop	rbp
	jmp	_ft_ltoa                ## TAILCALL
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
