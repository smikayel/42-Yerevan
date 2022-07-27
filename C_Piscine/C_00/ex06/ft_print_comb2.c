/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:31:24 by smikayel          #+#    #+#             */
/*   Updated: 2022/02/07 17:36:28 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printing(int a, int b)
{
	char	tmp;

	tmp = a / 10 + '0';
	write(1, &tmp, 1);
	tmp = a % 10 + '0';
	write(1, &tmp, 1);
	write(1, " ", 1);
	tmp = b / 10 + '0';
	write(1, &tmp, 1);
	tmp = b % 10 + '0';
	write(1, &tmp, 1);
	if (a != 98)
	{
		write(1, ", ", 2);
	}
}

void	first_part(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			printing(a, b);
			b++;
		}
		a++;
	}
}
