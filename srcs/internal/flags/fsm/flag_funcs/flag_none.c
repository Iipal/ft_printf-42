/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_none.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:52:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 22:17:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline bool
	flag_none(struct s_lpf_buf_ *restrict _Nonnull __attribute__((unused)) buf,
			struct s_lpf_flag_ *restrict _Nonnull __attribute__((unused)) flag,
					va_list *restrict _Nonnull __attribute__((unused)) ap)
{
	return (false);
}
