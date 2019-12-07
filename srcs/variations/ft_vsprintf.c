/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:04:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 17:28:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

inline int	ft_vsprintf(char *dst,
				const char *restrict format,
				va_list *restrict ap)
{
	int	out;

	if ((out = internal_vprintf(format, ap)))
	{
		ft_strncpy(dst, g_buf, g_buf_i);
		dst[g_buf_i] = '\0';
		out = g_buf_i;
	}
	ft_strdel(&g_buf);
	return (out);
}
