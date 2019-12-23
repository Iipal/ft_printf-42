/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:33:42 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:22:22 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

inline int	ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list	ap;
	int		out;

	va_start(ap, format);
	out = ft_vdprintf(fd, format, &ap);
	va_end(ap);
	return (out);
}
