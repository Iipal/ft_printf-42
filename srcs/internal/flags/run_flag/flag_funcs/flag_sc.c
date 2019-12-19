/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_sc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:32:58 by tmaluh           ###   ########.fr       */
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
	size_t	swidth;
	size_t	dwidth;

	swidth = (flag->width > data->len) ? (flag->width - data->len) : 0UL;
	dwidth = (data->len > flag->width) ? flag->width : data->len;
	if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS))
	{
		if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_DOT))
			buf_add_data(buf, data, dwidth);
		else
		{
			buf_add_data(buf, data);
			buf_add_ch(buf, ' ', swidth);
		}
	}
	else
	{
		if (IS_BIT(flag->spec_mask, PF_BIT_SPEC_DOT))
			buf_add_data(buf, data, dwidth);
		else
		{
			buf_add_ch(buf, ' ', swidth);
			buf_add_data(buf, data);
		}
	}
}

static inline int __attribute__((__always_inline__))
	s_choose_data(char *restrict _Nonnull *restrict _Nullable data_ptr,
		va_list *restrict _Nonnull ap,
		int symbol)
{
	if ('s' == symbol)
	{
		if (!(*data_ptr = (char*)va_arg(*ap, char*)))
			*data_ptr = "(null)";
	}
	else if ('%' == symbol)
		return ('%');
	else
		return (va_arg(*ap, int));
	return (0);
}

extern bool
	flag_sc(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap)
{
	struct s_flag_data	data;
	char				ch;
	bool				is_str;

	ch = s_choose_data(&data.ptr, ap, flag->symbol);
	is_str = !(flag->symbol == 'c' || flag->symbol == '%');
	if (is_str)
		data.len = ft_strlen(data.ptr);
	else
		data.len = 1UL;
	if (is_str)
		s_fmt_data_to_buf(buf, flag, &data);
	else
		buf_add_ch(buf, ch);
	return (true);
}
