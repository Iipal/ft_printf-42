/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:24:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_INTERNAL_H
# define LIBFTPRINTF_INTERNAL_H

# ifndef LIBFTPRINTF_INTERNAL
#  error "include only libftprintf.h"
# endif

# define _GNU_SOURCE

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <inttypes.h>

# include "lftprintf_fsm.h"
# include "lftprintf_bits.h"
# include "lftprintf_errno.h"
# include "lftprintf_utils.h"

struct s_lpf_buf_	*internal_vprintf(const char *restrict fmt, va_list ap);

struct s_lpf_flag_	*flag_parser(const char *restrict format,
						size_t *restrict fmt_i);

extern char	*get_signed_data(va_list ap, int8_t type);
extern char	*get_unsigned_data(va_list ap, int base, int8_t type);

#endif
