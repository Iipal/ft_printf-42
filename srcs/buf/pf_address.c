/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/18 01:26:37 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_local.h"

bool	pf_address(va_list *ap)
{
	intptr_t	addr;

	addr = (intptr_t)va_arg(*ap, void*);
	if (!(g_data_ptr = ft_ltoa_base(addr, 16)))
		return (false);
	g_data_len = ft_strlen(g_data_ptr);
	ft_strcpy(g_buf + g_buf_i, "0x");
	g_buf_i += sizeof("0x");
	ft_strncpy(g_buf + g_buf_i, g_data_ptr, g_data_len);
	g_buf_i += g_data_len;
	ft_strdel(&g_data_ptr);
	return (true);
}
