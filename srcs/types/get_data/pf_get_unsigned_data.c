/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_unsigned_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:42:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/25 21:36:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

inline char	*pf_get_unsigned_data(va_list *ap)
{
	g_data_ptr = ft_strnew(24UL);
		g_data_ptr = ft_strnew(24UL);
	if (!g_flag_type_mask
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_H)
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_HH))
		return (ft_ultoa(va_arg(*ap, unsigned int), g_data_ptr, 8));
	else if (g_flag_type_mask)
		return (ft_ultoa(va_arg(*ap, unsigned long), g_data_ptr, 8));
	return (NULL);
}
