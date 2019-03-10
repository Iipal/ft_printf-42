/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:56:35 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/10 21:58:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_is_minus_flag_output(t_printf *p, long out_len,
										long out, string out_str)
{
	long	i;

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

static void	add_no_minus_flag_output(t_printf *p, long out_len,
										long out, string out_str)
{
	long	i;
	long	prec;

	i = -1;
	while (++i < p->width - out_len - p->precision)
		p->flags[2] ? _PUT('0') : _PUT(' ');
	if (p->symbol != 'u')
	{
		if (p->flags[1] && out >= 0)
			_PUT('+');
		else if (p->flags[1] && out < 0)
			--(p->counter);
	}
	prec = p->precision;
	while (prec--)
		_PUT('0');
	if (p->is_precision && !p->precision && !out)
		p->counter -= out_len;
	else
	{
		if (p->flags[3])
			p->symbol == 'x' ? ft_putstr("0x") : ft_putstr("0X");
		ft_putstr(out_str);
	}
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
		*out = (INTMAX_T)va_arg(*ap, INTMAX_T);
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
		*out = (UINTMAX_T)va_arg(*ap, UINTMAX_T);
	else
		*out = (unsigned int)va_arg(*ap, int);
}

bool		pf_decimal(t_printf *p, va_list *ap)
{
	__int128	out;
	string		out_str;
	long		out_len;

	ft_is_one_of_n(p->symbol, 4, 'x', 'X', 'u', 'o')
	? add_choose_udatatype(p, ap, &out) : add_choose_di_datatype(p, ap, &out);
	if (ft_is_one_of_n(p->symbol, 2, 'x', 'X'))
	{
		_NOTISD(E_ALLOC, out_str = ft_itoa_base(out, 16), exit(1), false)
		(p->symbol == 'x') ? ft_strtolower(out_str) : 0;
	}
	else
		_NOTISD(E_ALLOC, out_str = ft_maxitoa(out), exit(1), false);
	out_len = ft_strlen(out_str);
	(p->flags[4] && p->symbol != 'u' && !p->flags[1]) ? _PUT(' ') : 0;
	(p->is_precision && p->precision > out_len) ? (p->precision -= out_len)
	: (p->precision = 0);
	p->flags[1] ? ++(out_len) : 0;
	p->flags[3] ? (out_len += 2) : 0;
	p->counter += out_len;
	(p->flags[0]) ? add_is_minus_flag_output(p, out_len, out, out_str)
	: add_no_minus_flag_output(p, out_len, out, out_str);
	ft_strdel(&out_str);
	return (true);
}
