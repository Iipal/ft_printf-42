/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpf_buf_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:34:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:28:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline void __attribute__((__overloadable__))
	lpf_buf_ch_(struct s_lpf_buf_ *restrict buf, char ch)
{
	if (buf->size <= buf->pos)
	{
		buf->buf = ft_memrealloc(buf->buf, buf->size, buf->size << 1UL);
		buf->size <<= 1UL;
	}
	buf->buf[buf->pos++] = ch;
}

inline void __attribute__((__overloadable__))
	lpf_buf_ch_(struct s_lpf_buf_ *restrict buf, char ch, size_t n)
{
	while (n--)
		lpf_buf_ch_(buf, ch);
}
