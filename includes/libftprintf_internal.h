/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:29:38 by tmaluh           ###   ########.fr       */
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

# include "lftprintf_structs.h"
# include "lftprintf_bits_masks.h"
# include "lftprintf_errno.h"

struct s_data_buf *_Nullable
internal_vprintf(const char *restrict _Nonnull format,
					va_list *restrict _Nonnull ap);

extern bool
flag_parser(struct s_flag_info *restrict _Nonnull flag,
					const char *restrict _Nonnull format,
						size_t *restrict _Nonnull fmt_i);

extern bool
run_flag(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap);

extern bool
flag_di(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap);
extern bool
flag_sc(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap);
extern bool
flag_p(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap);
extern bool
flag_o(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap);
extern bool
flag_u(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap);

extern char *_Nullable
get_signed_data(va_list *restrict _Nonnull ap, int8_t type);
extern char *_Nullable
get_unsigned_data(va_list *restrict _Nonnull ap, int base, int8_t type);

#endif
