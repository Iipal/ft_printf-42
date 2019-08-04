/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/04 12:31:32 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_global_variables.h"

static void	add_is_minus_output(t_printf *p, char *out, size_t prec)
{
	size_t	i;
	size_t	out_len;

	i = ~0ULL;
	out_len = ft_strlen(out) + 2;
	ft_strncpy(g_buff, "0x", sizeof("0x"));
	while (++i < prec)
		PUT_CH_BUFF('0');
	ft_strncpy(g_buff, out, out_len - 2);
	i = ~0ULL;
	while (++i < p->width - out_len - prec)
		PUT_CH_BUFF(' ');
	g_buff_i += out_len;
}

static void	add_no_minus_output(t_printf *p, char *out, size_t prec)
{
	size_t	i;
	size_t	out_len;

	i = ~0ULL;
	out_len = ft_strlen(out) + 2;
	while (++i < p->width - out_len - prec && !p->flags[Z])
		PUT_CH_BUFF(' ');
	ft_strncpy(g_buff, "0x", sizeof("0x"));
	if (p->flags[Z])
		if (p->width > ft_strlen(out))
			prec = p->width - ft_strlen(out) - 2;
	if ((p->is_precision || p->flags[Z]) && (i = -1))
		while (++i < prec)
			PUT_CH_BUFF('0');
	if (p->is_precision && !p->precision)
		g_buff_i += 2;
	else
	{
		ft_strncpy(g_buff, out, out_len - 2);
		g_buff_i += out_len;
	}
}

bool		pf_address(t_printf *p, va_list *ap)
{
	intptr_t	addr;
	char		*out;
	size_t		prec;

	prec = 0;
	addr = (intptr_t)va_arg(*ap, void*);
	NO_F(out = ft_ltoa_base(addr, 16));
	ft_strlwr(out);
	if (p->is_precision)
		if (p->precision > ft_strlen(out))
			prec = p->precision - ft_strlen(out);
	(p->flags[M])
	? add_is_minus_output(p, out, prec)
	: add_no_minus_output(p, out, prec);
	ft_strdel(&out);
	return (true);
}
