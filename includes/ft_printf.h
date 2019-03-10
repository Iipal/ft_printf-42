/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:05:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/03/10 21:59:35 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <limits.h>

# ifdef __APPLE__
#  define INTMAX_T	intmax_t
#  define UINTMAX_T	uintmax_t
# endif

# ifdef __linux__
#  define INTMAX_T	long long
#  define UINTMAX_T	unsigned long long
# endif

# define MAX_FLAGS  5

# define E_ALLOC    "STOP: Where is memory, pal ?"
# define E_WIDTH	" \\ STOP: Width can not be less than 0."
# define E_MINUS	" \\ STOP: Invalid \'-\' specifier."
# define E_INVALID	"Invalid flag detected."

# define _MSG(msg) ft_putstr(msg);
# define _MSGN(msg) ft_putendl(msg);
# define _NOTIS(msg, ex, ret) if (!(ex)) {_MSGN(msg);return (ret);}
# define _NOTISD(msg, ex, do, ret) if (!(ex)) {_MSGN(msg);do;return (ret);}
# define _NOTIS_N(ex) if (!(ex)) {return (NULL);}
# define _NOTIS_F(ex) if (!(ex)) {return (false);}
# define _NOTISM_F(msg, ex) if (!(ex)) {_MSGN(msg);return (false);}
# define _IS(ex, do, ret) if (ex) {do; return (ret);}
# define _ISM(msg, ex, do, ret) if (ex) {_MSGN(msg);do;return (ret);}
# define _IS_N(ex) if (ex) {return (NULL);}
# define _IS_F(ex) if (ex) {return (false);}
# define _ISM_F(msg, ex) if (ex) {_MSGN(msg);return (false);}

# define _IS_FLAG(c) (c == '#' || c == '-' || c == '+' || c == ' ' || c == '0')

# define _PUT(c) ft_cputchar(c, &(p->counter))

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
	int			i;
	int			counter;
	int			width;
	int			precision;
	bool		is_precision;
	char		length[2];
	char		symbol;
	t_flags		flags[MAX_FLAGS];
}				t_printf;

int				ft_printf(const char *restrict format, ...);

bool			pf_decimal(t_printf *p, va_list *ap);
bool			pf_string(t_printf *p, va_list *ap);
bool			pf_hex(t_printf *p, va_list *ap);

void			ft_cputchar(char c, int *inc);

#endif
