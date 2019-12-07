/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_vprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 21:51:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

int	internal_vprintf(const char *restrict format, va_list *restrict ap)
{
	ssize_t	out;
	bool	is_valid;

	refresh_all_global_data();
	out = 0L;
	is_valid = true;
	while (is_valid && format[++g_fmt_i])
		if (format[g_fmt_i] != '%')
			pf_put_ch_buf(format[g_fmt_i]);
		else if ((is_valid = pf_flag_parser(format)))
			is_valid = pf_get_processing_func(ap);
	if (is_valid)
		out = g_buf_i;
	return (out);
}
