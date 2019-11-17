/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_str_buf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:55:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/17 21:57:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

void	pf_put_str_buf(const char *restrict str, size_t len)
{
	size_t	i;

	i = ~0UL;
	while (len > ++i)
		pf_put_ch_buf(str[i]);
}
