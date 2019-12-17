	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_pf_flag_parser         ## -- Begin function pf_flag_parser
	.p2align	4, 0x90
_pf_flag_parser:                        ## @pf_flag_parser
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	r14
	push	rbx
	sub	rsp, 16
	.cfi_offset rbx, -32
	.cfi_offset r14, -24
	mov	rbx, rdi
	mov	r14, qword ptr [rip + _g_fmt_i@GOTPCREL]
	mov	rdx, qword ptr [r14]
	lea	rax, [rdx + 1]
	mov	qword ptr [r14], rax
	mov	cl, byte ptr [rdi + rdx + 1]
	cmp	cl, 45
	jne	LBB0_1
## %bb.2:
	mov	rax, qword ptr [rip + _g_flag_spec_mask@GOTPCREL]
	or	byte ptr [rax], 1
	lea	rax, [rdx + 2]
	mov	qword ptr [r14], rax
	lea	rdi, [rbx + rdx]
	add	rdi, 2
	mov	cl, byte ptr [rbx + rdx + 2]
	cmp	cl, 46
	je	LBB0_4
	jmp	LBB0_5
LBB0_1:
	lea	rdi, [rbx + rdx]
	add	rdi, 1
	cmp	cl, 46
	jne	LBB0_5
LBB0_4:
	mov	rcx, qword ptr [rip + _g_flag_spec_mask@GOTPCREL]
	or	byte ptr [rcx], 2
	lea	rcx, [rax + 1]
	mov	qword ptr [r14], rcx
	lea	rdi, [rbx + rax]
	add	rdi, 1
LBB0_5:
	call	_ft_atol
	mov	rcx, qword ptr [rip + _g_flag_width@GOTPCREL]
	mov	qword ptr [rcx], rax
	mov	rcx, qword ptr [r14]
	mov	al, byte ptr [rbx + rcx]
	mov	edx, eax
	add	dl, -48
	cmp	dl, 9
	ja	LBB0_8
	.p2align	4, 0x90
LBB0_6:                                 ## =>This Inner Loop Header: Depth=1
	movzx	eax, byte ptr [rbx + rcx + 1]
	add	rcx, 1
	mov	edx, eax
	add	dl, -48
	cmp	dl, 10
	jb	LBB0_6
## %bb.7:
	mov	qword ptr [r14], rcx
LBB0_8:
	mov	dword ptr [rsp], 122
	movsx	edi, al
	mov	esi, 5
	mov	edx, 108
	mov	ecx, 104
	mov	r8d, 106
	mov	r9d, 116
	xor	eax, eax
	call	__Z14ft_is_one_of_ncmz
	mov	rcx, qword ptr [rip + _g_flag_type_mask@GOTPCREL]
	or	dword ptr [rcx], eax
	mov	rax, qword ptr [r14]
	je	LBB0_11
## %bb.9:
	lea	rcx, [rax + 1]
	mov	qword ptr [r14], rcx
	mov	dl, byte ptr [rbx + rax + 1]
	or	dl, 4
	cmp	dl, 108
	jne	LBB0_12
## %bb.10:
	add	rax, 2
	mov	qword ptr [r14], rax
LBB0_11:
	mov	rcx, rax
LBB0_12:
	movsx	eax, byte ptr [rbx + rcx]
	mov	rcx, qword ptr [rip + _g_flag@GOTPCREL]
	mov	word ptr [rcx], ax
	mov	al, 1
	add	rsp, 16
	pop	rbx
	pop	r14
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
