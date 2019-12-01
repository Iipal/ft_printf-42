/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:25:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/01 17:27:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libftprintf_internal.h"

int	ft_vdprintf(int fd, const char *restrict format, va_list *restrict ap)
{
	ssize_t	out;
	int		is_valid;

	refresh_all_global_data();
	is_valid = true;
	out = 0L;
	while (is_valid && format[++g_fmt_i])
		if (format[g_fmt_i] != '%')
			pf_put_ch_buf(format[g_fmt_i]);
		else if ((is_valid = pf_flag_parser(format)))
			is_valid = pf_get_processing_func(ap);
	if (is_valid)
		out = write(fd, g_buf, g_buf_i);
	ft_strdel(&g_buf);
	return ((int)out);
}
