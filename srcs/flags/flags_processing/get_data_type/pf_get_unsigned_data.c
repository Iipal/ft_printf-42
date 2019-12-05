/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_unsigned_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:42:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 22:44:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

inline char	*pf_get_unsigned_data(va_list *ap, int base)
{
	g_data_ptr = ft_strnew(24UL);
	if (!g_flag_type_mask
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_H)
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_HH))
		return (ft_ultoa(va_arg(*ap, unsigned int), g_data_ptr, base));
	else if (g_flag_type_mask)
		return (ft_ultoa(va_arg(*ap, unsigned long), g_data_ptr, base));
	return (NULL);
}
