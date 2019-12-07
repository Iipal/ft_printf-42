/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:04:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 21:47:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

inline int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		out;

	va_start(ap, format);
	out = ft_vdprintf(STDOUT_FILENO, format, &ap);
	va_end(ap);
	return (out);
}
