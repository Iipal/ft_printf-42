/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 22:43:25 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_INTERNAL_H
# define LIBFTPRINTF_INTERNAL_H

# include <stddef.h>
# include <limits.h>
# include <inttypes.h>

# include "libft.h"

/*
** global variables:
*/
# include "global_vars.h"

/*
** Bit mask for each flag specifications:
*/
# include "bits_masks.h"

/*
** Errno:
*/
# include "errno.h"

extern bool
pf_flag_parser(const char *restrict format);

extern bool
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

extern char
*pf_get_signed_data(va_list *ap);
extern char
*pf_get_unsigned_data(va_list *ap, int base);

#endif
