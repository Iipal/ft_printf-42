/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_colors.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:52:47 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/05 20:50:07 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_COLORS_H
# define LIBFTPRINTF_COLORS_H

# ifndef NO_PF_CLRS

/*
** restore changed colors to default:
*/
#  define PF_FG_CLR_DEFAULT  "\033[39m"
#  define PF_BG_CLR_DEFAULT  "\033[49m"

/*
** Invert colors:
*/
#  define PF_CLR_INVERT      "\033[7m"

/*
** default foreground colors:
*/
#  define PF_FG_CLR_BLACK    "\033[30m"
#  define PF_FG_CLR_RED      "\033[31m"
#  define PF_FG_CLR_GREEN    "\033[32m"
#  define PF_FG_CLR_YELLOW   "\033[33m"
#  define PF_FG_CLR_BLUE     "\033[34m"
#  define PF_FG_CLR_MAGENTA  "\033[35m"
#  define PF_FG_CLR_CYAN     "\033[36m"

/*
** default foreground light colors:
*/
#  define PF_FG_CLR_LBLACK   "\033[90m"
#  define PF_FG_CLR_LRED     "\033[91m"
#  define PF_FG_CLR_LGREEN   "\033[92m"
#  define PF_FG_CLR_LYELLOW  "\033[93m"
#  define PF_FG_CLR_LBLUE    "\033[94m"
#  define PF_FG_CLR_LMAGENTA "\033[95m"
#  define PF_FG_CLR_LCYAN    "\033[96m"

/*
** default background colors:
*/
#  define PF_BG_CLR_BLACK    "\033[40m"
#  define PF_BG_CLR_RED      "\033[41m"
#  define PF_BG_CLR_GREEN    "\033[42m"
#  define PF_BG_CLR_YELLOW   "\033[43m"
#  define PF_BG_CLR_BLUE     "\033[44m"
#  define PF_BG_CLR_MAGENTA  "\033[45m"
#  define PF_BG_CLR_CYAN     "\033[46m"

/*
** default background light colors:
*/
#  define PF_BG_CLR_LBLACK   "\033[100m"
#  define PF_BG_CLR_LRED     "\033[101m"
#  define PF_BG_CLR_LGREEN   "\033[102m"
#  define PF_BG_CLR_LYELLOW  "\033[103m"
#  define PF_BG_CLR_LBLUE    "\033[104m"
#  define PF_BG_CLR_LMAGENTA "\033[105m"
#  define PF_BG_CLR_LCYAN    "\033[106m"

# endif

#endif
