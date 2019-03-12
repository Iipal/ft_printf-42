/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 19:08:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/12 19:23:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_choose_decimal_length(t_printf *p, va_list *ap, __int128_t *o)
{
	*o = 0;
	if (p->length[0] == 'h' && p->length[1] == 'h')
		*o = (char)va_arg(*ap, int);
	else if (p->length[0] == 'h' && !p->length[1])
		*o = (short)va_arg(*ap, int);
	else if (p->length[0] == 'l' && !p->length[1])
		*o = (long)va_arg(*ap, long);
	else if (p->length[0] == 'l' && p->length[1] == 'l')
		*o = (long long)va_arg(*ap, long long);
	else if (p->length[0] == 'z' && !p->length[1])
		*o = (intmax_t)va_arg(*ap, intmax_t);
	else if (p->length[0] == 'j' && !p->length[1])
		*o = (size_t)va_arg(*ap, size_t);
	else
		*o = (int)va_arg(*ap, int);
}

bool		pf_decimal(t_printf *p, va_list *ap)
{
	__int128_t	out;
	string		out_str;
	long		out_len;
	long		prec;

	prec = 0;
	add_choose_decimal_length(p, ap, &out);
	out_str = ft_maxitoa(out);
	out_len = ft_strlen(out_str);
	ft_strdel(&out_str);
	return (true);
}
