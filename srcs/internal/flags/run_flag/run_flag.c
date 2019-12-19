/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpf_run_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:41:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/19 15:32:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

static inline bool __attribute__((__const__,__always_inline__))
	invalid(struct s_data_buf *restrict _Nonnull __attribute__((unused)) buf,
			struct s_flag_info *restrict _Nonnull __attribute__((unused)) flag,
						va_list *restrict _Nonnull __attribute__((unused)) ap)
{
	return (false);
}

static inline bool __attribute__((__const__,__always_inline__))
	s_run(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap,
						const size_t index)
{
	static bool	(*fn[])(struct s_data_buf *restrict _Nonnull,
		struct s_flag_info *restrict _Nonnull,
		va_list *restrict _Nonnull) = { invalid, flag_di, flag_sc, flag_p,
											flag_o, flag_u, NULL, NULL };

	return (fn[index](buf, flag, ap));
}

static inline size_t __attribute__((__const__))
	s_get_func_index(char symbol)
{
	static const char	arr[16] = { 'd', 'i', 's', 'c', '%', 'p', 'o', 'u', 0 };
	ptrdiff_t			i;

	i = 0L;
	while (arr[i] && symbol != arr[i])
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

inline bool __attribute__((always_inline))
	run_flag(struct s_data_buf *restrict _Nonnull buf,
			struct s_flag_info *restrict _Nonnull flag,
						va_list *restrict _Nonnull ap)
{
	bool	ret;

	ret = s_run(buf, flag, ap, s_get_func_index(flag->symbol));
	if (!ret)
		ft_putendl_fd(E_PF_INVALID, STDERR_FILENO);
	*flag = (struct s_flag_info) { S_FLAG_INFO_REFRESH };
	return (ret);
}
