/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:41:07 by smikayel          #+#    #+#             */
/*   Updated: 2022/07/26 17:41:42 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	conuterscore(char **map)
{
	int	i;
	int	j;
	int	score_count;

	i = 0;
	score_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				score_count++;
			j++;
		}
		i++;
	}
	return (score_count);
}

int	close_game(int keycode, t_player *player)
{
	(void)keycode;
	(void)player;
	exit(0);
	return (0);
}

void	finish(int isenemy)
{
	if (!isenemy)
		ft_printf("%s", ">>>>you win!<<<<\nGame over!");
	else
		ft_printf("%s", ">>>>You lose!<<<<\nGame over!");
	exit(0);
}
