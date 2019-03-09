/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:56:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/09 18:38:09 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool			pf_output_decimal(t_printf *p, va_list *ap)
{
	int			out_len;
	string		temp;
	int			i;
	int			out;
	int			prec;

	out = va_arg(*ap, int);
	_NOTISM_F(E_ALLOC, temp = ft_itoa(out));
	out_len = ft_strlen(temp);
	p->flags[1] ? ++(out_len) : 0;
	p->counter += out_len;
	if (p->is_precision)
	{
		if (p->precision > (u)(p->flags[1] ? (out_len - 1) : out_len))
			p->precision -= (u)(p->flags[1] ? (out_len - 1) : out_len);
		else
			p->precision = 0;
	}
	prec = p->precision;
	i = -1;
	if (p->flags[0])
	{
		i = out_len - 1;
		if (p->flags[1] && out >= 0)
			ft_putchar('+');
		else if (p->flags[1] && out < 0)
			--(p->counter);
		i += p->precision;
		while (prec--)
			_PUT('0');
		ft_putstr(temp);
		while (++i < p->width)
			p->flags[2] ? _PUT('0') : _PUT(' ');
	}
	else
	{
		while (++i < p->width - out_len - (int)p->precision)
			p->flags[2] ? _PUT('0') : _PUT(' ');
		if (p->flags[1] && out > 0)
			ft_putchar('+');
		else if (p->flags[1] && out < 0)
			--(p->counter);
		while (prec--)
			_PUT('0');
		ft_putstr(temp);
	}
	ft_strdel(&temp);
	return (true);
}

bool			pf_output_string(t_printf *p, va_list *ap)
{
	if (p)
	{
	}
	if (ap)
	{
	}
	return (true);
}
