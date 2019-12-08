/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_unsigned_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:42:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:19:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

inline char __attribute__((__const__,__always_inline__))
	*pf_get_unsigned_data(va_list *ap, int base)
{
	if (!g_flag_type_mask
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_H)
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_HH))
		return (ft_ultoa(va_arg(*ap, unsigned int), ft_strnew(24UL), base));
	else if (g_flag_type_mask)
		return (ft_ultoa(va_arg(*ap, unsigned long), ft_strnew(24UL), base));
	return (NULL);
}
