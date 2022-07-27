/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:05:08 by samirkha          #+#    #+#             */
/*   Updated: 2022/03/28 19:14:55 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static int	lenhex(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	terminal(char *hex, int index)
{
	while (index--)
		write(1, &hex[index], 1);
}

char	*printhex_help(char *hex, unsigned int n, int *j, char upp_low)
{
	int	tmp;
	int	index;

	index = *j;
	hex = malloc(lenhex(n));
	index = 0;
	while (n != 0)
	{
		tmp = n % 16;
		if (tmp < 10)
			hex[index] = tmp + '0';
		else
			hex[index] = upp_low + tmp - 10;
		n /= 16;
		index++;
	}
	terminal(hex, index);
	*j = index;
	return (hex);
}

int	hex_print(unsigned int n, char format)
{
	char	*hex;
	int		index;
	char	upp_low;

	if (format == 'X')
		upp_low = 'A';
	else
		upp_low = 'a';
	hex = NULL;
	if (n == 0)
	{
		write(1, "0", 1);
		index = 1;
	}
	else
	{
		hex = printhex_help(hex, n, &index, upp_low);
	}
	free(hex);
	return (index);
}
