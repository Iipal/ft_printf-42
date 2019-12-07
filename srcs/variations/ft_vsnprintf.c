/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:07:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 17:28:20 by tmaluh           ###   ########.fr       */
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
		ft_strncpy(dst, g_buf, len);
		dst[g_buf_i] = '\0';
		out = g_buf_i;
	}
	ft_strdel(&g_buf);
	return ((int)out);
}