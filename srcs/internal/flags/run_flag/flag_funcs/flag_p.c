/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:33:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline bool
	flag_p(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap)
{
	struct s_flag_data	data;
	intptr_t			addr;
	ssize_t				width;

	addr = (intptr_t)va_arg(*ap, void*);
	if (!(data.ptr = ft_ltoa_base(addr, 16)))
		return (false);
	data.len = ft_strlen(data.ptr);
	width = (ssize_t)flag->width - (ssize_t)(data.len + 2UL);
	if (0 < width && !IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS))
		buf_add_ch(buf, ' ', (size_t)width);
	buf_add_data(buf, "0x", sizeof("0x"));
	buf_add_data(buf, &data);
	if (0 < width && IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS))
		buf_add_ch(buf, ' ', (size_t)width);
	ft_strdel(&data.ptr);
	return (true);
}
