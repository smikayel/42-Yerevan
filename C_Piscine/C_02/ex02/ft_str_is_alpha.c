/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:03:29 by smikayel          #+#    #+#             */
/*   Updated: 2022/02/12 13:37:11 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	is_alpha;
	int	tmp;

	tmp = 0;
	is_alpha = 1;
	while (*str != '\0')
	{
		tmp = *str;
		if (tmp < 65 || (tmp > 90 && tmp < 97) || tmp > 122)
		{
			is_alpha = 0;
			break ;
		}
		str++;
	}
	return (is_alpha);
}
