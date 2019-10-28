/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_local.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/10/28 12:52:28 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LOCAL_H
# define FT_PRINTF_LOCAL_H

# include <stddef.h>
# include <limits.h>
# include <inttypes.h>

# include "libft.h"

# define MAX_BUFF 1024

extern char		g_buff[MAX_BUFF];
extern size_t	g_buff_i;

# define PUT_CH_BUFF(c) ((MAX_BUFF > g_buff_i) ? (g_buff[g_buff_i++] = (c)) : 0)

extern size_t	g_fmt_i;

extern size_t	g_flag_width;
extern char		g_flag;

extern char		*g_data_ptr;
extern size_t	g_data_len;

# define E_PF_PREFIX "ft_printf: "
# define E_INVALID	E_PF_PREFIX "Invalid flag detected."

bool	pf_decimal(va_list *ap);
bool	pf_string(va_list *ap);
bool	pf_address(va_list *ap);

#endif
