/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:04:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 22:44:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

int	ft_fprintf(FILE *stream, const char *restrict format, ...)
{
	va_list	ap;
	size_t	out;
	int		is_valid;

	refresh_all_global_data();
	va_start(ap, format);
	is_valid = true;
	out = 0UL;
	while (is_valid && format[++g_fmt_i])
		if (format[g_fmt_i] != '%')
			pf_put_ch_buf(format[g_fmt_i]);
		else if ((is_valid = pf_flag_parser(format)))
			is_valid = pf_get_processing_func(&ap);
	va_end(ap);
	if (is_valid)
		out = fwrite(g_buf, sizeof(char), g_buf_i, stream);
	ft_strdel(&g_buf);
	return ((int)out);
}
