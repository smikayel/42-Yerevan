/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:14:07 by smikayel          #+#    #+#             */
/*   Updated: 2022/02/05 17:09:00 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchars(char i, char j, char k)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if (i != '7' || j != '8' || k != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	j = '0';
	k = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{	
			k = j + 1;
			while (k <= '9')
			{
				ft_putchars(i, j, k);
				k += 1;
			}
			j += 1;
		}
		i += 1;
	}
}
