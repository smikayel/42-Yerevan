/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:41:48 by smikayel          #+#    #+#             */
/*   Updated: 2022/06/06 16:02:49 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int	ft_move(int keycode, t_player *player)
{
	if (keycode == KEY_ARROW_UP || keycode == KEY_W)
		moveup(player->map, player);
	if (keycode == KEY_ARROW_DOWN || keycode == KEY_S)
		movedown(player->map, player);
	if (keycode == KEY_ARROW_RIGHT || keycode == KEY_D)
		moveright(player->map, player);
	if (keycode == KEY_ARROW_LEFT || keycode == KEY_A)
		moveleft(player->map, player);
	if (keycode == KEY_ESC)
		exit(0);
	render(player->mlx, player->win, player->map);
	return (0);
}

void	game(t_player *player)
{
	player->mlx = mlx_init();
	player->win = mlx_new_window(player->mlx, player->w * 50,
			player->h * 50, "So_long");
	render(player->mlx, player->win, player->map);
	mlx_key_hook(player->win, ft_move, player);
	mlx_hook(player->win, 17, 1L << 0, close_game, &player);
	mlx_loop(player->mlx);
}

int	main(int ac, char **av)
{
	char		**s_map;
	t_player	player;
	char		*map;

	if (ac != 2)
		get_error(1);
	map = read_map(av[1]);
	check_valid_endls(map);
	s_map = check_validation(map);
	player.map = s_map;
	player.h = ft_height(player.map);
	player.w = ft_strlen(player.map[0]);
	player.scores = conuterscore(s_map);
	get_new_player(&player);
	get_player_cordinates(&player, s_map);
	game(&player);
	return (0);
}
