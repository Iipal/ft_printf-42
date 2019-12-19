/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:04:29 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 22:12:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline bool
	flag_c(struct s_lpf_buf_ *restrict _Nonnull buf,
			struct s_lpf_flag_ *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap)
{
	if (flag->symbol == '%')
		lpf_buf_ch_(buf, '%');
	else
		lpf_buf_ch_(buf, va_arg(*ap, int));
	return (true);
}
