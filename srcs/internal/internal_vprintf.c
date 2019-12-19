/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_vprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 17:43:13 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

struct s_data_buf *_Nullable
	internal_vprintf(const char *restrict _Nonnull format,
		va_list *restrict _Nonnull ap)
{
	struct s_data_buf	*buf;
	struct s_flag_info	flag;
	size_t				fmt_i;
	bool				is_valid;

	if (!(buf = calloc(1UL, sizeof(*buf))))
		return (NULL);
	*buf = (struct s_data_buf) { S_DATA_BUF_INIT };
	flag = (struct s_flag_info) { S_FLAG_INFO_REFRESH };
	fmt_i = ~0UL;
	is_valid = true;
	while (is_valid && format[++fmt_i])
		if (format[fmt_i] != '%')
			buf_add_ch(buf, format[fmt_i]);
		else if ((is_valid = flag_parser(&flag, format, &fmt_i)))
			is_valid = run_flag(buf, &flag, ap);
	if (!is_valid)
		buf = free_buf(buf);
	return (buf);
}
