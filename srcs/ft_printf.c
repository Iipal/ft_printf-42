/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:04:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/21 08:45:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	add_parser_precision_length(const char *format, t_printf *p)
{
	if (format[(p->i)++] == '.')
	{
		IFM_F(E_MINUS, format[p->i] == '-');
		p->is_precision = true;
		p->precision = ft_atoi((string)(&(format[p->i])));
		while (format[p->i] && ft_isdigit(format[p->i]))
			++(p->i);
	}
	if (ft_is_one_of_n(format[p->i], 5, 'l', 'L', 'h', 'z', 'j'))
	{
		p->length[0] = format[(p->i)++];
		if (ft_is_one_of_n(format[p->i], 2, 'h', 'l'))
			p->length[1] = format[(p->i)++];
	}
	return (true);
}

static bool	add_parser(const char *format, t_printf *p)
{
	const char	flags[] = {'-', '+', '0', '#', ' '};
	size_t		i;

	*p = (t_printf){++(p->i), p->counter, 0, 0, false, {0}, 0, {0}};
	while (format[p->i] && (i = ~0ULL)
	&& ft_is_one_of_n(format[p->i], 5ULL, '-', '+', '0', '#', ' '))
	{
		while (++i < MAX_FLAGS)
			if (format[p->i] == flags[i])
				p->flags[i] = i + 1;
		++(p->i);
	}
	p->width = ft_atoi((string)(&(format[p->i])));
	while (format[p->i] && ft_isdigit(format[p->i]))
		++(p->i);
	NO_F(add_parser_precision_length(format, p));
	p->symbol = format[p->i];
	return (true);
}

static bool	add_choose_func(t_printf *p, va_list *ap)
{
	// if (ft_is_one_of_n(p->symbol, 4, 'd', 'i', 'u', 'o') && (is = true))
		// NO_F(pf_decimal(p, ap));
	if (p->symbol == 'd')
		return (pf_decimal(p, ap));
	else if (p->symbol == 'p')
		return (pf_address(p, ap));
	else if (ft_is_one_of_n(p->symbol, 4, 's', 'S', 'c', '%'))
		return (pf_string(p, ap));
	MSGN(E_INVALID);
	return (false);
}

int			ft_printf(const char *restrict format, ...)
{
	t_printf	p;
	va_list		ap;

	p = (t_printf){-1, 0, 0, 0, false, {0}, 0, {0}};
	va_start(ap, format);
	while (format[++(p.i)])
		if (format[p.i] != '%')
			pf_cputchar(format[p.i], &(p.counter));
		else
		{
			NODO_F(add_parser(format, &p), va_end(ap));
			NODO_F(add_choose_func(&p, &ap), va_end(ap));
		}
	va_end(ap);
	return (p.counter);
}
