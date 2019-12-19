/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf_fsm.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:45:43 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 22:15:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTPRINTF_FSM_H
# define LFTPRINTF_FSM_H

# ifndef LIBFTPRINTF_INTERNAL_H
#  error "include only libftprintf.h"
# endif

# include <stdbool.h>

# include "lftprintf_structs.h"

enum	e_fsm_flag_state
{
	fsm_flag_none,
	fsm_flag_di,
	fsm_flag_s,
	fsm_flag_c,
	fsm_flag_u,
	fsm_flag_p,
	fsm_flag_o,
} __attribute__((packed));

typedef bool (*_Nonnull t_fsm_callback)(struct s_lpf_buf_ *restrict _Nonnull,
									struct s_lpf_flag_ *restrict _Nonnull,
											va_list *restrict _Nonnull);

extern bool
fsm_run_flag(struct s_lpf_buf_ *restrict _Nonnull buf,
			struct s_lpf_flag_ *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap);

extern bool
flag_none(struct s_lpf_buf_ *restrict _Nonnull __attribute__((unused)) buf,
			struct s_lpf_flag_ *restrict _Nonnull __attribute__((unused)) flag,
						va_list *restrict _Nonnull __attribute__((unused)) ap);
extern bool
flag_di(struct s_lpf_buf_ *restrict _Nonnull buf,
		struct s_lpf_flag_ *restrict _Nonnull flag,
					va_list *restrict _Nonnull ap);
extern bool
flag_s(struct s_lpf_buf_ *restrict _Nonnull buf,
		struct s_lpf_flag_ *restrict _Nonnull flag,
					va_list *restrict _Nonnull ap);
extern bool
flag_c(struct s_lpf_buf_ *restrict _Nonnull buf,
		struct s_lpf_flag_ *restrict _Nonnull flag,
					va_list *restrict _Nonnull ap);
extern bool
flag_p(struct s_lpf_buf_ *restrict _Nonnull buf,
		struct s_lpf_flag_ *restrict _Nonnull flag,
					va_list *restrict _Nonnull ap);
extern bool
flag_o(struct s_lpf_buf_ *restrict _Nonnull buf,
		struct s_lpf_flag_ *restrict _Nonnull flag,
					va_list *restrict _Nonnull ap);
extern bool
flag_u(struct s_lpf_buf_ *restrict _Nonnull buf,
		struct s_lpf_flag_ *restrict _Nonnull flag,
					va_list *restrict _Nonnull ap);

#endif
