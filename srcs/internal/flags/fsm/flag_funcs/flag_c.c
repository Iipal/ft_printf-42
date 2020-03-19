/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:04:29 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:13:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

bool	flag_c(struct s_lpf_buf_ *restrict buf,
				struct s_lpf_flag_ *restrict flag,
				va_list ap)
{
	lpf_buf_ch_(buf, (flag->symbol == '%') ? '%' : va_arg(ap, int));
	return (true);
}
