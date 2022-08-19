/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:48:33 by smikayel          #+#    #+#             */
/*   Updated: 2022/08/18 16:12:18 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n - 1 && str1[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_atoi(const char *str)
{
	int			is_negative;
	long int	res;

	res = 0;
	is_negative = 1;
	if (ft_strncmp(str, "-0", 2) == 0 || ft_strncmp(str, "+0", 2) == 0)
		error(2);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		error(3);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if ((res > INT_MAX && is_negative == 1)
			|| ((res * -1) < INT_MIN && is_negative == -1))
			error(2);
		str++;
	}
	if (*str != '\0')
		error(2);
	return (res * is_negative);
}
