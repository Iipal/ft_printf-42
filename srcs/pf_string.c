/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/12 20:06:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_is_minus_output(t_printf *p, int out_len, string out)
{
	long	i;

	i = -1;
	while (++i < out_len)
		_PUT(out[i]);
	i = out_len - 1;
	while (++i < p->width)
		(p->symbol == '%' && p->flags[Z] && !p->flags[M])
		? _PUT('0') : _PUT(' ');
}

static void	add_no_minus_output(t_printf *p, int out_len, string out)
{
	long	i;

	i = -1;
	while (++i < p->width - out_len)
		(p->symbol == '%' && p->flags[Z]) ? _PUT('0') : _PUT(' ');
	i = -1;
	while (++i < out_len)
		_PUT(out[i]);
}

static void	add_choose_data(char sym, va_list *ap, string *s, char *c)
{
	if (ft_is_one_of_n(sym, 2, 'S', 's'))
	{
		*s = (string)va_arg(*ap, string);
		if (*s && sym == 'S')
			ft_strtoupper(*s);
	}
	else if (sym == '%')
		*c = '%';
	else
		*c = (char)va_arg(*ap, int);
	if (!*s && ft_is_one_of_n(sym, 2, 'S', 's'))
		*s = ft_strdup("(null)");
}

bool		pf_string(t_printf *p, va_list *ap)
{
	string	out;
	char	c_out;
	long	out_len;
	bool	is_str;

	c_out = 0;
	out = NULL;
	is_str = true;
	if (p->symbol == 'c' || p->symbol == '%')
		is_str = false;
	add_choose_data(p->symbol, ap, &out, &c_out);
	out_len = is_str ? ft_strlen(out) : 1;
	if (is_str)
		if (p->is_precision)
			(p->precision >= out_len) ? (p->precision = 0)
			: (out_len = p->precision);
	if (p->flags[M])
		add_is_minus_output(p, out_len, is_str ? out : &c_out);
	else
		add_no_minus_output(p, out_len, is_str ? out : &c_out);
	return (true);
}
