/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printX.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:50:19 by hvardany          #+#    #+#             */
/*   Updated: 2022/04/07 20:58:10 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

static char	*hexadecimalx(char *r, unsigned int s, int l, int b)
{
	int		i;

	i = 0;
	while (s != 0)
	{
		if (b == 1 && (s % 16) >= 10)
			r[l - i - 1] = s % 16 + 87;
		else if (b == 0 && s % 16 >= 10)
			r[l - i - 1] = s % 16 + 55;
		else
		{
			r[l - i - 1] = s % 16 + 48;
		}
		i++;
		s = s / 16;
	}
	return (r);
}

int	printnumberx(unsigned int k, int b)
{
	unsigned int	s;
	char			*r;
	int				i;
	int				l;

	i = 0;
	l = 0;
	s = k;
	if (s == 0)
		return (write(1, "0", 1));
	while (k != 0)
	{
		k /= 16;
		l++;
	}
	r = (char *)malloc(sizeof(char) * (l + 1));
	if (!r)
		return (0);
	r = hexadecimalx(r, s, l, b);
	r[l] = '\0';
	i = putstrs(r);
	free(r);
	return (l);
}

static char	*hexadecimalp(unsigned long long s, char *r, int l)
{
	int	i;

	i = 0;
	while (s != 0)
	{
		if ((s % 16) >= 10)
			r[l - i - 1] = s % 16 + 87;
		else
			r[l - i - 1] = s % 16 + 48;
		i++;
		s = s / 16;
	}
	return (r);
}

int	printnumberp(unsigned long long k)
{
	unsigned long long	s;
	char				*r;
	int					i;
	int					l;

	i = 0;
	l = 0;
	s = k;
	if (k == 0)
		return (write(1, "0x0", 3));
	while (k != 0)
	{
		k /= 16;
		l++;
	}
	r = (char *)malloc(sizeof(char) * (l + 1));
	if (!r)
		return (0);
	r = hexadecimalp(s, r, l);
	r[l] = '\0';
	l += write (1, "0x", 2);
	putstrs(r);
	free(r);
	return (l);
}
