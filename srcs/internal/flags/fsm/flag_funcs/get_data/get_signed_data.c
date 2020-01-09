/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signed_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:40:54 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:27:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline char __attribute__((__const__,__always_inline__))
	*get_signed_data(va_list *restrict ap, int8_t type)
{
	if (!type || IS_BIT(type, PF_BIT_TYPE_H) || IS_BIT(type, PF_BIT_TYPE_HH))
		return (ft_itoa(va_arg(*ap, int)));
	else if (type)
		return (ft_ltoa(va_arg(*ap, long)));
	return (NULL);
}
