/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:08:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/17 22:16:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_local.h"

bool	pf_decimal(va_list *ap)
{
	size_t const	out = va_arg(*ap, size_t);

	g_data_ptr = ft_i128toa(out);
	g_data_len = ft_strlen(g_data_ptr);
	if (IS_BIT(g_flag_spec_mask, FTPRINTF_BIT_MINUS))
		pf_put_gstr_buf();
	if (g_flag_width > g_data_len)
	{
		ft_memset(g_buf + g_buf_i, ' ', g_flag_width - g_data_len);
		g_buf_i += g_flag_width - g_data_len;
	}
	if (!IS_BIT(g_flag_spec_mask, FTPRINTF_BIT_MINUS))
		pf_put_gstr_buf();
	ft_strdel(&g_data_ptr);
	return (true);
}
