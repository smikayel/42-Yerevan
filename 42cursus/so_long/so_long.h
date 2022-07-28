/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:07:17 by smikayel          #+#    #+#             */
/*   Updated: 2022/06/06 16:22:25 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "keys.h"
# include "libftprintf.h"

# define DOOR_PATH "./Models/door.xpm"
# define CHEAS_PATH "./Models/scores/cheas.xpm"
# define ENEMY_PATH "./Models/enemy.xpm"
# define PLAYER_PATH "./Models/player.xpm"
# define FLOOR_PATH "./Models/floor/floor.xpm"
# define WALL_PATH "./Models/walls/wall.xpm"

typedef struct s_img
{
	void	*wall;
	void	*floor ;
	void	*player;
	void	*score ;
	void	*door;
	void	*enemy;
}	t_img;

typedef struct s_validateMap
{
	int	p;
	int	e;
	int	s;
	int	f;
}	t_validateMap;

typedef struct s_player
{
	char	**map;
	void	*mlx;
	void	*win;
	int		scores;
	int		steps;
	int		x;
	int		y;
	int		h;
	int		w;
}	t_player;

size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);

void	get_error(int err_num);
char	**check_validation(char *map);
int		wall(char *w);
int		fwall(char **splited_map, int index);
int		checkvalid(t_validateMap map);
void	isok(char **splited_map);
char	*read_map(char *file_path);
int		ft_height(char **map);
int		conuterscore(char **map);
void	render(void *mlx, void *win, char **map);
void	get_new_player(t_player *player);
void	get_player_cordinates(t_player *player, char **map);
void	moveup(char **map, t_player *player);
void	movedown(char **map, t_player *player);
void	moveright(char **map, t_player *player);
void	moveleft(char **map, t_player *player);
void	check_valid_endls(char *map);
int		close_game(int keycode, t_player *player);
void	finish(int isenemy);

#endif