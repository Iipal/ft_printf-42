/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:12:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/11 18:12:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lft_str.h"
#define ABS(var) ((var) < 0 ? -(var) : (var))

static void	add_aux(long n, long b, string out, long *p)
{
	char	base[] = "0123456789ABCDEF";

	if (n <= -b || b <= n)
		add_aux(n / b, b, out, p);
	out[(*p)++] = base[ABS(n % b)];
}

string		ft_ltoa_base(long value, long base)
{
	string	out;
	long	p;

	if (base < 2 || 16 < base || !(out = (string)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		out[p++] = '-';
	add_aux(value, base, out, &p);
	out[p] = '\0';
	return (out);
}