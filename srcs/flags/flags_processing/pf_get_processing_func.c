/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_processing_func.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:41:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:12:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

static inline bool __attribute__((__const__,__always_inline__))
	invalid(va_list *ap)
{
	return (!ap);
}

static inline bool __attribute__((__const__,__always_inline__))
	s_run_func(const size_t index, va_list *ap)
{
	static bool	(*fn[])(va_list*) = { invalid, pf_decimal, pf_string,
						pf_address, pf_octal, pf_unsigned, NULL, NULL };

	return (fn[index](ap));
}

static inline size_t __attribute__((__const__))
	s_get_func_index(void)
{
	static const char	arr[16] = { 'd', 'i', 's', 'c', '%', 'p', 'o', 'u', 0 };
	ptrdiff_t			i;

	i = 0L;
	while (arr[i] && g_flag != arr[i])
		++i;
	if (2L > i)
		return (1L);
	else if (5L > i)
		return (2L);
	else if (8L > i)
		return (i - 2L);
	else
		return (0L);
}

inline bool __attribute__((__always_inline__))
	pf_get_processing_func(va_list *ap)
{
	bool	ret;

	ret = s_run_func(s_get_func_index(), ap);
	refresh_flag_global_data();
	if (!ret)
		ft_putendl_fd(E_PF_INVALID, STDERR_FILENO);
	return (ret);
}
