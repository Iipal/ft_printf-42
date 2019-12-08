/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_signed_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:40:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:14:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

inline char __attribute__((__const__,__always_inline__))
	*pf_get_signed_data(va_list *ap)
{
	if (!g_flag_type_mask
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_H)
	|| IS_BIT(g_flag_type_mask, PF_BIT_TYPE_HH))
		return (ft_itoa(va_arg(*ap, int)));
	else if (g_flag_type_mask)
		return (ft_ltoa(va_arg(*ap, long)));
	return (NULL);
}
