/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:14:22 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/28 15:51:03 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	len_llu(unsigned long long nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*get_arr_llu(char *char_arr_llu, unsigned long long int nbr,
		int *j)
{
	int	tmp;
	int	i;

	i = *j;
	while (nbr != 0)
	{
		tmp = nbr % 16;
		if (tmp >= 10)
			tmp = 'a' + tmp - 10;
		else
			tmp += '0';
		char_arr_llu[i] = tmp;
		nbr /= 16;
		i++;
	}
	*j = i;
	return (char_arr_llu);
}

int	ft_print_pointer(unsigned long long int nbr)
{
	char	*char_arr_llu;
	int		len;
	int		i;

	char_arr_llu = NULL;
	write(1, "0x", 2);
	len = len_llu(nbr);
	i = 0;
	if (nbr == 0)
	{
		len += 3;
		write(1, "0", 1);
	}
	else
	{
		char_arr_llu = malloc(len);
		char_arr_llu = get_arr_llu(char_arr_llu, nbr, &i);
		len = i;
		while (--i >= 0)
			ft_putchar_fd(char_arr_llu[i], 1);
		len += 2;
	}
	free(char_arr_llu);
	return (len);
}
