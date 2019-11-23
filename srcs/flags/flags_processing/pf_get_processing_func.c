/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_processing_func.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:41:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 21:58:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

inline bool	pf_get_processing_func(va_list *ap)
{
	bool	ret;

	ret = false;
	if (g_flag == 'd' || g_flag == 'i')
		ret = pf_decimal(ap);
	else if (g_flag == 's' || g_flag == 'c' || g_flag == '%')
		ret = pf_string(ap);
	else if (g_flag == 'p')
		ret = pf_address(ap);
	else if (g_flag == 'o')
		ret = pf_octal(ap);
	refresh_flag_global_data();
	if (!ret)
		ft_putendl_fd(E_PF_INVALID, STDERR_FILENO);
	return (ret);
}
