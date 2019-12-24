/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_vprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/24 01:30:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

struct s_lpf_buf_
	*internal_vprintf(const char *restrict fmt, va_list *restrict ap)
{
	struct s_lpf_buf_	*buf;
	size_t				fmt_i;
	bool				is_valid;

	if (!(buf = calloc(1UL, sizeof(*buf))))
		return (NULL);
	*buf = (struct s_lpf_buf_) { S_DATA_BUF_INIT };
	fmt_i = ~0UL;
	is_valid = true;
	while (fmt[++fmt_i]) {
		if (fmt[fmt_i] != '%') {
			lpf_buf_ch_(buf, fmt[fmt_i]);
		} else {
			if (!(is_valid = fsm_run_flag(buf, flag_parser(fmt, &fmt_i), ap)))
				break ;
		}
	}
	if (!is_valid)
		buf = lpf_buf_free_(buf);
	return (buf);
}
