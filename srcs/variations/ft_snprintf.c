/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:51:57 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 13:05:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

inline int	ft_snprintf(char *restrict _Nonnull dst,
				size_t len,
				const char *restrict _Nonnull format, ...)
{
	va_list	ap;
	int		out;

	va_start(ap, format);
	out = ft_vsnprintf(dst, len, format, &ap);
	va_end(ap);
	return (out);
}
