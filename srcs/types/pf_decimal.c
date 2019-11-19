/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:08:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/19 15:43:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pf_local.h"

bool	pf_decimal(va_list *ap)
{
	const size_t	out = va_arg(*ap, size_t);
	const int		fill_width_ch = IS_BIT(g_flag_spec_mask, FTPRINTF_BIT_DOT)
									? '0' : ' ';

	g_data_ptr = ft_i128toa(out);
	g_data_len = ft_strlen(g_data_ptr);
	if (IS_BIT(g_flag_spec_mask, FTPRINTF_BIT_MINUS) && fill_width_ch != '0')
		pf_put_str_buf();
	if (g_flag_width > g_data_len)
		pf_put_ch_buf(fill_width_ch, g_flag_width - g_data_len);
	if (!IS_BIT(g_flag_spec_mask, FTPRINTF_BIT_MINUS) || fill_width_ch == '0')
		pf_put_str_buf();
	ft_strdel(&g_data_ptr);
	return (true);
}
