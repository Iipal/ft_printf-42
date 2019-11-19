/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:18:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/19 11:26:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

bool    pf_flag_parser(const char *restrict format)
{
	if (format[++g_fmt_i] == '-')
	{
		SET_BIT(g_flag_spec_mask, FTPRINTF_BIT_MINUS);
		++g_fmt_i;
	}
	if (format[g_fmt_i] == '.')
	{
		SET_BIT(g_flag_spec_mask, FTPRINTF_BIT_DOT);
		++g_fmt_i;
	}
	g_flag_width = (size_t)ft_atol(format + g_fmt_i);
	while (format[g_fmt_i] && F_ISDIGIT(format[g_fmt_i]))
		++g_fmt_i;
	g_flag = format[g_fmt_i];
	return (true);
}
