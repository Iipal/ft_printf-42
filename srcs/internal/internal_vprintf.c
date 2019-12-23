/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_vprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:24:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

struct s_lpf_buf_
	*internal_vprintf(const char *restrict format,
						va_list *restrict ap)
{
	struct s_lpf_buf_	*buf;
	struct s_lpf_flag_	flag;
	size_t				fmt_i;
	bool				is_valid;

	if (!(buf = calloc(1UL, sizeof(*buf))))
		return (NULL);
	*buf = (struct s_lpf_buf_) { S_DATA_BUF_INIT };
	fmt_i = ~0UL;
	is_valid = true;
	while (format[++fmt_i]) {
		if (format[fmt_i] != '%') {
			lpf_buf_ch_(buf, format[fmt_i]);
		} else if (flag_parser(&flag, format, &fmt_i)) {
			if (!(is_valid = fsm_run_flag(buf, &flag, ap)))
				break ;
		}
	}
	if (!is_valid)
		buf = lpf_buf_free_(buf);
	return (buf);
}
