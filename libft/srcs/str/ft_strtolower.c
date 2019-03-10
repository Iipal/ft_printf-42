/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:16:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/10 19:23:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#include "../../includes/lft_ctype.h"

void	ft_strtolower(string str)
{
	long	i;

	i = -1;
	while (str[++i])
		if (ft_isupper(str[i]))
			str[i] = ft_tolower(str[i]);
}
