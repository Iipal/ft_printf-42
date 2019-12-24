/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_run_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:41:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/24 01:37:00 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

static inline enum e_fsm_flag_state __attribute__((__const__))
	s_get_index(char symbol)
{
	static const char					arr[16] = "disc%upo";
	static const enum e_fsm_flag_state	state_table[16] = {
		[0] = fsm_flag_di,
		[1] = fsm_flag_di,
		[2] = fsm_flag_s,
		[3] = fsm_flag_c,
		[4] = fsm_flag_c,
		[5] = fsm_flag_u,
		[6] = fsm_flag_p,
		[7] = fsm_flag_o,
		[8 ... 15] = fsm_flag_none
	};

	return (state_table[ft_strchrnul(arr, symbol) - arr]);
}

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

	if (!(callback_table[s_get_index(flag->symbol)](buf, flag, ap))) {
		ft_putendl_fd(E_PF_INVALID, STDERR_FILENO);
		return (false);
	}
	return (true);
}
