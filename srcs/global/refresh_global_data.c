/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_global_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:42:48 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:41:42 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_internal.h"

size_t	g_max_buf = 256;
char	*g_buf = NULL;
size_t	g_buf_i = 0UL;

size_t	g_fmt_i = ~0UL;

short	g_flag = 0;
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
	if (g_buf)
		free(g_buf);
	refresh_flag_global_data();
	g_max_buf = DEFAULT_BUF_SIZE;
	g_buf = ft_strnew(sizeof(char) * g_max_buf);
	g_buf_i = 0UL;
	g_data_len = 0UL;
	g_data_ptr = NULL;
	g_fmt_i = ~0UL;
}
