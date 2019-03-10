/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:04:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/10 19:26:29 by tmaluh           ###   ########.fr       */
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
	if (format[p->i] == 'l' || format[p->i] == 'L'
	|| format[p->i] == 'h' || format[p->i] == 'z'
	|| format[p->i] == 'j')
	{
		p->length[0] = format[p->i];
		++(p->i);
		if (format[p->i] == 'h' || format[p->i] == 'l')
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
	while (format[p->i] && _IS_FLAG(format[p->i]) && (i = -1))
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
	const char		symbols[] = {'d', 'i', 'u', 'x', 'X', 's', 'c', '%'};
	int				i;

	i = -1;
	while (++i < 8)
		if (symbols[i] == p->symbol)
		{
			if (i >= 0 && i <= 4)
				_NOTIS_F(pf_decimal(p, ap));
			if (i > 4 && i < 8)
				_NOTIS_F(pf_string(p, ap));
		}
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
			ft_cputchar(format[p->i], &(p->counter));
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
