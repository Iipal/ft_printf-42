/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:48:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 13:05:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

inline int	ft_sprintf(char *restrict _Nonnull dst,
				const char *restrict _Nonnull format, ...)
{
	va_list	ap;
	int		out;

	va_start(ap, format);
	out = ft_vsprintf(dst, format, &ap);
	va_end(ap);
	return (out);
}
