/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:17:51 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/05 16:39:33 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_enemy2(t_game *game)
{
	if (game->move_nbr % 2 == 0)
	{
		game->enemy = init_tile(game, "img/enemy_w_l.xpm");
		game->enemys = init_tile(game, "img/enemy_s_l.xpm");
		game->player = init_tile(game, "img/player1.xpm");
		game->keys = init_tile(game, "img/key1.xpm");
	}
	else
	{
		game->enemy = init_tile(game, "img/enemy_w_r.xpm");
		game->enemys = init_tile(game, "img/enemy_s_r.xpm");
		game->player = init_tile(game, "img/player2.xpm");
		game->keys = init_tile(game, "img/key2.xpm");
	}
}

void	dest_img(t_game *game, t_data *data)
{
	if (data->img)
	{
		mlx_destroy_image(game->mlx, data->img);
	}
	if (data)
		free(data);
}

void	draw_enemy(t_game *game)
{
	if (game->end == 1)
		return ;
	dest_img(game, game->enemy);
	dest_img(game, game->enemys);
	dest_img(game, game->player);
	dest_img(game, game->keys);
	draw_enemy2(game);
}
