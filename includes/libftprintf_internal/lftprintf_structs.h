/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 22:14:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTPRINTF_STRUCTS_H
# define LFTPRINTF_STRUCTS_H

# ifndef LIBFTPRINTF_INTERNAL_H
#  error "include only libftprintf.h"
# endif

# include <sys/types.h>
# include <stdlib.h>

struct s_lpf_buf_
{
	char *restrict _Nullable	buf;
	size_t						pos;
	size_t						size;
} __attribute__((aligned(__BIGGEST_ALIGNMENT__)));

# ifndef S_DATA_BUF_INIT
#  define S_DATA_BUF_INIT malloc(sizeof(char) * 256UL), 0, 256UL
# endif

struct s_lpf_data_
{
	char *restrict _Nullable	ptr;
	size_t						len;
}  __attribute__((aligned(__BIGGEST_ALIGNMENT__)));

extern void __attribute__((__overloadable__))
lpf_buf_ch_(struct s_lpf_buf_ *restrict _Nonnull buf, char ch);
extern void __attribute__((__overloadable__))
lpf_buf_ch_(struct s_lpf_buf_ *restrict _Nonnull buf, char ch, size_t n);

extern void __attribute__((__overloadable__))
lpf_buf_data_(struct s_lpf_buf_ *restrict _Nonnull buf,
		struct s_lpf_data_ *restrict _Nonnull data);
extern void __attribute__((__overloadable__))
lpf_buf_data_(struct s_lpf_buf_ *restrict _Nonnull buf,
		struct s_lpf_data_ *restrict _Nonnull data,
		size_t len);
extern void __attribute__((__overloadable__))
lpf_buf_data_(struct s_lpf_buf_ *restrict _Nonnull buf,
		const char *restrict _Nonnull str,
		size_t len);

extern void *_Nullable
lpf_buf_free_(struct s_lpf_buf_ *restrict _Nonnull buf);

struct s_lpf_flag_
{
	size_t	width;
	char	symbol;
	int8_t	spec_mask;
	int8_t	type_mask;
	char	_dummy[5] __attribute__((unused));
} __attribute__((aligned(__BIGGEST_ALIGNMENT__)));

# ifndef S_FLAG_INFO_REFRESH
#  define S_FLAG_INFO_REFRESH 0UL, 0, 0, 0, { 0, 0, 0, 0, 0 }
# endif

#endif
