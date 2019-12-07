/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:25:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 17:27:47 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

inline int	ft_vdprintf(int fd,
				const char *restrict format,
				va_list *restrict ap)
{
	int	out;

	if ((out = internal_vprintf(format, ap)))
		write(fd, g_buf, g_buf_i);
	ft_strdel(&g_buf);
	return (out);
}
