/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_gstr_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:52:22 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/17 21:57:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_local.h"

/*
** This funcion put string from global variables(g_data_ptr) to buffer.
*/
void	pf_put_gstr_buf(void)
{
	size_t	i;

	i = ~0UL;
	while (g_data_len > ++i)
		pf_put_ch_buf(g_data_ptr[i]);
}
