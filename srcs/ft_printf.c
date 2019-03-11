/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:04:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/11 23:08:46 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static bool	add_parser_precision_length(const char *format, t_printf *p)
{
	if (format[p->i] == '.')
	{
		++(p->i);
		_ISM(E_MINUS, format[p->i] == '-', exit(1), false);
		p->is_precision = true;
		p->precision = ft_atoi((string)(&(format[p->i])));
		while (format[p->i] && ft_isdigit(format[p->i]))
			++(p->i);
	}
	if (ft_is_one_of_n(format[p->i], 5, 'l', 'L', 'h', 'z', 'j'))
	{
		p->length[0] = format[p->i];
		++(p->i);
		if (ft_is_one_of_n(format[p->i], 2, 'h', 'l'))
		{
			p->length[1] = format[p->i];
			++(p->i);
		}
	}
	return (true);
}

static bool	add_parser(const char *format, t_printf *p)
{
	const char	flags[] = {'-', '+', '0', '#', ' '};
	int			i;

	*p = (t_printf){++(p->i), p->counter, 0, 0, false, {0}, 0, {0}};
	while (format[p->i] && (i = -1)
	&& ft_is_one_of_n(format[p->i], 5, '-', '+', '0', '#', ' '))
	{
		while (++i < MAX_FLAGS)
			if (format[p->i] == flags[i])
				p->flags[i] = i + 1;
		++(p->i);
	}
	_ISM(E_WIDTH, (p->width = ft_atoi((string)(&(format[p->i])))) < 0,
		exit(1), false);
	while (format[p->i] && ft_isdigit(format[p->i]))
		++(p->i);
	_NOTIS_F(add_parser_precision_length(format, p));
	p->symbol = format[p->i];
	return (true);
}

static bool	add_choose_func(t_printf *p, va_list *ap)
{
	bool	is;

	is = false;
	if (ft_is_one_of_n(p->symbol, 4, 'd', 'i', 'u', 'o') && (is = true))
		_NOTIS_F(pf_decimal(p, ap));
	if (ft_is_one_of_n(p->symbol, 4, 's', 'S', 'c', '%') && (is = true))
		_NOTIS_F(pf_string(p, ap));
	if (ft_is_one_of_n(p->symbol, 3, 'x', 'X', 'p') && (is = true))
		_NOTIS_F(pf_address(p, ap));
	_NOTISD(E_INVALID, is, exit(1), false);
	return (true);
}

int			ft_printf(const char *restrict format, ...)
{
	t_printf	*p;
	va_list		ap;
	int			ret;

	_NOTIS(E_ALLOC, p = (t_printf*)malloc(sizeof(t_printf)), -1);
	*p = (t_printf){-1, 0, 0, 0, false, {0}, 0, {0}};
	va_start(ap, format);
	while (format[++(p->i)])
		if (format[p->i] != '%')
			pf_cputchar(format[p->i], &(p->counter));
		else
		{
			_NOTIS_F(add_parser(format, p));
			_NOTIS_F(add_choose_func(p, &ap));
		}
	va_end(ap);
	ret = p->counter;
	free(p);
	return (ret);
}
