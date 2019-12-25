/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_none.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:52:13 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/25 21:26:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

bool	flag_none(struct s_lpf_buf_ *restrict __attribute__((unused)) buf,
				struct s_lpf_flag_ *restrict __attribute__((unused)) flag,
						va_list *restrict __attribute__((unused)) ap)
{
	return (false);
}
