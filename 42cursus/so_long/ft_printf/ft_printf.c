/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:56:38 by hvardany          #+#    #+#             */
/*   Updated: 2022/07/26 17:33:53 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	putstrs(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
	while (s[i])
	{
		write (1, &s[i++], 1);
	}
	return (i);
}

int	printnumberdi(int k)
{
	int		l;
	char	*p;

	p = ft_itoaasd(k);
	l = putstrs(p);
	free(p);
	return (l);
}

int	printnumberu(unsigned int s)
{
	int				l;
	char			*r;
	unsigned int	v;
	int				i;

	i = 0;
	l = 0;
	v = s;
	if (s == 0)
		return (write(1, "0", 1));
	while (v != 0)
	{
		v /= 10;
		l++;
	}
	r = (char *)malloc(sizeof(char) * (l + 1));
	while (s != 0)
	{
		r[l - i++ - 1] = s % 10 + 48;
		s = s / 10;
	}
	r[i] = '\0';
	putstrs(r);
	free(r);
	return (l);
}

int	printa(const char *s, int i, int n, va_list list)
{
	char	srt[1];

	if (s[i + 1] && s[i + 1] == 's')
		n += putstrs(va_arg(list, char *));
	if (s[i + 1] && s[i + 1] == 'c')
	{
		srt[0] = va_arg(list, int);
		n += write(1, &srt[0], 1);
	}
	if (s[i + 1] && (s[i + 1] == 'd' || s[i + 1] == 'i'))
		n += printnumberdi(va_arg(list, int));
	if (s[i + 1] && s[i + 1] == 'u')
		n += printnumberu(va_arg(list, unsigned int));
	if (s[i + 1] && s[i + 1] == 'x')
		n += printnumberx(va_arg(list, unsigned int), 1);
	if (s[i + 1] && s[i + 1] == 'X')
		n += printnumberx(va_arg(list, unsigned int), 0);
	if (s[i + 1] && s[i + 1] == 'p')
		n += printnumberp(va_arg(list, unsigned long long));
	if (s[i + 1] && s[i + 1] == '%')
		n += write(1, "%", 1);
	return (n);
}

int	ft_printf(const char *s, ...)
{
	int		n;
	int		i;
	va_list	list;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	va_start(list, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1])
				n += printa(s, i, 0, list);
			i++;
		}
		else
			n += write (1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (n);
}
