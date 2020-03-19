/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:05:21 by tmaluh            #+#    #+#             */
/*   Updated: 2020/03/19 22:24:23 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define _GNU_SOURCE

/*
** inlcude stdio.h only for FILE struct.
*/
# include <stdio.h>
# include <stdarg.h>

/*
** Simple implementation of 'printf' (man 3 printf).
** Flags: 'd', 'i', 'p', 's', 'c', 'u' and 'o'.
** Specificators: '-', '.' and width.
*/
extern int	ft_printf(const char *restrict format, ...)
				__attribute__((format(printf,1,2)));
extern int	ft_vprintf(const char *restrict format,
				va_list ap) __attribute__((format(printf,1,0)));

extern int	ft_fprintf(FILE *restrict stream,
				const char *restrict format,
				...) __attribute__((format(printf,2,3)));
extern int	ft_vfprintf(FILE *restrict stream,
				const char *restrict format,
				va_list ap) __attribute__((format(printf,2,0)));

extern int	ft_dprintf(int fd,
				const char *restrict format,
				...) __attribute__((format(printf,2,3)));
extern int	ft_vdprintf(int fd,
				const char *restrict format,
				va_list ap) __attribute__((format(printf,2,0)));

extern int	ft_sprintf(char *restrict dst,
				const char *restrict format,
				...) __attribute__((format(printf,2,3)));
extern int	ft_vsprintf(char *restrict dst,
				const char *restrict format,
				va_list ap) __attribute__((format(printf,2,0)));

extern int	ft_snprintf(char *restrict dst,
				size_t len,
				const char *restrict format,
				...) __attribute__((format(printf,3,4)));
extern int	ft_vsnprintf(char *restrict dst,
				size_t len,
				const char *restrict format,
				va_list ap) __attribute__((format(printf,3,0)));

#endif
