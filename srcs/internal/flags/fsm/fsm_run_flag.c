/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm_run_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:41:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 22:35:44 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

static inline enum e_fsm_flag_state __attribute__((__const__))
	s_get_index(char symbol)
{
	static const char	arr[16] = { 'd', 'i', 's', 'c', '%', 'u', 'p', 'o', 0 };
	ptrdiff_t			i;

	i = 0L;
	while (arr[i] && symbol != arr[i])
		++i;
	switch (i) {
		case 0L:
		case 1L: return (fsm_flag_di);
		case 2L: return (fsm_flag_s);
		case 3L:
		case 4L: return (fsm_flag_c);
		case 5L: return (fsm_flag_u);
		case 6L: return (fsm_flag_p);
		case 7L: return (fsm_flag_o);
		default: return (fsm_flag_none);
	}
}

inline bool __attribute__((always_inline))
	fsm_run_flag(struct s_lpf_buf_ *restrict _Nonnull buf,
				struct s_lpf_flag_ *restrict _Nonnull flag,
							va_list *restrict _Nonnull ap)
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
