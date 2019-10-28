/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:04:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 13:23:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_local.h"

char	g_buff[MAX_BUFF] = { 0 };
size_t	g_buff_i = 0UL;

size_t	g_fmt_i = ~0UL;

char	g_flag = 0;
size_t	g_flag_width = 0UL;

char	*g_data_ptr = NULL;
size_t	g_data_len = 0UL;

static bool			s_pf_parser(char const *const format)
{
	++g_fmt_i;
	g_flag_width = (size_t)ft_atol(&format[g_fmt_i]);
	while (format[g_fmt_i] && F_ISDIGIT(format[g_fmt_i]))
		++g_fmt_i;
	g_flag = format[g_fmt_i];
	return (true);
}

static bool			s_choose_func(va_list *ap)
{
	if (g_flag == 'd')
		return (pf_decimal(ap));
	else if (g_flag == 'p')
		return (pf_address(ap));
	else if ('s' == g_flag || 'c' == g_flag || '%' == g_flag)
		return (pf_string(ap));
	write(STDERR_FILENO, E_INVALID, ft_strlen(E_INVALID));
	return (false);
}

static inline void	s_zero_global_variables(void)
{
	ft_bzero(g_buff, sizeof(char) * MAX_BUFF);
	g_buff_i = 0UL;
	g_fmt_i = ~0UL;
	g_flag = 0;
	g_flag_width = 0UL;
	g_data_ptr = NULL;
	g_data_len = 0UL;
}

int					ft_printf(char const *const format, ...)
{
	bool	is_valid;
	va_list	ap;

	s_zero_global_variables();
	va_start(ap, format);
	is_valid = true;
	while (is_valid && format[++g_fmt_i])
		if (format[g_fmt_i] != '%')
		{
			PUT_CH_BUFF(format[g_fmt_i]);
		}
		else
		{
			is_valid = s_pf_parser(format);
			if (is_valid)
				is_valid = s_choose_func(&ap);
		}
	va_end(ap);
	return (is_valid ? write(STDOUT_FILENO, g_buff, g_buff_i) : 0);
}
