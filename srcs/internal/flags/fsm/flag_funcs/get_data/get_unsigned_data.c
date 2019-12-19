/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:42:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:34:31 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

extern char __attribute__((__const__,__always_inline__)) *_Nullable
	get_unsigned_data(va_list *restrict _Nonnull ap, int base, int8_t type)
{
	if (!type || IS_BIT(type, PF_BIT_TYPE_H) || IS_BIT(type, PF_BIT_TYPE_HH))
		return (ft_ultoa(va_arg(*ap, unsigned int), ft_strnew(24UL), base));
	else if (type)
		return (ft_ultoa(va_arg(*ap, unsigned long), ft_strnew(24UL), base));
	return (NULL);
}
