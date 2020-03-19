/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:38:44 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:28:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

extern inline void __attribute__((always_inline))
	s_fmt_data_to_buf(struct s_lpf_buf_ *restrict buf,
					struct s_lpf_flag_ *restrict flag,
					struct s_lpf_data_ *restrict data)
{
	const int	wch = IS_BIT(flag->spec_mask, PF_BIT_SPEC_DOT) ? '0' : ' ';
	size_t		swidth;

	swidth = (flag->width > data->len) ? (flag->width - data->len) : 0UL;
	if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS) && wch != '0')
		lpf_buf_data_(buf, data);
	lpf_buf_ch_(buf, wch, swidth);
	if (!IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS) || wch == '0')
		lpf_buf_data_(buf, data);
}

bool	flag_o(struct s_lpf_buf_ *restrict buf,
			struct s_lpf_flag_ *restrict flag,
			va_list ap)
{
	struct s_lpf_data_	data;

	if (!(data.ptr = get_unsigned_data(ap, 8, flag->type_mask)))
		return (false);
	data.len = strlen(data.ptr);
	s_fmt_data_to_buf(buf, flag, &data);
	free(data.ptr);
	data.ptr = NULL;
	return (true);
}
