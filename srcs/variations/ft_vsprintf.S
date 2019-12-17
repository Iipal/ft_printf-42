	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_vsprintf            ## -- Begin function ft_vsprintf
	.p2align	4, 0x90
_ft_vsprintf:                           ## @ft_vsprintf
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
	mov	rbx, rdi
	mov	rdi, rsi
	mov	rsi, rdx
	call	_internal_vprintf
	test	eax, eax
	je	LBB0_1
## %bb.2:
	mov	rax, qword ptr [rip + _g_buf@GOTPCREL]
	mov	rsi, qword ptr [rax]
	mov	r14, qword ptr [rip + _g_buf_i@GOTPCREL]
	mov	rdx, qword ptr [r14]
	mov	rdi, rbx
	call	_ft_strncpy
	mov	rax, qword ptr [r14]
	mov	byte ptr [rbx + rax], 0
	mov	ebx, dword ptr [r14]
	jmp	LBB0_3
LBB0_1:
	xor	ebx, ebx
LBB0_3:
	mov	rdi, qword ptr [rip + _g_buf@GOTPCREL]
	call	_ft_strdel
	mov	eax, ebx
	pop	rbx
	pop	r14
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
