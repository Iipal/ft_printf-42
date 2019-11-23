/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:05:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/23 21:51:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdio.h>

/*
** Simple implementation of 'printf' (man 3 printf).
** Flags: 'd', 'i', 'p', 's', 'c' and 'o'.
** Specificators: '-', '.' and width.
*/
int __attribute__((format(printf,1,2)))
ft_printf(const char *restrict format, ...);

int __attribute__((format(printf,2,3)))
ft_dprintf(int fd, const char *restrict format, ...);

int __attribute__((format(printf,2,3)))
ft_sprintf(char *dst, const char *restrict format, ...);

int __attribute__((format(printf,3,4)))
ft_snprintf(char *dst, size_t len, const char *restrict format, ...);

#endif
