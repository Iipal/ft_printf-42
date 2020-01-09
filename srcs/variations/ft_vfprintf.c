/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:13:32 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:23:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

int	ft_vfprintf(FILE *restrict stream,
		const char *restrict format,
		va_list *restrict ap)
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
