/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 23:55:07 by tmaluh           ###   ########.fr       */
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

struct s_lpf_buf_ *_Nullable
internal_vprintf(const char *restrict _Nonnull format,
					va_list *restrict _Nonnull ap);

bool
flag_parser(struct s_lpf_flag_ *restrict _Nonnull flag,
					const char *restrict _Nonnull format,
						size_t *restrict _Nonnull fmt_i);

extern char *_Nullable
get_signed_data(va_list *restrict _Nonnull ap, int8_t type);
extern char *_Nullable
get_unsigned_data(va_list *restrict _Nonnull ap, int base, int8_t type);

#endif
