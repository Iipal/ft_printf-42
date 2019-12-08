/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_ch_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:34:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:39:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

inline void __attribute__((__overloadable__))
	pf_put_ch_buf(char ch)
{
	if (g_max_buf <= g_buf_i)
	{
		g_buf = ft_memrealloc(g_buf, g_max_buf, g_max_buf + DEFAULT_BUF_SIZE);
		g_max_buf += DEFAULT_BUF_SIZE;
	}
	g_buf[g_buf_i++] = ch;
}

inline void __attribute__((__overloadable__))
	pf_put_ch_buf(char ch, size_t n)
{
	while (n--)
		pf_put_ch_buf(ch);
}
