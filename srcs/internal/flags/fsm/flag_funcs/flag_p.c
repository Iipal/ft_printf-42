/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:22:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

bool	flag_p(struct s_lpf_buf_ *restrict buf,
				struct s_lpf_flag_ *restrict flag,
				va_list ap)
{
	struct s_lpf_data_	data;
	uintptr_t			addr;
	ssize_t				width;

	addr = (uintptr_t)va_arg(ap, void*);
	data.ptr = lpf_ultoap_base(addr, calloc(24, sizeof(char)), 16);
	if (!(data.len = strlen(data.ptr)))
		return (false);
	width = (ssize_t)flag->width - (ssize_t)(data.len + 2UL);
	if (0 < width && !IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS))
		lpf_buf_ch_(buf, ' ', (size_t)width);
	lpf_buf_data_(buf, "0x", 2UL);
	lpf_buf_data_(buf, &data);
	if (0 < width && IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS))
		lpf_buf_ch_(buf, ' ', (size_t)width);
	free(data.ptr);
	data.ptr = NULL;
	return (true);
}
