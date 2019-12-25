/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_run_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:41:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/25 21:34:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

inline bool __attribute__((always_inline))
	fsm_run_flag(struct s_lpf_buf_ *restrict buf,
				struct s_lpf_flag_ *restrict flag,
							va_list *restrict ap)
{
	const static t_fsm_callback	callback_table[8] = {
		[fsm_flag_none] = flag_none,
		[fsm_flag_di]   = flag_di,
		[fsm_flag_s]    = flag_s,
		[fsm_flag_c]    = flag_c,
		[fsm_flag_u]    = flag_u,
		[fsm_flag_p]    = flag_p,
		[fsm_flag_o]    = flag_o,
		[7]             = NULL
	};
	enum e_fsm_flag_state	fn_i;

	switch (flag->symbol) {
		case 'd':
		case 'i': fn_i = fsm_flag_di; break;
		case 's': fn_i = fsm_flag_s; break;
		case 'c':
		case '%': fn_i = fsm_flag_c; break;
		case 'u': fn_i = fsm_flag_u; break;
		case 'p': fn_i = fsm_flag_p; break;
		case 'o': fn_i = fsm_flag_o; break;
		default: fn_i = fsm_flag_none; break;
	}
	if (!(callback_table[fn_i](buf, flag, ap))) {
		ft_putendl_fd(E_PF_INVALID, STDERR_FILENO);
		return (false);
	}
	return (true);
}
