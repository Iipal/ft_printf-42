/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_global_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:42:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 21:46:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

size_t	g_max_buf = 128;
char	*g_buf = NULL;
size_t	g_buf_i = 0UL;

size_t	g_fmt_i = ~0UL;

char	g_flag = 0;
int		g_flag_spec_mask = 0;
int		g_flag_type_mask = 0;
size_t	g_flag_width = 0UL;

char	*g_data_ptr = NULL;
size_t	g_data_len = 0UL;

inline void	refresh_flag_global_data(void)
{
	g_flag = 0;
	g_flag_spec_mask = 0;
	g_flag_type_mask = 0;
	g_flag_width = 0UL;
}

inline void	refresh_all_global_data(void)
{
	g_flag = 0;
	g_data_len = 0UL;
	g_data_ptr = NULL;
	g_flag_width = 0UL;
	g_flag_spec_mask = 0;
	g_flag_type_mask = 0;
	g_max_buf = 128;
	g_fmt_i = ~0UL;
	g_buf_i = 0UL;
	if (!g_buf)
		g_buf = ft_strnew(sizeof(char) * g_max_buf);
}
