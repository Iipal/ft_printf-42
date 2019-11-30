/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:51:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 22:44:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

int	ft_snprintf(char *str, size_t len, const char *restrict format, ...)
{
	va_list	ap;
	size_t	out;
	int		is_valid;

	refresh_all_global_data();
	va_start(ap, format);
	is_valid = true;
	out = 0UL;
	while (is_valid && len >= ++g_fmt_i && format[g_fmt_i])
		if (format[g_fmt_i] != '%')
			pf_put_ch_buf(format[g_fmt_i]);
		else if ((is_valid = pf_flag_parser(format)))
			is_valid = pf_get_processing_func(&ap);
	va_end(ap);
	if (is_valid)
	{
		ft_strncpy(str, g_buf, g_buf_i);
		str[g_buf_i] = '\0';
		out = g_buf_i;
	}
	ft_strdel(&g_buf);
	return ((int)out);
}
