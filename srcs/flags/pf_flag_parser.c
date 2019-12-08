/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:18:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:06:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

static inline void __attribute__((__always_inline__))
	s_get_flag_type(const char *restrict format)
{
	SET_BIT(g_flag_type_mask,
		ft_is_one_of_n(format[g_fmt_i], 5UL, 'l', 'h', 'j', 't', 'z'));
	if (g_flag_type_mask
	&& (format[++g_fmt_i] == 'l' || format[g_fmt_i] == 'h'))
		++g_fmt_i;
}

inline bool
	pf_flag_parser(const char *restrict format)
{
	if (format[++g_fmt_i] == '-')
	{
		SET_BIT(g_flag_spec_mask, PF_BIT_SPEC_MINUS);
		++g_fmt_i;
	}
	if (format[g_fmt_i] == '.')
	{
		SET_BIT(g_flag_spec_mask, PF_BIT_SPEC_DOT);
		++g_fmt_i;
	}
	g_flag_width = (size_t)ft_atol(format + g_fmt_i);
	while (F_ISDIGIT(format[g_fmt_i]) && format[g_fmt_i])
		++g_fmt_i;
	s_get_flag_type(format);
	g_flag = format[g_fmt_i];
	return (true);
}
