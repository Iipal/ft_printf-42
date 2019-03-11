/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:42:34 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/11 20:20:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	add_is_minus_flag_output(t_printf *p, string *out)
{
	if (p)
	{
	}
	if (out)
	{
	}
}

static void	add_no_minus_flag_output(t_printf *p, string *out)
{
	if (p)
	{
	}
	if (out)
	{
	}
}

static void	add_choose_addr_length(t_printf *p, va_list *ap, intptr_t *addr)
{
	*addr = 0;
	if (p->symbol == 'p')
		*addr = (intptr_t)va_arg(*ap, void*);
}

bool	pf_address(t_printf *p, va_list *ap)
{
	intptr_t	addr;
	string		out;

	add_choose_addr_length(p, ap, &addr);
	out = ft_ltoa_base(addr, 16);	
	(ft_is_one_of_n(p->symbol, 2, 'x', 'p')) ? ft_strtolower(out) : 0;
	(p->flags[M]) ? add_is_minus_flag_output(p, &out) : 0;
	if (p->flags[H] || p->symbol == 'p')
	{
		ft_is_one_of_n(p->symbol, 2, 'x', 'p')
		? ft_putstr("0x") : ft_putstr("0X");
		p->counter += 2;
	}
	ft_putstr(out);
	p->counter += ft_strlen(out);
	(p->flags[M]) ? 0 : add_no_minus_flag_output(p, &out);
	return (true);
}
