/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:18:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/24 01:53:55 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

static inline int8_t __attribute__((__always_inline__,__const__))
	s_get_specificator_bit(char spec_ch)
{
	switch (spec_ch) {
		case '-': return 1;
		case '.': return 2;
		default : return 0;
	}
}

static inline int8_t __attribute__((__always_inline__,__const__))
	s_get_type_spec_bit(char spec_ch)
{
	switch (spec_ch) {
		case 'l': return 1;
		case 'h': return 2;
		case 'j': return 3;
		case 't': return 4;
		case 'z': return 5;
		default : return 0;
	}
}

struct s_lpf_flag_
	*flag_parser(const char *restrict format, size_t *restrict fmt_i)
{
	static struct s_lpf_flag_	flag;
	int8_t						spec_n;

	flag = (struct s_lpf_flag_){ S_FLAG_INFO_REFRESH };
	spec_n = s_get_specificator_bit(format[++(*fmt_i)]);
	while (spec_n - 1 != -1) {
		SET_BIT(flag.spec_mask, TO_N_BIT(spec_n - 1));
		spec_n = s_get_specificator_bit(format[++(*fmt_i)]);
	}
	flag.width = (size_t)ft_atol(format + *fmt_i);
	while (F_ISDIGIT(format[*fmt_i]) && format[*fmt_i])
		++(*fmt_i);
	spec_n = s_get_type_spec_bit(format[*fmt_i]);
	while (spec_n - 1 != -1) {
		SET_BIT(flag.type_mask, TO_N_BIT(spec_n - 1));
		spec_n = s_get_type_spec_bit(format[++(*fmt_i)]);
	}
	flag.symbol = format[*fmt_i];
	return (&flag);
}
