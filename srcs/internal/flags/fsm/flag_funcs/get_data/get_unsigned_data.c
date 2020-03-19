/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unsigned_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:42:39 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:23:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

extern char __attribute__((__const__,__always_inline__))
	*get_unsigned_data(va_list ap, int base, int8_t type)
{
	unsigned long	value = 0;
	char	*out = NULL;

	if (!type || IS_BIT(type, PF_BIT_TYPE_H) || IS_BIT(type, PF_BIT_TYPE_HH)) {
		value = va_arg(ap, unsigned int);
		out = lpf_ultoap_base(value, calloc(24UL, sizeof(char)), base);
	} else if (type) {
		value = va_arg(ap, unsigned long);
		out = lpf_ultoap_base(value, calloc(24UL, sizeof(char)), base);
	}
	return (out);
}
