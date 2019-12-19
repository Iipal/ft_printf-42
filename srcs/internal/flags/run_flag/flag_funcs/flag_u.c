/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:31:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:36:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

static inline void __attribute__((__always_inline__))
	s_fmt_data_to_buf(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
			struct s_flag_data *restrict _Nonnull data)
{
	const int	wch = IS_BIT(flag->spec_mask, PF_BIT_SPEC_DOT) ? '0' : ' ';
	size_t		swidth;

	swidth = (flag->width > data->len) ? (flag->width - data->len) : 0UL;
	if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS) && wch != '0')
		buf_add_data(buf, data);
	buf_add_ch(buf, wch, swidth);
	if (!IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS) || wch == '0')
		buf_add_data(buf, data);
}

inline bool
	flag_u(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap)

{
	struct s_flag_data	data;

	if (!(data.ptr = get_unsigned_data(ap, 10, flag->type_mask)))
		return (false);
	data.len = ft_strlen(data.ptr);
	s_fmt_data_to_buf(buf, flag, &data);
	ft_strdel(&data.ptr);
	return (true);
}
