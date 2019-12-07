/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:16:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/07 21:47:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libftprintf_internal.h"

inline int	ft_vprintf(const char *restrict format, va_list *restrict ap)
{
	return (ft_vdprintf(STDOUT_FILENO, format, ap));
}
