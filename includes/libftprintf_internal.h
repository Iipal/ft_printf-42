/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:20:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_INTERNAL_H
# define LIBFTPRINTF_INTERNAL_H

# ifndef LIBFTPRINTF_INTERNAL
#  error "include only libftprintf.h"
# endif

# include <stddef.h>
# include <limits.h>
# include <inttypes.h>

# include "libft.h"

# include "lftprintf_fsm.h"
# include "lftprintf_bits_masks.h"
# include "lftprintf_errno.h"

struct s_lpf_buf_
*internal_vprintf(const char *restrict format,
					va_list *restrict ap);

bool
flag_parser(struct s_lpf_flag_ *restrict flag,
					const char *restrict format,
						size_t *restrict fmt_i);

extern char
*get_signed_data(va_list *restrict ap, int8_t type);
extern char
*get_unsigned_data(va_list *restrict ap, int base, int8_t type);

#endif
