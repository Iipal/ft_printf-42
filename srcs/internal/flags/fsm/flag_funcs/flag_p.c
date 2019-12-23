/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:26:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline bool
	flag_p(struct s_lpf_buf_ *restrict buf,
			struct s_lpf_flag_ *restrict flag,
						va_list *restrict ap)
{
	struct s_lpf_data_	data;
	intptr_t			addr;
	ssize_t				width;

	addr = (intptr_t)va_arg(*ap, void*);
	if (!(data.ptr = ft_ltoa_base(addr, 16)))
		return (false);
	data.len = ft_strlen(data.ptr);
	width = (ssize_t)flag->width - (ssize_t)(data.len + 2UL);
	if (0 < width && !IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS))
		lpf_buf_ch_(buf, ' ', (size_t)width);
	lpf_buf_data_(buf, "0x", 2UL);
	lpf_buf_data_(buf, &data);
	if (0 < width && IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS))
		lpf_buf_ch_(buf, ' ', (size_t)width);
	ft_strdel(&data.ptr);
	return (true);
}
