/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:13:23 by smikayel          #+#    #+#             */
/*   Updated: 2022/06/06 15:47:48 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// first and last walls checker
int	wall(char *w)
{
	int	index;

	index = 0;
	while (w[index] != '\0')
	{
		if (w[index] != '1')
			return (0);
		index++;
	}
	return (1);
}

int	fwall(char **splited_map, int index)
{
	int	i;

	i = 1;
	while (i < index)
	{
		if (splited_map[i][0] != '1' ||
			splited_map[i][ft_strlen(splited_map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checkvalid(t_validateMap map)
{
	if (!map.e || !map.s)
		return (0);
	else if (map.p != 1)
		get_error(5);
	return (1);
}

void	isok(char **splited_map)
{
	int	i;
	int	j;

	i = 0;
	while (splited_map[i])
	{
		j = 0;
		while (splited_map[i][j])
		{
			if (splited_map[i][j] != 'P' && splited_map[i][j] != 'E'
			&& splited_map[i][j] != 'C' && splited_map[i][j] != '1'
			&& splited_map[i][j] != '0' && splited_map[i][j] != 'G')
				get_error(6);
			j++;
		}
		i++;
	}
}

void	check_valid_endls(char *map)
{
	int	i;

	i = 0;
	if (!map)
		get_error(7);
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == map[i])
			return (get_error(6));
		i++;
	}
}
