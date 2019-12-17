	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_pf_string              ## -- Begin function pf_string
	.p2align	4, 0x90
_pf_string:                             ## @pf_string
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	rbx
	push	rax
	.cfi_offset rbx, -24
	mov	rax, qword ptr [rip + _g_flag@GOTPCREL]
	movzx	ecx, word ptr [rax]
	cmp	ecx, 115
	je	LBB0_3
## %bb.1:
	movzx	ecx, cx
	cmp	ecx, 37
	jne	LBB0_5
## %bb.2:
	mov	byte ptr [rip + _pf_string.ch], 37
	mov	byte ptr [rip + _pf_string.is_str], 0
	xor	eax, eax
	jmp	LBB0_13
LBB0_3:
	movsxd	rdx, dword ptr [rdi]
	cmp	rdx, 40
	ja	LBB0_7
## %bb.4:
	mov	rcx, rdx
	add	rcx, qword ptr [rdi + 16]
	lea	edx, [rdx + 8]
	mov	dword ptr [rdi], edx
	jmp	LBB0_8
LBB0_5:
	movsxd	rdx, dword ptr [rdi]
	cmp	rdx, 40
	ja	LBB0_9
## %bb.6:
	mov	rcx, rdx
	add	rcx, qword ptr [rdi + 16]
	lea	edx, [rdx + 8]
	mov	dword ptr [rdi], edx
	jmp	LBB0_10
LBB0_7:
	mov	rcx, qword ptr [rdi + 8]
	lea	rdx, [rcx + 8]
	mov	qword ptr [rdi + 8], rdx
LBB0_8:
	mov	rcx, qword ptr [rcx]
	test	rcx, rcx
	lea	rdx, [rip + L_.str]
	cmovne	rdx, rcx
	mov	rcx, qword ptr [rip + _g_data_ptr@GOTPCREL]
	mov	qword ptr [rcx], rdx
	xor	ecx, ecx
	jmp	LBB0_11
LBB0_9:
	mov	rcx, qword ptr [rdi + 8]
	lea	rdx, [rcx + 8]
	mov	qword ptr [rdi + 8], rdx
LBB0_10:
	mov	cl, byte ptr [rcx]
LBB0_11:
	movzx	edx, word ptr [rax]
	cmp	edx, 99
	setne	bl
	cmp	edx, 37
	setne	al
	and	al, bl
	mov	byte ptr [rip + _pf_string.ch], cl
	mov	byte ptr [rip + _pf_string.is_str], al
	cmp	edx, 37
	je	LBB0_13
## %bb.12:
	movzx	ecx, dx
	cmp	ecx, 99
	jne	LBB0_19
LBB0_13:
	mov	rcx, qword ptr [rip + _g_data_len@GOTPCREL]
	mov	qword ptr [rcx], 1
	mov	edi, 1
	test	al, al
	je	LBB0_21
LBB0_14:
	mov	rax, qword ptr [rip + _g_flag_width@GOTPCREL]
	mov	rax, qword ptr [rax]
	cmp	rax, rdi
	mov	rbx, rdi
	cmova	rbx, rax
	sub	rbx, rdi
	cmp	rdi, rax
	cmova	rdi, rax
	mov	rax, qword ptr [rip + _g_flag_spec_mask@GOTPCREL]
	mov	eax, dword ptr [rax]
	test	al, 1
	jne	LBB0_17
## %bb.15:
	test	al, 2
	jne	LBB0_18
## %bb.22:
	mov	edi, 32
	mov	rsi, rbx
	call	__Z13pf_put_ch_bufcm
	call	__Z14pf_put_str_bufv
	jmp	LBB0_24
LBB0_17:
	test	al, 2
	je	LBB0_23
LBB0_18:
	call	__Z14pf_put_str_bufm
	jmp	LBB0_24
LBB0_19:
	mov	rcx, qword ptr [rip + _g_data_ptr@GOTPCREL]
	mov	rdi, qword ptr [rcx]
	cmp	byte ptr [rdi], 0
	je	LBB0_25
## %bb.20:
	call	_ft_strlen
	mov	rdi, rax
	mov	rax, qword ptr [rip + _g_data_len@GOTPCREL]
	mov	qword ptr [rax], rdi
	mov	al, byte ptr [rip + _pf_string.is_str]
	test	al, al
	jne	LBB0_14
LBB0_21:
	movsx	edi, byte ptr [rip + _pf_string.ch]
	call	__Z13pf_put_ch_bufc
	jmp	LBB0_24
LBB0_23:
	call	__Z14pf_put_str_bufv
	mov	edi, 32
	mov	rsi, rbx
	call	__Z13pf_put_ch_bufcm
LBB0_24:
	mov	rax, qword ptr [rip + _g_data_ptr@GOTPCREL]
	mov	qword ptr [rax], 0
	mov	al, 1
	add	rsp, 8
	pop	rbx
	pop	rbp
	ret
LBB0_25:
	mov	rcx, qword ptr [rip + _g_data_len@GOTPCREL]
	mov	qword ptr [rcx], 0
	xor	edi, edi
	test	al, al
	jne	LBB0_14
	jmp	LBB0_21
	.cfi_endproc
                                        ## -- End function
.zerofill __DATA,__bss,_pf_string.ch,1,0 ## @pf_string.ch
.zerofill __DATA,__bss,_pf_string.is_str,1,0 ## @pf_string.is_str
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"(null)"


.subsections_via_symbols
