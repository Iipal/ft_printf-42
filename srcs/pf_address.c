/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/21 00:21:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_is_minus_output(t_printf *p, string out, long prec)
{
	long	i;
	long	out_len;

	i = -1;
	out_len = ft_strlen(out) + 2;
	ft_putstr("0x");
	while (++i < prec)
		_PUT('0');
	ft_putstr(out);
	i = -1;
	while (++i < p->width - out_len - prec)
		_PUT(' ');
	p->counter += out_len;
}

static void	add_no_minus_output(t_printf *p, string out, long prec)
{
	long	i;
	long	out_len;

	i = -1;
	out_len = ft_strlen(out) + 2;
	while (++i < p->width - out_len - prec && !p->flags[Z])
		_PUT(' ');
	ft_putstr("0x");
	if (p->flags[Z])
		if (p->width > (int)ft_strlen(out))
			prec = p->width - ft_strlen(out) - 2;
	if ((p->is_precision || p->flags[Z]) && (i = -1))
		while (++i < prec)
			_PUT('0');
	if (p->is_precision && !p->precision)
		p->counter += 2;
	else
	{
		ft_putstr(out);
		p->counter += out_len;
	}
}

bool		pf_address(t_printf *p, va_list *ap)
{
	intptr_t	addr;
	string		out;
	long		prec;

	prec = 0;
	addr = (intptr_t)va_arg(*ap, void*);
	NO_F(out = ft_ltoa_base(addr, 16));
	ft_strlwr(out);
	if (p->is_precision)
		if (p->precision > (int)ft_strlen(out))
			prec = p->precision - (int)ft_strlen(out);
	(p->flags[M])
	? add_is_minus_output(p, out, prec)
	: add_no_minus_output(p, out, prec);
	ft_strdel(&out);
	return (true);
}
