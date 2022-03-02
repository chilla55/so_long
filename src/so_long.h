/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:58:47 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 16:35:59 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include "../include/mlx/mlx.h"
# include "../include/libft/src/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}			t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_data	*player;
	t_data	*floor;
	t_data	*wall;
	t_data	*enemy;
	t_data	*enemys;
	t_data	*keys;
	t_data	*exit;
	char	**arr;
	int		map_rows;
	int		map_cols;
	int		collect_nbr;
	int		move_nbr;
}			t_game;

void		mem_free(t_game *game);

void		game_init(t_game *game, char **argv);
int			exit_game(t_game *game);

int			ft_print(char *s, t_game *game, int type, int exit);

void		ft_load_map(char **argv, t_game *game);
void		map_ending_check(char *str, t_game *game);
void		wall_check(char *res, t_game *game);
void		value_check(char *res, int counter, t_game *game);
void		character_check(char *res, t_game *game);
void		rectangular_check(char *res, t_game *game);
void		rowsncols(char *res, int mapsize, t_game *game);
t_data		*init_tile(t_game *game, char *path);
char		**init_map(t_game *game, char **argv);
int			put_map(t_game *game);
void		char_ident(t_game *game, int i, int j);
void		last_row_wall_check(char *res, t_game *game);
void		ran_enemy(t_game *game);

int			key_hook(int key_code, t_game *game);
void		player_movement(t_game *game, int x_diff, int y_diff);
void		print_movement(t_game *game);

void		draw_enemy(t_game *game);

int			game_abort(t_game *game);

#endif
