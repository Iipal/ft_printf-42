/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lftprintf_global_data.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:19:04 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:41:39 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFTPRINTF_GLOBAL_VARS_H
# define LFTPRINTF_GLOBAL_VARS_H

# include <sys/types.h>

# define DEFAULT_BUF_SIZE 256UL

/*
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
** g_flag_spec_mask: current flag specificators (such as '-' or else)
** g_flag_type_mask: current flag additional type spec. (such as 'll' or else)
** g_flag_width: cureent flag width
*/
extern short	g_flag;
extern int		g_flag_spec_mask;
extern int		g_flag_type_mask;
extern size_t	g_flag_width;

/*
** pointer to string with data of current parsing flag and
** what will be added to buffer
*/
extern char		*g_data_ptr;
extern size_t	g_data_len;

extern void
refresh_flag_global_data(void);

extern void
refresh_all_global_data(void);

/*
** put \param ch to g_buf
**  and checks for is enought memory to put ch to g_buf.
*/
extern void __attribute__((__overloadable__))
pf_put_ch_buf(char ch);

/*
** put \param ch \param n times to g_buf.
*/
extern void __attribute__((__overloadable__))
pf_put_ch_buf(char ch, size_t n);

/*
** put g_data_ptr to g_buf.
*/
extern void __attribute__((__overloadable__))
pf_put_str_buf(void);

/*
** put \param len bytes from g_data_ptr to g_buf.
*/
extern void __attribute__((__overloadable__))
pf_put_str_buf(size_t len);

/*
** put \param str with \param len length to g_buf.
*/
extern void __attribute__((__overloadable__))
pf_put_str_buf(const char *restrict str, size_t len);

#endif
