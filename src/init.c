/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 05:14:25 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/05 17:04:50 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, char **argv)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->map_cols) * 32,
			game->map_rows * 32, "So_long");
	game->map_cols = game->map_cols + 1;
	game->move_nbr = 0;
	game->floor = init_tile(game, "img/floor.xpm");
	game->player = init_tile(game, "img/player1.xpm");
	game->wall = init_tile(game, "img/wall.xpm");
	game->exit = init_tile(game, "img/portal_close.xpm");
	game->keys = init_tile(game, "img/key1.xpm");
	game->enemy = init_tile(game, "img/enemy_w_l.xpm");
	game->enemys = init_tile(game, "img/enemy_s_l.xpm");
	game->arr = init_map(game, argv);
	ran_enemy(game);
	if (!game->mlx || !game->win || !game->floor || !game->player \
	|| !game->wall || !game->exit || !game->enemy || !game->keys \
	|| !game->arr || !game->enemys)
		exit_game(game);
}
