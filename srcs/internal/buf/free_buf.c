/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_buf.c                                     :+:      :+:    :+:   */
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

inline void *_Nullable
	free_buf(struct s_data_buf *restrict _Nonnull buf)
{
	if (buf->buf)
		ft_strdel(&buf->buf);
	free(buf);
	return (NULL);
}
