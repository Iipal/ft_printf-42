/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 19:10:58 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/21 08:39:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_is_minus_output(t_printf *const p,
				const size_t out_len,
				const string out)
{
	size_t	i;

	i = ~0ULL;
	while (out_len > ++i)
		PUTC(out[i]);
	i = out_len - 1;
	while (++i < p->width)
		(p->symbol == '%' && p->flags[Z] && !p->flags[M])
			? PUTC('0') : PUTC(' ');
}

static void	add_no_minus_output(t_printf *const p,
				const size_t out_len,
				const string out)
{
	size_t	i;

	i = ~0ULL;
	while ((p->width - out_len) > ++i)
		(p->symbol == '%' && p->flags[Z]) ? PUTC('0') : PUTC(' ');
	i = ~0ULL;
	while (++i < out_len)
		PUTC(out[i]);
}

static void	add_choose_data(char sym, va_list *ap, string *s, char *c)
{
	if (ft_is_one_of_n(sym, 2, 'S', 's'))
	{
		*s = (string)va_arg(*ap, string);
		if (*s && sym == 'S')
			ft_strupr(*s);
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
	size_t	out_len;
	char	c_out;
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
