/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:08:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:27:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline bool
	flag_di(struct s_lpf_buf_ *restrict buf,
			struct s_lpf_flag_ *restrict flag,
						va_list *restrict ap)
{
	struct s_lpf_data_	data;
	int					wch;

	if (!(data.ptr = get_signed_data(ap, flag->type_mask)))
		return (false);
	wch = IS_BIT(flag->spec_mask, PF_BIT_SPEC_DOT) ? '0' : ' ';
	data.len = ft_strlen(data.ptr);
	if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS) && wch != '0')
		lpf_buf_data_(buf, &data);
	if (flag->width > data.len)
		lpf_buf_ch_(buf, wch, flag->width - data.len);
	if (!IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS) || wch == '0')
		lpf_buf_data_(buf, &data);
	ft_strdel(&data.ptr);
	return (true);
}
