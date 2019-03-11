/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_one_of_n.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 08:33:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/11 10:50:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

bool	ft_is_one_of_n(int cmp, int n, ...)
{
	va_list	ap;

	va_start(ap, n);
	while (n--)
		if (cmp == va_arg(ap, int))
		{
			va_end(ap);
			return (true);
		}
	va_end(ap);
	return (false);
}
