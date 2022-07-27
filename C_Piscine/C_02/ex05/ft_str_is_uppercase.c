/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:53:12 by smikayel          #+#    #+#             */
/*   Updated: 2022/02/12 14:00:12 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	is_uppercase;
	int	tmp;

	tmp = 0;
	is_uppercase = 1;
	while (*str != '\0')
	{
		tmp = *str;
		if (tmp > 90 || tmp < 65)
		{
			is_uppercase = 0;
			break ;
		}
		str++;
	}
	return (is_uppercase);
}
