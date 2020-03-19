/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:51:57 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:03:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_snprintf(char *restrict dst, size_t len,
		const char *restrict format, ...)
{
	va_list	ap;
	int		out;

	va_start(ap, format);
	out = ft_vsnprintf(dst, len, format, ap);
	va_end(ap);
	return (out);
}
