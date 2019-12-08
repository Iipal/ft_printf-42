/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:07:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 14:21:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

inline int	ft_vsnprintf(char *dst,
				size_t len,
				const char *restrict format,
				va_list *restrict ap)
{
	int	out;

	if ((out = internal_vprintf(format, ap)))
	{
		if (len <= (size_t)out)
			out = len;
		ft_strncpy(dst, g_buf, out);
		dst[out] = '\0';
	}
	ft_strdel(&g_buf);
	return (out);
}
