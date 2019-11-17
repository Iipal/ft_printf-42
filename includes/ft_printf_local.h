/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_local.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/17 22:02:45 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LOCAL_H
# define FT_PRINTF_LOCAL_H

# include <stddef.h>
# include <limits.h>
# include <inttypes.h>

# include "libft.h"

/*
** global variables:
**
** global buffer for all data what will be printed:
*/
extern size_t	g_max_buf;
extern char		*g_buf;
extern size_t	g_buf_i;

/*
** iterator in format string for printf:
*/
extern size_t	g_fmt_i;

/*
** g_flag: current data type flag(s d c ...)
** g_flag_spec_mask: current data type specificators (such as '-' or else)
** g_flag_width: cureent data type width
*/
extern char		g_flag;
extern int		g_flag_spec_mask;
extern size_t	g_flag_width;

/*
** pointer to string with data of current parsing data type and
** what will be added to buffer
*/
extern char		*g_data_ptr;
extern size_t	g_data_len;

/*
** functions for work with global buffer.
*/
void	pf_put_ch_buf(char ch);
void	pf_put_n_ch_buf(char ch, size_t n);
void	pf_put_str_buf(const char *restrict str, size_t len);
void	pf_put_gstr_buf(void);

# define FTPRINTF_BIT_MINUS (1 << 0)

# define E_PF_PREFIX "ft_printf: "
# define E_INVALID	E_PF_PREFIX "Invalid flag detected."

bool	pf_decimal(va_list *ap);
bool	pf_string(va_list *ap);
bool	pf_address(va_list *ap);


#endif
