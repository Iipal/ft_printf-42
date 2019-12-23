/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:48:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:22:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

inline int	ft_sprintf(char *restrict dst, const char *restrict format, ...)
{
	va_list	ap;
	int		out;

	va_start(ap, format);
	out = ft_vsprintf(dst, format, &ap);
	va_end(ap);
	return (out);
}
