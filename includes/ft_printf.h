/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:05:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/03 20:33:27 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# include <limits.h>
# include <inttypes.h>

# define MAX_FLAGS  5

# define E_MINUS	" \\ STOP: Invalid \'-\' specifier."
# define E_INVALID	"Invalid flag detected."

# define IS_FLAG(c) (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')

# define M 0
# define P 1
# define Z 2
# define H 3
# define S 4

# define MAX_BUFF 1024

extern char		g_buff[MAX_BUFF];
extern size_t	g_buff_i;

# define PUT_CH_BUFF(c) ((MAX_BUFF > g_buff_i) ? (g_buff[g_buff_i++] = (c)) : 0)

typedef enum	e_flags
{
	none,
	minus,
	plus,
	zero,
	hashtag,
	space
} __attribute__((packed))				t_flags;

typedef struct	s_printf
{
	size_t	i;
	size_t	counter;
	size_t	width;
	size_t	precision;
	bool	is_precision;
	char	length[2];
	char	symbol;
	t_flags	flags[MAX_FLAGS];
}				t_printf;

int				ft_printf(const char *restrict format, ...);

bool			pf_decimal(t_printf *p, va_list *ap);
bool			pf_string(t_printf *p, va_list *ap);
bool			pf_address(t_printf *p, va_list *ap);

void			pf_buff_putchar(char const c);

#endif
