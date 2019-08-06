/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/06 11:48:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_local.h"

static void	s_out_data(void)
{
	size_t	i;

	i = ~0UL;
	while (g_flag_width + g_data_len > ++i)
		PUT_CH_BUFF(g_flag_width > i ? ' ' : g_data_ptr[i - g_flag_width]);
}

static void	s_choose_data(va_list *ap, char *c)
{
	if ('s' == g_flag)
		g_data_ptr = (char*)va_arg(*ap, char*);
	else if ('%' == g_flag)
		*c = '%';
	else
		*c = (char)va_arg(*ap, int);
	if ((!g_data_ptr || !*g_data_ptr) && 's' == g_flag)
	{
		ft_strcpy(g_buff + g_buff_i, "(null)");
		g_buff_i += sizeof("(null)");
	}
}

bool		pf_string(va_list *ap)
{
	char	ch;
	bool	is_str;

	ch = 0;
	is_str = !(g_flag == 'c' || g_flag == '%');
	s_choose_data(ap, &ch);
	g_data_len = is_str ? ft_strlen(g_data_ptr) : 1;
	if (is_str)
		s_out_data();
	else
		PUT_CH_BUFF(ch);
	return (true);
}
