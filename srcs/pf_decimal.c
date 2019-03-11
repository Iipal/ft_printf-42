/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:56:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/11 23:10:02 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_is_minus_flag_output(t_printf *p, long out_len,
										long out, string out_str)
{
	long	i;
	long	prec;

	i = out_len - 1;
	if (p->symbol != 'u')
	{
		if (p->is_precision && !p->precision && p->symbol == 'o')
				;
		else if (p->flags[P] && out >= 0)
			_PUT('+');
		else if (p->flags[P] && out < 0)
			--(p->counter);
	}
	prec = p->precision;
	i += p->precision;
	while (prec--)
		_PUT('0');
	if (p->is_precision && !p->precision && !out)
		p->counter -= out_len;
	else
		ft_putstr(out_str);
	while (++i < p->width)
		p->flags[Z] ? _PUT('0') : _PUT(' ');
}

static void	add_no_minus_flag_output(t_printf *p, long out_len,
										long out, string out_str)
{
	long	i;
	long	prec;

	i = -1;
	while (++i < p->width - out_len - p->precision)
		p->flags[Z] ? _PUT('0') : _PUT(' ');
	if (p->symbol != 'u')
	{
		if (p->is_precision && !p->precision && p->flags[P] && p->symbol == 'o')
			;
		else if (p->is_precision && !p->precision && p->symbol == 'o')
			_PUT('+');
		else if (p->flags[P] && out >= 0)
			_PUT('+');
		else if (p->flags[P] && out < 0)
			--(p->counter);
	}
	prec = p->precision;
	while (prec--)
		_PUT('0');
	if (p->is_precision && !p->precision && !out)
	{
		p->counter -= out_len;
		if (p->symbol == 'o')
		{
			ft_putstr(out_str);
			p->counter += ft_strlen(out_str);
		}
	}
	else
		ft_putstr(out_str);
}

static void	add_choose_di_datatype(t_printf *p, va_list *ap,
											__int128 *out)
{
	*out = 0;
	if (p->length[0] == 'h' && p->length[1] == 'h')
		*out = (char)va_arg(*ap, int);
	else if (p->length[0] == 'h' && !p->length[1])
		*out = (short)va_arg(*ap, int);
	else if (p->length[0] == 'l' && !p->length[1])
		*out = (long)va_arg(*ap, long);
	else if (p->length[0] == 'l' && p->length[1] == 'l')
		*out = (long long)va_arg(*ap, long long);
	else if (p->length[0] == 'z' && !p->length[1])
		*out = (intmax_t)va_arg(*ap, intmax_t);
	else if (p->length[0] == 'j' && !p->length[1])
		*out = (size_t)va_arg(*ap, size_t);
	else
		*out = (int)va_arg(*ap, int);
}

static void	add_choose_udatatype(t_printf *p, va_list *ap,
											__int128 *out)
{
	*out = 0;
	if (p->length[0] == 'h' && p->length[1] == 'h')
		*out = (unsigned char)va_arg(*ap, int);
	else if (p->length[0] == 'h' && !p->length[1])
		*out = (unsigned short)va_arg(*ap, int);
	else if (p->length[0] == 'l' && !p->length[1])
		*out = (unsigned long)va_arg(*ap, unsigned long);
	else if (p->length[0] == 'l' && p->length[1] == 'l')
		*out = (unsigned long long)va_arg(*ap, unsigned long long);
	else if (p->length[0] == 'z' && !p->length[1])
		*out = (size_t)va_arg(*ap, size_t);
	else if (p->length[0] == 'j' && !p->length[1])
		*out = (uintmax_t)va_arg(*ap, uintmax_t);
	else
		*out = (unsigned int)va_arg(*ap, unsigned int);
}

bool		pf_decimal(t_printf *p, va_list *ap)
{
	__int128	out;
	string		out_str;
	long		out_len;	

	ft_is_one_of_n(p->symbol, 2, 'u', 'o')
	? add_choose_udatatype(p, ap, &out) : add_choose_di_datatype(p, ap, &out);
	_NOTIS_F(add_choose_out_str(&out_str, p->symbol, out));
	out_len = ft_strlen(out_str);
	(p->flags[4] && !ft_is_one_of_n(p->symbol, 2, 'u', 'o')
	&& !p->flags[P]) ? _PUT(' ') : 0;
	(p->is_precision && p->precision > out_len) ? (p->precision -= out_len)
	: (p->precision = 0);
	p->flags[P] ? ++(out_len) : 0;
	p->counter += out_len;
	(p->flags[M]) ? add_is_minus_flag_output(p, out_len, out, out_str)
	: add_no_minus_flag_output(p, out_len, out, out_str);
	ft_strdel(&out_str);
	return (true);
}
