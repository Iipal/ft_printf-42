/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:13:32 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:02:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

int	ft_vfprintf(FILE *restrict stream, const char *restrict format, va_list ap)
{
	struct s_lpf_buf_	*buf;
	int					out;

	out = 0;
	if (!(buf = internal_vprintf(format, ap)))
		return (out);
	out = buf->pos;
	fwrite(buf->buf, sizeof(char), out, stream);
	buf = lpf_buf_free_(buf);
	return (out);
}
