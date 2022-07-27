/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:00:31 by smikayel          #+#    #+#             */
/*   Updated: 2022/02/24 14:26:54 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

int	main(int argc, char *argv[])
{
	int		i;
	char	*p;

	i = 0;
	while (i++ < argc - 2)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			p = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = p;
			i = 0;
		}
	}
	i = 0;
	while (i++ < argc - 1)
		ft_putstr(argv[i]);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if ((s1[i] != '\0' && s2[i] == '\0') || (s1[i] == '\0' && s2[i] != '\0'))
		return (s1[i] - s2[i]);
	return (r);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}
