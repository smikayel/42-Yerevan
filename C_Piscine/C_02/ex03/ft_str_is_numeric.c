/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:43:06 by smikayel          #+#    #+#             */
/*   Updated: 2022/02/12 13:46:23 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	is_numeric;
	int	tmp;

	tmp = 0;
	is_numeric = 1;
	while (*str != '\0')
	{
		tmp = *str;
		if (tmp > 57 || tmp < 48)
		{
			is_numeric = 0;
			break ;
		}
		str++;
	}
	return (is_numeric);
}
