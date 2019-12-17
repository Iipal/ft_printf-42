	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.intel_syntax noprefix
	.globl	_refresh_flag_global_data ## -- Begin function refresh_flag_global_data
	.p2align	4, 0x90
_refresh_flag_global_data:              ## @refresh_flag_global_data
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	word ptr [rip + _g_flag], 0
	mov	dword ptr [rip + _g_flag_spec_mask], 0
	mov	dword ptr [rip + _g_flag_type_mask], 0
	mov	qword ptr [rip + _g_flag_width], 0
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.globl	_refresh_all_global_data ## -- Begin function refresh_all_global_data
	.p2align	4, 0x90
_refresh_all_global_data:               ## @refresh_all_global_data
	.cfi_startproc
## %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	mov	rdi, qword ptr [rip + _g_buf]
	test	rdi, rdi
	je	LBB1_2
## %bb.1:
	call	_free
LBB1_2:
	mov	word ptr [rip + _g_flag], 0
	mov	dword ptr [rip + _g_flag_spec_mask], 0
	mov	dword ptr [rip + _g_flag_type_mask], 0
	mov	qword ptr [rip + _g_flag_width], 0
	mov	qword ptr [rip + _g_max_buf], 256
	mov	edi, 256
	call	_ft_strnew
	mov	qword ptr [rip + _g_buf], rax
	mov	qword ptr [rip + _g_buf_i], 0
	mov	qword ptr [rip + _g_data_len], 0
	mov	qword ptr [rip + _g_data_ptr], 0
	mov	qword ptr [rip + _g_fmt_i], -1
	pop	rbp
	ret
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_g_max_buf              ## @g_max_buf
	.p2align	3
_g_max_buf:
	.quad	256                     ## 0x100

	.globl	_g_buf                  ## @g_buf
.zerofill __DATA,__common,_g_buf,8,3
	.globl	_g_buf_i                ## @g_buf_i
.zerofill __DATA,__common,_g_buf_i,8,3
	.globl	_g_fmt_i                ## @g_fmt_i
	.p2align	3
_g_fmt_i:
	.quad	-1                      ## 0xffffffffffffffff

	.globl	_g_flag                 ## @g_flag
.zerofill __DATA,__common,_g_flag,2,1
	.globl	_g_flag_spec_mask       ## @g_flag_spec_mask
.zerofill __DATA,__common,_g_flag_spec_mask,4,2
	.globl	_g_flag_type_mask       ## @g_flag_type_mask
.zerofill __DATA,__common,_g_flag_type_mask,4,2
	.globl	_g_flag_width           ## @g_flag_width
.zerofill __DATA,__common,_g_flag_width,8,3
	.globl	_g_data_ptr             ## @g_data_ptr
.zerofill __DATA,__common,_g_data_ptr,8,3
	.globl	_g_data_len             ## @g_data_len
.zerofill __DATA,__common,_g_data_len,8,3

.subsections_via_symbols
