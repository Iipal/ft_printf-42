	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_ft_fprintf             ## -- Begin function ft_fprintf
	.p2align	4, 0x90
_ft_fprintf:                            ## @ft_fprintf
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	sub	rsp, 208
	test	al, al
	je	LBB0_2
## %bb.1:
	vmovaps	xmmword ptr [rbp - 160], xmm0
	vmovaps	xmmword ptr [rbp - 144], xmm1
	vmovaps	xmmword ptr [rbp - 128], xmm2
	vmovaps	xmmword ptr [rbp - 112], xmm3
	vmovaps	xmmword ptr [rbp - 96], xmm4
	vmovaps	xmmword ptr [rbp - 80], xmm5
	vmovaps	xmmword ptr [rbp - 64], xmm6
	vmovaps	xmmword ptr [rbp - 48], xmm7
LBB0_2:
	mov	qword ptr [rbp - 168], r9
	mov	qword ptr [rbp - 176], r8
	mov	qword ptr [rbp - 184], rcx
	mov	qword ptr [rbp - 192], rdx
	mov	rax, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rax, qword ptr [rax]
	mov	qword ptr [rbp - 8], rax
	lea	rax, [rbp - 208]
	mov	qword ptr [rbp - 16], rax
	lea	rax, [rbp + 16]
	mov	qword ptr [rbp - 24], rax
	movabs	rax, 206158430224
	mov	qword ptr [rbp - 32], rax
	lea	rdx, [rbp - 32]
	call	_ft_vfprintf
	mov	rcx, qword ptr [rip + ___stack_chk_guard@GOTPCREL]
	mov	rcx, qword ptr [rcx]
	cmp	rcx, qword ptr [rbp - 8]
	jne	LBB0_4
## %bb.3:
	add	rsp, 208
	pop	rbp
	ret
LBB0_4:
	call	___stack_chk_fail
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
