/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/10 10:16:34 by tmaluh           ###   ########.fr       */
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
		_PUT(' ');
}

static void	add_no_minus_flag_output(t_printf *p, int out_len, string out)
{
	long	i;

	i = -1;
	while (++i < p->width - out_len)
		_PUT(' ');
	i = -1;
	while (++i < out_len)
		_PUT(out[i]);
}

bool		pf_string(t_printf *p, va_list *ap)
{
	string	out;
	char	c_out;
	long	out_len;

	if (p->symbol == 's')
		out = (string)va_arg(*ap, string);
	else
		c_out = (char)va_arg(*ap, int);
	out_len = p->symbol == 's' ? ft_strlen(out) : 1;
	if (p->symbol == 's')
		if (p->is_precision)
			(p->precision >= out_len) ? (p->precision = 0)
			: (out_len = p->precision);
	(p->flags[0])
	? add_is_minus_flag_output(p, out_len, p->symbol== 's' ? out : &c_out)
	: add_no_minus_flag_output(p, out_len, p->symbol== 's' ? out : &c_out);
	return (true);
}