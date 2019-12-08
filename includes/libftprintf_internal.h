/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:47:29 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_INTERNAL_H
# define LIBFTPRINTF_INTERNAL_H

# include <stddef.h>
# include <limits.h>
# include <inttypes.h>

# include "libft.h"

/*
** global variables and functions to work with global variables:
*/
# include "lftprintf_global_data.h"

/*
** Bit mask for each flag specifications:
*/
# include "lftprintf_bits_masks.h"

/*
** errno:
*/
# include "lftprintf_errno.h"

int
internal_vprintf(const char *restrict format, va_list *restrict ap);

extern bool
pf_flag_parser(const char *restrict format);

extern bool __attribute__((__always_inline__))
pf_get_processing_func(va_list *ap);

extern bool
pf_decimal(va_list *ap);
extern bool
pf_string(va_list *ap);
extern bool
pf_address(va_list *ap);
extern bool
pf_octal(va_list *ap);
extern bool
pf_unsigned(va_list *ap);

extern char __attribute__((__const__,__always_inline__))
*pf_get_signed_data(va_list *ap);
extern char __attribute__((__const__,__always_inline__))
*pf_get_unsigned_data(va_list *ap, int base);

#endif
