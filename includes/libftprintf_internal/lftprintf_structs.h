/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:30:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTPRINTF_STRUCTS_H
# define LFTPRINTF_STRUCTS_H

# ifndef LIBFTPRINTF_INTERNAL_H
#  error "include only libftprintf.h"
# endif

# include <sys/types.h>
# include <stdlib.h>

struct s_data_buf
{
	char *restrict _Nullable	buf;
	size_t						pos;
	size_t						size;
} __attribute__((aligned(__BIGGEST_ALIGNMENT__)));

# ifndef S_DATA_BUF_INIT
#  define S_DATA_BUF_INIT malloc(sizeof(char) * 256UL), 0, 256UL
# endif

struct s_flag_data
{
	char *restrict _Nullable	ptr;
	size_t						len;
}  __attribute__((aligned(__BIGGEST_ALIGNMENT__)));

extern void __attribute__((__overloadable__))
buf_add_ch(struct s_data_buf *restrict _Nonnull buf, char ch);
extern void __attribute__((__overloadable__))
buf_add_ch(struct s_data_buf *restrict _Nonnull buf, char ch, size_t n);

extern void __attribute__((__overloadable__))
buf_add_data(struct s_data_buf *restrict _Nonnull buf,
		struct s_flag_data *restrict _Nonnull data);
extern void __attribute__((__overloadable__))
buf_add_data(struct s_data_buf *restrict _Nonnull buf,
		struct s_flag_data *restrict _Nonnull data,
		size_t len);
extern void __attribute__((__overloadable__))
buf_add_data(struct s_data_buf *restrict _Nonnull buf,
		const char *restrict _Nonnull str,
		size_t len);

extern void *_Nullable
free_buf(struct s_data_buf *restrict _Nonnull buf);

struct s_flag_info
{
	size_t	width;
	int		symbol;
	int8_t	spec_mask;
	int8_t	type_mask;
	char	_dummy __attribute__((unused));
} __attribute__((aligned(__BIGGEST_ALIGNMENT__)));

# ifndef S_FLAG_INFO_REFRESH
#  define S_FLAG_INFO_REFRESH 0UL, 0, 0, 0, 0
# endif

#endif
