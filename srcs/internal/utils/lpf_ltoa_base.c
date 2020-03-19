/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpf_ltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 21:22:22 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:20:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LIBFTPRINTF_INTERNAL
# include "libftprintf_internal.h"
#undef LIBFTPRINTF_INTERNAL

char	*lpf_ultoap_base(unsigned long num, char *restrict dst, int base)
{
	char	temp[24] = { 0 };
	long	digit = 0;
	long	i = 0L, j =0L;
	bool	dowhile_reducer = true;

	while (num > 0 || dowhile_reducer)
	{
		dowhile_reducer = false;
		digit = num % base;
		if (digit < 10L)
			temp[i++] = digit + '0';
		else
			temp[i++] = digit - 10 + 'A';
		num /= (unsigned long)base;
	}
	--i;
	while (i >= 0L)
		dst[j++] = temp[i--];
	dst[j] = 0;
	return (dst);
}
