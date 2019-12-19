/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_vprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:24:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 22:34:57 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

struct s_lpf_buf_ *_Nullable
	internal_vprintf(const char *restrict _Nonnull format_,
		va_list *restrict _Nonnull ap_)
{
	struct s_lpf_buf_	*buf_;
	struct s_lpf_flag_	flag_;
	size_t				fmt_i;
	bool				is_valid;

	if (!(buf_ = calloc(1UL, sizeof(*buf_))))
		return (NULL);
	*buf_ = (struct s_lpf_buf_) { S_DATA_BUF_INIT };
	fmt_i = ~0UL;
	is_valid = true;
	while (format_[++fmt_i]) {
		if (format_[fmt_i] != '%') {
			lpf_buf_ch_(buf_, format_[fmt_i]);
		} else if (flag_parser(&flag_, format_, &fmt_i)) {
			if (!(is_valid = fsm_run_flag(buf_, &flag_, ap_)))
				break ;
		}
	}
	if (!is_valid)
		buf_ = lpf_buf_free_(buf_);
	return (buf_);
}
