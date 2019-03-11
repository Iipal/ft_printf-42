/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:33:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/11 16:33:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_ctype.h"

void	ft_strtoupper(string str)
{
	long	i;

	i = -1;
	while (str[++i])
		if (ft_islower(str[i]))
			str[i] = ft_toupper(str[i]);
}
