/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 11:17:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/11 18:23:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool	add_choose_out_str(string *out_str, char symbol, __int128 out)
{
	if (symbol == 'o')
	{
		_NOTISD(E_ALLOC, *out_str = ft_itoa_base(out, 8), exit(1), false);
	}
	else
		_NOTISD(E_ALLOC, *out_str = ft_maxitoa(out), exit(1), false);
	return (true);
}
