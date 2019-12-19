/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:18:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 22:34:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline bool
	flag_parser(struct s_lpf_flag_ *restrict _Nonnull flag,
						const char *restrict _Nonnull format,
							size_t *restrict _Nonnull fmt_i)
{
	*flag = (struct s_lpf_flag_) { S_FLAG_INFO_REFRESH };
	if (format[++(*fmt_i)] == '-')
	{
		SET_BIT(flag->spec_mask, PF_BIT_SPEC_MINUS);
		++(*fmt_i);
	}
	if (format[*fmt_i] == '.')
	{
		SET_BIT(flag->spec_mask, PF_BIT_SPEC_DOT);
		++(*fmt_i);
	}
	flag->width = (size_t)ft_atol(format + *fmt_i);
	while (F_ISDIGIT(format[*fmt_i]) && format[*fmt_i])
		++(*fmt_i);
	SET_BIT(flag->type_mask,
		ft_is_one_of_n(format[*fmt_i], 5UL, 'l', 'h', 'j', 't', 'z'));
	if (flag->type_mask && (format[++(*fmt_i)] == 'l' || format[*fmt_i] == 'h'))
		++(*fmt_i);
	flag->symbol = format[*fmt_i];
	return (true);
}
