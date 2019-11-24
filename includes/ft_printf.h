/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 13:05:21 by tmaluh            #+#    #+#             */
/*   Updated: 2019/11/24 02:05:08 by tmaluh           ###   ########.fr       */
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
int __attribute__((format(printf,1,2),__nonnull__(1)))
ft_printf(const char *restrict format, ...);

int __attribute__((format(printf,2,3),__nonnull__(2)))
ft_dprintf(int fd, const char *restrict format, ...);

int __attribute__((format(printf,2,3),__nonnull__(1,2)))
ft_sprintf(char *dst, const char *restrict format, ...);

int __attribute__((format(printf,3,4),,__nonnull__(1,3)))
ft_snprintf(char *dst, size_t len, const char *restrict format, ...);

#endif
