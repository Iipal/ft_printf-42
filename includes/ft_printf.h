/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:05:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/08/05 10:11:08 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# include <limits.h>
# include <inttypes.h>

# define MAX_PF_FLAGS  5

# define E_MINUS	" \\ STOP: Invalid \'-\' specifier."
# define E_INVALID	"Invalid flag detected."

# define IS_FLAG(c) (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')

# define M 0
# define P 1
# define Z 2
# define H 3
# define S 4

# define F_MINUS (1 << 0)
# define F_PLUS  (1 << 1)
# define F_ZERO  (1 << 2)
# define F_TAG   (1 << 3)
# define F_SPACE (1 << 4)

# define SET_BIT(mask, bit) ((mask) |= (bit))
# define IS_BIT(mask, bit) (((mask) & (bit)) == (bit))

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
	size_t	width;
	size_t	precision;
	bool	is_precision;
	char	length[2];
	char	symbol;
	t_flags	flags[MAX_PF_FLAGS];
}				t_printf;

int				ft_printf(char const *const format, ...);

bool			pf_decimal(t_printf *p, va_list *ap);
bool			pf_string(t_printf *p, va_list *ap);
bool			pf_address(t_printf *p, va_list *ap);

void			pf_buff_putchar(char const c);

#endif
