/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:08:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 12:53:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_local.h"

bool	pf_decimal(va_list *ap)
{
	size_t const	out = va_arg(*ap, size_t);

	g_data_ptr = ft_i128toa(out);
	g_data_len = ft_strlen(g_data_ptr);
	if (g_flag_width > g_data_len)
	{
		ft_memset(g_buff + g_buff_i, ' ', g_flag_width - g_data_len);
		g_buff_i += g_flag_width - g_data_len;
	}
	ft_strncpy(g_buff + g_buff_i, g_data_ptr, g_data_len);
	g_buff_i += g_data_len;
	ft_strdel(&g_data_ptr);
	return (true);
}
