/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 09:44:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/10 09:52:47 by tmaluh           ###   ########.fr       */
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
 
static void	add_choose_udatatype_length(t_printf *p, va_list *ap,
											__int128 *out)
{
	*out = 0;
	if (p->length[0] == 'h' && p->length[1] == 'h')
		*out = (unsigned char)va_arg(*ap, int);
	else if (p->length[0] == 'h' && !p->length[1])
		*out = (unsigned short)va_arg(*ap, int);
	else if (p->length[0] == 'l' && !p->length[1])
		*out = (unsigned long)va_arg(*ap, long);
	else if (p->length[0] == 'l' && p->length[1] == 'l')
		*out = (unsigned long long)va_arg(*ap, long long);
	else
		*out = (unsigned int)va_arg(*ap, int);
}

bool		pf_unsigned(t_printf *p, va_list *ap)
{
	__int128	out;
	string		out_str;
	long		out_len;

	add_choose_udatatype_length(p, ap, &out);
	_NOTISD(E_ALLOC, out_str = ft_maxitoa(out), exit(1), false);
	out_len = ft_strlen(out_str);
	if (p->is_precision)
		(p->precision > out_len) ? (p->precision -= out_len)
		: (p->precision = 0);
	p->flags[1] ? ++(out_len) : 0;
	p->counter += out_len;
	(p->flags[0]) ? add_is_minus_flag_output(p, out_len, out, out_str)
	: add_no_minus_flag_output(p, out_len, out, out_str);
	ft_strdel(&out_str);
	return (true);
}
