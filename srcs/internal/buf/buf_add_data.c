/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_add_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:55:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:35:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline void __attribute__((__overloadable__))
	buf_add_data(struct s_data_buf *restrict _Nonnull buf,
		struct s_flag_data *restrict _Nonnull data)
{
	size_t	i;

	i = ~0UL;
	while (data->len > ++i)
		buf_add_ch(buf, data->ptr[i]);
}

inline void __attribute__((__overloadable__))
	buf_add_data(struct s_data_buf *restrict _Nonnull buf,
		struct s_flag_data *restrict _Nonnull data,
		size_t len)
{
	size_t	i;

	i = ~0UL;
	if (len > data->len)
		len = data->len;
	while (len > ++i)
		buf_add_ch(buf, data->ptr[i]);
}

inline void __attribute__((__overloadable__))
	buf_add_data(struct s_data_buf *restrict _Nonnull buf,
		const char *restrict _Nonnull str,
		size_t len)
{
	size_t	i;

	i = ~0UL;
	while (len > ++i)
		buf_add_ch(buf, str[i]);
}
