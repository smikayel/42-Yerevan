/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:41:31 by smikayel          #+#    #+#             */
/*   Updated: 2022/06/06 16:02:24 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	null_t_validatemap(t_validateMap *map)
{
	map->e = 0;
	map->f = 0;
	map->s = 0;
	map->p = 0;
}

void	mapchecker(char **splited_map, size_t lineSize)
{
	int				index;
	size_t			j;
	t_validateMap	map;

	index = 0;
	null_t_validatemap(&map);
	while (splited_map[index] != '\0')
	{
		j = 0;
		while (j < lineSize)
		{
			if (splited_map[index][j] == 'P')
				map.p++;
			else if (splited_map[index][j] == 'C')
				map.s++;
			else if (splited_map[index][j] == 'E')
				map.e++;
			j++;
		}
		index++;
	}
	if (!checkvalid(map))
		get_error(4);
	isok(splited_map);
}

char	**check_validation(char *map)
{
	char	**splited_map;
	int		index;
	size_t	size;

	splited_map = ft_split(map, '\n');
	size = ft_strlen(splited_map[0]);
	index = 1;
	while (splited_map[index] != '\0')
	{
		if (size != ft_strlen(splited_map[index]))
			get_error(2);
		index++;
	}
	if (index <= 1)
		get_error(2);
	if (!wall(splited_map[0]) || !wall(splited_map[--index])
		|| !fwall(splited_map, index))
		get_error(3);
	mapchecker(splited_map, size);
	return (splited_map);
}
