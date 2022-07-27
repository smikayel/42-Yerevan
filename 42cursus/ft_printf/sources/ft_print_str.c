/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:51:19 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/28 15:51:32 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str(char *string)
{
	int	count_of_chars;

	count_of_chars = 0;
	if (!string)
	{
		count_of_chars = 6;
		write(1, "(null)", 6);
	}
	else
	{
		count_of_chars = ft_strlen(string);
		ft_putstr_fd(string, 1);
	}
	return (count_of_chars);
}
