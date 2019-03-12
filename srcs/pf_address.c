/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/12 17:31:48 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_choose_addr_length(t_printf *p, va_list *ap, intptr_t *addr)
{
	*addr = 0;
	if (p->symbol == 'p')
		*addr = (intptr_t)va_arg(*ap, void*);
	else
	{
		if (p->length[0] == 'h' && p->length[1] == 'h')
			*addr = (unsigned char)va_arg(*ap, int);
		else if (p->length[0] == 'h' && !p->length[1])
			*addr = (unsigned short)va_arg(*ap, int);
		else if (p->length[0] == 'l' && !p->length[1])
			*addr = (unsigned long)va_arg(*ap, unsigned long);
		else if (p->length[0] == 'l' && p->length[1] == 'l')
			*addr = (unsigned long long)va_arg(*ap, unsigned long long);
		else if (p->length[0] == 'z' && !p->length[1])
			*addr = (size_t)va_arg(*ap, size_t);
		else if (p->length[0] == 'j' && !p->length[1])
			*addr = (uintmax_t)va_arg(*ap, uintmax_t);
		else
			*addr = (unsigned int)va_arg(*ap, unsigned int);
	}
}

static void	add_is_minus_flag_output(t_printf *p, string out, long prec)
{
	long	i;
	long	out_len;

	i = -1;
	out_len = ft_strlen(out) + 2;
	ft_putstr("0x");
	while (++i < prec)
		_PUT('0');
	ft_putstr(out);
	p->counter += out_len;
	i = -1;
	while (++i < p->width - out_len - prec)
		_PUT(' ');
}

static void	add_no_minus_flag_output(t_printf *p, string out, long prec)
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
	add_choose_addr_length(p, ap, &addr);
	out = ft_ltoa_base(addr, 16);
	ft_strtolower(out);
	if (p->is_precision)
		if (p->precision > (int)ft_strlen(out))
			prec = p->precision - (int)ft_strlen(out);
	(p->flags[M]) ? add_is_minus_flag_output(p, out, prec) : 0;
	(p->flags[M]) ? 0 : add_no_minus_flag_output(p, out, prec);
	return (true);
}
