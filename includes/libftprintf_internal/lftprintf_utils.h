/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 21:24:58 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:30:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTPRINTF_UTILS_H
# define LFTPRINTF_UTILS_H

# ifndef LIBFTPRINTF_INTERNAL_H
#  error "include only libftprintf.h"
# endif

# define LPF_ABS(val) __extension__({ \
	__typeof__(val) __val = (val); \
	0 > __val ? -__val : __val; })

char	*lpf_ultoap_base(unsigned long num, char *restrict dst, int base);

#endif
