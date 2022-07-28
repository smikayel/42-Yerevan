/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:03:40 by smikayel          #+#    #+#             */
/*   Updated: 2022/06/06 16:06:23 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *file_path)
{
	int		fd;
	char	*map;
	char	buff[2];
	int		bytes;

	map = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		get_error(1);
	while (1)
	{
		bytes = read(fd, buff, 1);
		if (!bytes)
			break ;
		buff[bytes] = '\0';
		if (!map)
			map = ft_strdup(buff);
		else
			map = ft_strjoin(map, buff);
	}
	return (map);
}
