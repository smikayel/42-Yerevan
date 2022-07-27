/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:11:04 by smikayel          #+#    #+#             */
/*   Updated: 2022/02/12 14:15:30 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	is_printable;
	int	tmp;

	tmp = 0;
	is_printable = 1;
	while (*str != '\0')
	{
		tmp = *str;
		if (tmp > 126 || tmp < 32)
		{
			is_printable = 0;
			break ;
		}
		str++;
	}
	return (is_printable);
}
