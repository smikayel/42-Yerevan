/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moument.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:40:33 by smikayel          #+#    #+#             */
/*   Updated: 2022/07/26 19:09:28 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	e(char enemy)
{
	if (enemy == 'G')
		finish(1);
	return (1);
}

void	moveup(char **map, t_player *player)
{
	int	i;
	int	j;

	j = player->x;
	i = player->y;
	if (map[i - 1][j] && map[i - 1][j] != '1' && e(map[i - 1][j]))
	{
		if (map[i - 1][j] == 'C')
			player->scores--;
		if (map[i - 1][j] == 'E')
		{
			if (player->scores == 0)
				finish(0);
			map[i - 1][j] = 'L';
		}
		else
			map[i - 1][j] = 'P';
		if (map[i][j] == 'L')
			map[i][j] = 'E';
		else
			map[i][j] = '0';
		--player->y;
		player->steps++;
		ft_printf("You maked:%d steps\n", player->steps);
	}
}

void	movedown(char **map, t_player *player)
{
	int	i;
	int	j;

	j = player->x;
	i = player->y;
	if (map[i + 1][j] && map[i + 1][j] != '1' && e(map[i + 1][j]))
	{
		if (map[i + 1][j] == 'C')
			player->scores--;
		if (map[i + 1][j] == 'E')
		{
			if (player->scores == 0)
				finish(0);
			map[i + 1][j] = 'L';
		}
		else
			map[i + 1][j] = 'P';
		if (map[i][j] == 'L')
			map[i][j] = 'E';
		else
			map[i][j] = '0';
		++player->y;
		player->steps++;
		ft_printf("You maked:%d steps\n", player->steps);
	}
}

void	moveright(char **map, t_player *player)
{
	int	i;
	int	j;

	j = player->x;
	i = player->y;
	if (map[i][j + 1] && map[i][j + 1] != '1' && e(map[i][j + 1]))
	{
		if (map[i][j + 1] == 'C')
			player->scores--;
		if (map[i][j + 1] == 'E')
		{
			if (player->scores == 0)
				finish(0);
			map[i][j + 1] = 'L';
		}
		else
			map[i][j + 1] = 'P';
		if (map[i][j] == 'L')
			map[i][j] = 'E';
		else
			map[i][j] = '0';
		++player->x;
		player->steps++;
		ft_printf("You maked:%d steps\n", player->steps);
	}
}

void	moveleft(char **map, t_player *player)
{
	int	i;
	int	j;

	j = player->x;
	i = player->y;
	if (map[i][j - 1] && map[i][j -1] != '1' && e(map[i][j - 1]))
	{
		if (map[i][j - 1] == 'C')
			player->scores--;
		if (map[i][j - 1] == 'E')
		{
			if (player->scores == 0)
				finish(0);
			map[i][j - 1] = 'L';
		}
		else
			map[i][j - 1] = 'P';
		if (map[i][j] == 'L')
			map[i][j] = 'E';
		else
			map[i][j] = '0';
		--player->x;
		player->steps++;
		ft_printf("You maked:%d steps\n", player->steps);
	}
}
