/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:13:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 21:47:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

int	ft_vfprintf(FILE *stream, const char *restrict format, va_list *restrict ap)
{
	int	out;

	if ((out = internal_vprintf(format, ap)))
		fwrite(g_buf, sizeof(char), g_buf_i, stream);
	ft_strdel(&g_buf);
	return (out);
}
