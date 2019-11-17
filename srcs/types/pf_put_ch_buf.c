/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_ch_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:34:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/17 22:29:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

void	pf_put_ch_buf(char c)
{
	if (g_max_buf <= g_buf_i)
	{
		g_buf = ft_memrealloc(g_buf, g_max_buf, g_max_buf * 2);
		g_max_buf *= 2;
	}
	g_buf[g_buf_i++] = c;
}
