/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:18:35 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:23:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

static inline int8_t __attribute__((__always_inline__,__const__))
	s_get_specificator_bit(char spec_ch)
{
	switch (spec_ch) {
		case '-': return PF_BIT_SPEC_MINUS;
		case '.': return PF_BIT_SPEC_DOT;
		default : return -1;
	}
}

static inline int8_t __attribute__((__always_inline__,__const__))
	s_get_type_spec_bit(char spec_ch)
{
	switch (spec_ch) {
		case 'l': return PF_BIT_TYPE_L;
		case 'h': return PF_BIT_TYPE_H;
		case 'j': return PF_BIT_TYPE_J;
		case 't': return PF_BIT_TYPE_T;
		case 'z': return PF_BIT_TYPE_Z;
		default : return -1;
	}
}

struct s_lpf_flag_
	*flag_parser(const char *restrict format, size_t *restrict fmt_i)
{
	static struct s_lpf_flag_	flag;
	int8_t						spec_n;

	flag = (struct s_lpf_flag_){ S_FLAG_INFO_REFRESH };
	spec_n = s_get_specificator_bit(format[++(*fmt_i)]);
	while (spec_n != -1) {
		SET_BIT(flag.spec_mask, spec_n);
		spec_n = s_get_specificator_bit(format[++(*fmt_i)]);
	}
	flag.width = (size_t)atol(format + *fmt_i);
	while (isdigit(format[*fmt_i]) && format[*fmt_i])
		++(*fmt_i);
	spec_n = s_get_type_spec_bit(format[*fmt_i]);
	while (spec_n != -1) {
		SET_BIT(flag.type_mask, spec_n);
		spec_n = s_get_type_spec_bit(format[++(*fmt_i)]);
	}
	flag.symbol = format[*fmt_i];
	return (&flag);
}
