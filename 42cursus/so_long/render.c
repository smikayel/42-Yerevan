/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:05:27 by smikayel          #+#    #+#             */
/*   Updated: 2022/06/06 15:41:06 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	get_imgs(void *mlx, t_img *img)
{
	int	size;

	img->wall = mlx_xpm_file_to_image (mlx, WALL_PATH, &size, &size);
	img->floor = mlx_xpm_file_to_image (mlx, FLOOR_PATH, &size, &size);
	img->player = mlx_xpm_file_to_image (mlx, PLAYER_PATH, &size, &size);
	img->score = mlx_xpm_file_to_image (mlx, CHEAS_PATH, &size, &size);
	img->door = mlx_xpm_file_to_image (mlx, DOOR_PATH, &size, &size);
	img->enemy = mlx_xpm_file_to_image (mlx, ENEMY_PATH, &size, &size);
}

void	render_objects(void *mlx, void *win, int *ob_info, t_img img)
{
	int		height;
	int		width;
	char	obj;

	obj = ob_info[0];
	height = ob_info[1] * 50;
	width = ob_info[2] * 50;
	mlx_put_image_to_window(mlx, win, img.floor, width, height);
	if (obj == 'C')
		mlx_put_image_to_window(mlx, win, img.score, width, height);
	else if (obj == '1')
		mlx_put_image_to_window(mlx, win, img.wall, width, height);
	else if (obj == 'P')
		mlx_put_image_to_window(mlx, win, img.player, width, height);
	else if (obj == 'E')
		mlx_put_image_to_window(mlx, win, img.door, width, height);
	else if (obj == 'L')
	{
		mlx_put_image_to_window(mlx, win, img.door, width, height);
		mlx_put_image_to_window(mlx, win, img.player, width, height);
	}
	else if (obj == 'G')
		mlx_put_image_to_window(mlx, win, img.enemy, width, height);
}

void	render(void *mlx, void *win, char **map)
{
	int		i;
	int		j;
	t_img	img;
	int		arr[3];

	i = 0;
	get_imgs(mlx, &img);
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			arr[0] = map[i][j];
			arr[1] = i;
			arr[2] = j;
			render_objects(mlx, win, arr, img);
			j++;
		}
		i++;
	}
}
