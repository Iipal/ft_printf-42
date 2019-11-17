/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/17 22:35:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

static inline void	s_put_str_to_buf(void)
{
	static ssize_t	width;

	width = (ssize_t)g_flag_width - (ssize_t)g_data_len;
	if (IS_BIT(g_flag_spec_mask, FTPRINTF_BIT_MINUS))
	{
		pf_put_gstr_buf();
		if (0 < width)
			pf_put_n_ch_buf(' ', g_flag_width - g_data_len);
	}
	else
	{
		if (0 < width)
			pf_put_n_ch_buf(' ', g_flag_width - g_data_len);
		pf_put_gstr_buf();
	}
}

static inline void	s_choose_data(va_list *ap, char *c)
{
	if ('s' == g_flag)
		g_data_ptr = (char*)va_arg(*ap, char*);
	else if ('%' == g_flag)
		*c = '%';
	else
		*c = (char)va_arg(*ap, int);
	if (!g_data_ptr && 's' == g_flag)
		g_data_ptr = "(null)";
}

bool				pf_string(va_list *ap)
{
	static char	ch;
	static bool	is_str;

	ch = 0;
	is_str = !(g_flag == 'c' || g_flag == '%');
	s_choose_data(ap, &ch);
	g_data_len = is_str ? ft_strlen(g_data_ptr) : 1;
	if (is_str)
		s_put_str_to_buf();
	else
		pf_put_ch_buf(ch);
	return (true);
}
