/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_global_variables.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/03 21:52:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_GLOBAL_VARIABLES
# define FT_PRINTF_GLOBAL_VARIABLES

# include <stddef.h>

# define MAX_BUFF 1024

extern char		g_buff[MAX_BUFF];
extern size_t	g_buff_i;

# define PUT_CH_BUFF(c) ((MAX_BUFF > g_buff_i) ? (g_buff[g_buff_i++] = (c)) : 0)


#endif
