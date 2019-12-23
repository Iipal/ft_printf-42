/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:26:36 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

static inline void __attribute__((__always_inline__))
	s_fmt_data_to_buf(struct s_lpf_buf_ *restrict buf,
					struct s_lpf_flag_ *restrict flag,
					struct s_lpf_data_ *restrict data)
{
	size_t	swidth;
	size_t	dwidth;

	swidth = (flag->width > data->len) ? (flag->width - data->len) : 0UL;
	dwidth = (data->len > flag->width) ? flag->width : data->len;
	if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS))
	{
		if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_DOT))
			lpf_buf_data_(buf, data, dwidth);
		else
		{
			lpf_buf_data_(buf, data);
			lpf_buf_ch_(buf, ' ', swidth);
		}
	}
	else
	{
		if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_DOT))
			lpf_buf_data_(buf, data, dwidth);
		else
		{
			lpf_buf_ch_(buf, ' ', swidth);
			lpf_buf_data_(buf, data);
		}
	}
}

extern bool
	flag_s(struct s_lpf_buf_ *restrict buf,
			struct s_lpf_flag_ *restrict flag,
						va_list *restrict ap)
{
	struct s_lpf_data_	data;

	if (!(data.ptr = (char*)va_arg(*ap, char*)))
		data.ptr = "(null)";
	data.len = ft_strlen(data.ptr);
	s_fmt_data_to_buf(buf, flag, &data);
	return (true);
}
