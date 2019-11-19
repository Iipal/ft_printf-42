/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_local.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 21:51:30 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/19 15:30:05 by tmaluh           ###   ########.fr       */
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
*/
# include "pf_global_vars.h"

/*
** Bit mask[g_flag_spec_mask] for each flag specifications:
*/
# include "pf_flags.h"

# define E_PF_PREFIX "ft_printf: "
# define E_INVALID	E_PF_PREFIX "Invalid flag detected."

bool    pf_flag_parser(const char *restrict format);

bool	pf_decimal(va_list *ap);
extern bool	pf_string(va_list *ap);
bool	pf_address(va_list *ap);


#endif
