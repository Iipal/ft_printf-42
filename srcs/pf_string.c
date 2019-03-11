/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/11 18:26:52 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_is_minus_flag_output(t_printf *p, int out_len, string out)
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

static void	add_no_minus_flag_output(t_printf *p, int out_len, string out)
{
	long	i;

	i = -1;
	while (++i < p->width - out_len)
		(p->symbol == '%' && p->flags[Z]) ? _PUT('0') : _PUT(' ');
	i = -1;
	while (++i < out_len)
		_PUT(out[i]);
}

bool		pf_string(t_printf *p, va_list *ap)
{
	string	out;
	char	c_out;
	long	out_len;

	c_out = 0;
	out = NULL;
	if (ft_is_one_of_n(p->symbol, 2, 's', 'S'))
	{
		out = (string)va_arg(*ap, string);
		if (out && p->symbol == 'S')
			ft_strtoupper(out);
	}
	else if (p->symbol == '%')
		c_out = '%';
	else
		c_out = (char)va_arg(*ap, int);
	if (!out)
		out = ft_strdup("(null)");
	out_len = ft_is_one_of_n(p->symbol, 2, 's', 'S') ? ft_strlen(out) : 1;
	if (ft_is_one_of_n(p->symbol, 2, 's', 'S'))
		if (p->is_precision)
			(p->precision >= out_len) ? (p->precision = 0)
			: (out_len = p->precision);
	if (p->flags[M])
		add_is_minus_flag_output(p, out_len,
		ft_is_one_of_n(p->symbol, 2, 's', 'S') ? out : &c_out);
	else
		add_no_minus_flag_output(p, out_len,
		ft_is_one_of_n(p->symbol, 2, 's', 'S') ? out : &c_out);
	ft_strdel(&out);
	return (true);
}
