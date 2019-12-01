/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:04:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/01 18:05:26 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

int	ft_vsprintf(char *str, const char *restrict format, va_list *restrict ap)
{
	size_t	out;
	int		is_valid;

	refresh_all_global_data();
	is_valid = true;
	out = 0UL;
	while (is_valid && format[++g_fmt_i])
		if (format[g_fmt_i] != '%')
			pf_put_ch_buf(format[g_fmt_i]);
		else if ((is_valid = pf_flag_parser(format)))
			is_valid = pf_get_processing_func(ap);
	if (is_valid)
	{
		ft_strncpy(str, g_buf, g_buf_i);
		str[g_buf_i] = '\0';
		out = g_buf_i;
	}
	ft_strdel(&g_buf);
	return ((int)out);
}
