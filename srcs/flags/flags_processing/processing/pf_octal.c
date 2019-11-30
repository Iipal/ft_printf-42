/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:38:44 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/30 22:44:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

static inline void __attribute__((__always_inline__))
	s_put_str_to_buf(void)
{
	const int	wch = IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_DOT) ? '0' : ' ';
	size_t		swidth;

	swidth = (g_flag_width > g_data_len)
		? (g_flag_width - g_data_len) : 0UL;
	if (IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_MINUS) && wch != '0')
		pf_put_str_buf();
	pf_put_ch_buf(wch, swidth);
	if (!IS_BIT(g_flag_spec_mask, PF_BIT_SPEC_MINUS) || wch == '0')
		pf_put_str_buf();
}

inline bool
	pf_octal(va_list *ap)
{
	g_data_ptr = pf_get_unsigned_data(ap, 8);
	g_data_len = ft_strlen(g_data_ptr);
	s_put_str_to_buf();
	ft_strdel(&g_data_ptr);
	return (true);
}
