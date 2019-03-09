/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:56:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/09 23:52:58 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		add_is_minus_flag_output(t_printf *p, int out_len,
										int out, string out_str)
{
	int	i;

	i = out_len - 1;
	if (p->flags[1] && out >= 0)
		ft_putchar('+');
	else if (p->flags[1] && out < 0)
		--(p->counter);
	i += p->precision;
	while (p->precision--)
		_PUT('0');
	ft_putstr(out_str);
	while (++i < p->width)
		p->flags[2] ? _PUT('0') : _PUT(' ');
}

static void		add_no_minus_flag_output(t_printf *p, int out_len,
										int out, string out_str)
{
	int	i;

	i = -1;
	while (++i < p->width - out_len - p->precision)
		p->flags[2] ? _PUT('0') : _PUT(' ');
	if (p->flags[1] && out > 0)
		ft_putchar('+');
	else if (p->flags[1] && out < 0)
		--(p->counter);
	while (p->precision--)
		_PUT('0');
	ft_putstr(out_str);
}
 
static __int128	add_choose_di_type(t_printf *p, va_list *ap)
{
	__int128	out;

	out = 0;
	if (p->length[0] == 'h' && p->length[1] == 'h')
		out = (char)va_arg(*ap, int);
	else if (p->length[0] == 'h' && !p->length[1])
		out = (short)va_arg(*ap, int);
	else if (p->length[0] == 'l' && !p->length[1])
		out = (long)va_arg(*ap, long);
	return (out);
}

bool			pf_output_decimal(t_printf *p, va_list *ap)
{
	__int128	out;
	string		out_str;
	int			out_len;

	out = add_choose_di_type(p, ap);
	_NOTISM_F(E_ALLOC, out_str = ft_maxitoa(out));
	out_len = ft_strlen(out_str);
	if (p->is_precision)
		(p->precision > out_len) ? (p->precision -= out_len)
		: (p->precision = 0);
	p->flags[1] ? ++(out_len) : 0;
	p->counter += out_len;
	if (p->flags[0])
		add_is_minus_flag_output(p, out_len, out, out_str);
	else
		add_no_minus_flag_output(p, out_len, out, out_str);
	ft_strdel(&out_str);
	return (true);
}
