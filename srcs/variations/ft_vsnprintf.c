/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:07:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:29:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline int	ft_vsnprintf(char *restrict _Nonnull dst,
				size_t len,
				const char *restrict _Nonnull format,
				va_list *restrict _Nonnull ap)
{
	struct s_data_buf	*buf;
	int					out;

	out = 0;
	if (!(buf = internal_vprintf(format, ap)))
		return (out);
	out = buf->pos;
	if (len <= buf->pos)
		out = len;
	ft_strncpy(dst, buf->buf, out);
	dst[out] = '\0';
	free_buf(buf);
	return (out);
}
