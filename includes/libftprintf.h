/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:05:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/23 21:20:12 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/*
** inlcude stdio.h only for FILE struct.
*/
# include <stdio.h>

/*
** Simple implementation of 'printf' (man 3 printf).
** Flags: 'd', 'i', 'p', 's', 'c', 'u' and 'o'.
** Specificators: '-', '.' and width.
*/
extern int __attribute__((format(printf,1,2)))
ft_printf(const char *restrict format, ...);
extern int __attribute__((format(printf,1,0)))
ft_vprintf(const char *restrict format, va_list *restrict ap);

extern int __attribute__((format(printf,2,3)))
ft_fprintf(FILE *restrict stream, const char *restrict format, ...);
extern int __attribute__((format(printf,2,0)))
ft_vfprintf(FILE *restrict stream,
	const char *restrict format,
	va_list *restrict ap);

extern int __attribute__((format(printf,2,3)))
ft_dprintf(int fd, const char *restrict format, ...);
extern int __attribute__((format(printf,2,0)))
ft_vdprintf(int fd, const char *restrict format, va_list *restrict ap);

extern int __attribute__((format(printf,2,3)))
ft_sprintf(char *restrict dst, const char *restrict format, ...);
extern int __attribute__((format(printf,2,0)))
ft_vsprintf(char *restrict dst,
	const char *restrict format,
	va_list *restrict ap);

extern int __attribute__((format(printf,3,4)))
ft_snprintf(char *restrict dst, size_t len, const char *restrict format, ...);
extern int __attribute__((format(printf,3,0)))
ft_vsnprintf(char *restrict dst, size_t len,
	const char *restrict format,
	va_list *restrict ap);

#endif
