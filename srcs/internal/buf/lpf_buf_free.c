/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpf_buf_free_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:52:59 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:22:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline void
	*lpf_buf_free_(struct s_lpf_buf_ *restrict buf)
{
	free(buf->buf);
	buf->buf = NULL;
	free(buf);
	buf = NULL;
	return (NULL);
}
