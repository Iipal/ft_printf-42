/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:04:40 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/09 18:01:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static bool	add_parser_precision_length(const char *format, t_printf *p)
{
	if (format[p->i] == '.')
	{
		++(p->i);
		_ISM_F(E_MINUS, format[p->i] == '-');
		p->is_precision = true;
		p->precision = ft_atoi((string)(&(format[p->i])));
		if (!p->precision)
			p->is_precision = false;
		while (format[p->i] && ft_isdigit(format[p->i]))
			++(p->i);
	}
	if (format[p->i] == 'l' || format[p->i] == 'L'
	|| format[p->i] == 'h')
	{
		p->lenght[0] = format[p->i];
		++(p->i);
		if (format[p->i] == 'h' || format[p->i] == 'l')
		{
			p->lenght[1] = format[p->i];
			++(p->i);
		}
	}
	return (true);
}

static bool	add_parser(const char *format, t_printf *p)
{
	const char	flags[] = {'-', '+', '0', '#', ' '};
	int			i;

	++(p->i);
	while (format[p->i] && _IS_FLAG(format[p->i]) && (i = -1))
	{
		while (++i < MAX_FLAGS)
			if (format[p->i] == flags[i])
				p->flags[i] = i + 1;
		++(p->i);
	}
	_ISM_F(E_WIDTH, (p->width = ft_atoi((string)(&(format[p->i])))) < 0);
	while (format[p->i] && ft_isdigit(format[p->i]))
		++(p->i);
	_NOTIS_F(add_parser_precision_length(format, p));
	p->symbol = format[p->i];
	return (true);
}

static bool	add_choose_func(t_printf *p, va_list *ap)
{
	const char		symbols[] = {'d', 's'};
	int				i;
	const t_fptr	fptrs[] = {&pf_output_decimal, &pf_output_string};

	i = -1;
	while (++i < 2)
		if (symbols[i] == p->symbol)
			_NOTIS_F(fptrs[i](p, ap));
	return (true);
}

int			ft_printf(const char *restrict format, ...)
{
	t_printf	*p;
	va_list		ap;

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
	free(p);
	return (p->counter);
}
