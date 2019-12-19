/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpf_ch_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:34:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:29:38 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline void __attribute__((__overloadable__))
	buf_add_ch(struct s_data_buf *restrict _Nonnull buf, char ch)
{
	if (buf->size <= buf->pos)
	{
		buf->buf = ft_memrealloc(buf->buf, buf->size, buf->size * 2UL);
		buf->size *= 2UL;
	}
	buf->buf[buf->pos++] = ch;
}

inline void __attribute__((__overloadable__))
	buf_add_ch(struct s_data_buf *restrict _Nonnull buf, char ch, size_t n)
{
	while (n--)
		buf_add_ch(buf, ch);
}
