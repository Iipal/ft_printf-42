	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_pf_get_processing_func ## -- Begin function pf_get_processing_func
	.p2align	4, 0x90
_pf_get_processing_func:                ## @pf_get_processing_func
	.cfi_startproc
## %bb.0:
	mov	rax, qword ptr [rip + _g_flag@GOTPCREL]
	movsx	ecx, word ptr [rax]
	mov	rax, -3
	lea	rdx, [rip + _s_get_func_index.arr]
	.p2align	4, 0x90
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movsx	esi, byte ptr [rax + rdx + 3]
	add	rax, 1
	test	esi, esi
	je	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	cmp	ecx, esi
	jne	LBB0_1
LBB0_3:
	mov	rdx, rax
	add	rdx, 2
	jae	LBB0_5
## %bb.4:
	mov	ecx, 1
	jmp	LBB0_8
LBB0_5:
	cmp	rdx, 5
	jae	LBB0_7
## %bb.6:
	mov	ecx, 2
	jmp	LBB0_8
LBB0_7:
	xor	ecx, ecx
	cmp	rdx, 8
	cmovb	rcx, rax
LBB0_8:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	push	rbx
	push	rax
	.cfi_offset rbx, -24
	lea	rax, [rip + _s_run_func.fn]
	call	qword ptr [rax + 8*rcx]
	mov	ebx, eax
	call	_refresh_flag_global_data
	test	bl, bl
	jne	LBB0_10
## %bb.9:
	lea	rdi, [rip + L_.str]
	mov	esi, 2
	call	_ft_putendl_fd
LBB0_10:
	mov	eax, ebx
	add	rsp, 8
	pop	rbx
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function invalid
_invalid:                               ## @invalid
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	test	rdi, rdi
	sete	al
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"ft_printf: Something invalid."

	.section	__DATA,__const
	.p2align	4               ## @s_run_func.fn
_s_run_func.fn:
	.quad	_invalid
	.quad	_pf_decimal
	.quad	_pf_string
	.quad	_pf_address
	.quad	_pf_octal
	.quad	_pf_unsigned
	.quad	0
	.quad	0

	.section	__TEXT,__const
	.p2align	4               ## @s_get_func_index.arr
_s_get_func_index.arr:
	.ascii	"disc%pou"
	.space	8


.subsections_via_symbols
