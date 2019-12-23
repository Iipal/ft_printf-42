/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:25:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:23:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline int
ft_vdprintf(int fd, const char *restrict format, va_list *restrict ap)
{
	struct s_lpf_buf_	*buf;
	int					out;

	out = 0;
	if (!(buf = internal_vprintf(format, ap)))
		return (out);
	out = buf->pos;
	write(fd, buf->buf, out);
	buf = lpf_buf_free_(buf);
	return (out);
}
