/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signed_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:40:54 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:31:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline char __attribute__((__const__,__always_inline__))
	*get_signed_data(va_list ap, int8_t type)
{
	char	*out = NULL;

	if (!type || IS_BIT(type, PF_BIT_TYPE_H) || IS_BIT(type, PF_BIT_TYPE_HH)) {
		out = lpf_ultoap_base(va_arg(ap, int), calloc(14, sizeof(char)), 10);
	} else if (type) {
		out = lpf_ultoap_base(va_arg(ap, long), calloc(14, sizeof(char)), 10);
	}
	return (out);
}
