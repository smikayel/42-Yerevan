/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:06:10 by hvardany          #+#    #+#             */
/*   Updated: 2022/04/07 21:00:20 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int		putstrs(char *s);
int		printnumberdi(int k);
int		printnumberu(unsigned int s);
int		printa(const char *s, int i, int n, va_list list);
int		ft_printf(const char *s, ...);
int		printnumberp(unsigned long long k);
int		printnumberx(unsigned int k, int b);

#endif
