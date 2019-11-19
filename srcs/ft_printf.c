/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:04:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/19 15:21:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pf_local.h"

size_t	g_max_buf = 128;
char	*g_buf = NULL;
size_t	g_buf_i = 0UL;

size_t	g_fmt_i = ~0UL;


char	g_flag = 0;
int		g_flag_spec_mask = 0;
size_t	g_flag_width = 0UL;

char	*g_data_ptr = NULL;
size_t	g_data_len = 0UL;

static inline void	s_refresh_global_flag_data(void)
{
	g_flag = 0;
	g_flag_spec_mask = 0;
	g_flag_width = 0UL;
}

static inline void	s_zero_global_variables(void)
{
	g_flag = 0;
	g_data_len = 0UL;
	g_data_ptr = NULL;
	g_flag_width = 0UL;
	g_flag_spec_mask = 0;
	g_max_buf = 128;
	g_fmt_i = ~0UL;
	g_buf_i = 0UL;
	if (!g_buf)
		g_buf = ft_strnew(sizeof(char) * g_max_buf);
}

static bool			s_choose_func(va_list *ap)
{
	bool	ret;

	ret = false;
	if (g_flag == 'd')
		ret = pf_decimal(ap);
	else if (g_flag == 'p')
		ret = pf_address(ap);
	else if ('s' == g_flag || 'c' == g_flag || '%' == g_flag)
		ret = pf_string(ap);
	s_refresh_global_flag_data();
	if (!ret)
		write(STDERR_FILENO, E_INVALID, ft_strlen(E_INVALID));
	return (ret);
}

int					ft_printf(const char *restrict format, ...)
{
	bool	is_valid;
	va_list	ap;
	ssize_t	out;

	s_zero_global_variables();
	va_start(ap, format);
	is_valid = true;
	out = 0L;
	while (is_valid && format[++g_fmt_i])
		if (format[g_fmt_i] != '%')
			pf_put_ch_buf(format[g_fmt_i]);
		else
		{
			if ((is_valid = pf_flag_parser(format)))
				is_valid = s_choose_func(&ap);
		}
	va_end(ap);
	if (is_valid)
		out = write(STDOUT_FILENO, g_buf, g_buf_i);
	if (g_buf)
	{
		free(g_buf);
		g_buf = NULL;
	}
	return ((int)out);
}
