/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:22:07 by tmaluh           ###   ########.fr       */
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
	char *restrict	buf;
	size_t			pos;
	size_t			size;
} __attribute__((aligned(__BIGGEST_ALIGNMENT__)));

# ifndef S_DATA_BUF_INIT
#  define S_DATA_BUF_INIT malloc(sizeof(char) * 256UL), 0, 256UL
# endif

struct s_lpf_data_
{
	char *restrict	ptr;
	size_t			len;
}  __attribute__((aligned(__BIGGEST_ALIGNMENT__)));

extern void __attribute__((__overloadable__))
lpf_buf_ch_(struct s_lpf_buf_ *restrict buf, char ch);
extern void __attribute__((__overloadable__))
lpf_buf_ch_(struct s_lpf_buf_ *restrict buf, char ch, size_t n);

extern void __attribute__((__overloadable__))
lpf_buf_data_(struct s_lpf_buf_ *restrict buf,
		struct s_lpf_data_ *restrict data);
extern void __attribute__((__overloadable__))
lpf_buf_data_(struct s_lpf_buf_ *restrict buf,
		struct s_lpf_data_ *restrict data,
		size_t len);
extern void __attribute__((__overloadable__))
lpf_buf_data_(struct s_lpf_buf_ *restrict buf,
					const char *restrict str,
					size_t len);

extern void *
lpf_buf_free_(struct s_lpf_buf_ *restrict buf);

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
