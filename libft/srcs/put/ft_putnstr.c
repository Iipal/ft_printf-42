/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:28:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/12 18:59:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_put.h"
#include "../../includes/lft_str.h"

void	ft_putnstr(char *str, size_t n)
{
	size_t	length;

	if (n > 0)
	{
		length = ft_strlen(str);
		if (n > length)
			write(1, str, length);
		else
			write(1, str, n);
	}
}
