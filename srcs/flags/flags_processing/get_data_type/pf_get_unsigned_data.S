	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_pf_get_unsigned_data   ## -- Begin function pf_get_unsigned_data
	.p2align	4, 0x90
_pf_get_unsigned_data:                  ## @pf_get_unsigned_data
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
	mov	r14d, esi
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
	jmp	LBB0_9
LBB0_2:
	cmp	eax, 40
	ja	LBB0_4
## %bb.3:
	mov	rcx, qword ptr [rdi + 16]
	add	rcx, rax
	add	eax, 8
	mov	dword ptr [rdi], eax
	mov	ebx, dword ptr [rcx]
	jmp	LBB0_10
LBB0_4:
	mov	rcx, qword ptr [rdi + 8]
	lea	rax, [rcx + 8]
	mov	qword ptr [rdi + 8], rax
	mov	ebx, dword ptr [rcx]
	jmp	LBB0_10
LBB0_8:
	mov	rcx, qword ptr [rdi + 8]
	lea	rax, [rcx + 8]
	mov	qword ptr [rdi + 8], rax
LBB0_9:
	mov	rbx, qword ptr [rcx]
LBB0_10:
	mov	edi, 24
	call	_ft_strnew
	mov	rdi, rbx
	mov	rsi, rax
	mov	edx, r14d
	pop	rbx
	pop	r14
	pop	rbp
	jmp	_ft_ultoa               ## TAILCALL
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
