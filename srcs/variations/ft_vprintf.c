/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:16:01 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:23:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

inline int	ft_vprintf(const char *restrict format, va_list *restrict ap)
{
	return (ft_vfprintf(stdout, format, ap));
}
