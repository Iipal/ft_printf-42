/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:04:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:27:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline bool
	flag_c(struct s_lpf_buf_ *restrict buf,
			struct s_lpf_flag_ *restrict flag,
						va_list *restrict ap)
{
	if (flag->symbol == '%')
		lpf_buf_ch_(buf, '%');
	else
		lpf_buf_ch_(buf, va_arg(*ap, int));
	return (true);
}
