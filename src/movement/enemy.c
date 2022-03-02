/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:17:51 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 17:13:44 by agrotzsc         ###   ########.fr       */
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

void	draw_enemy(t_game *game)
{
	if (game->enemy->img)
		mlx_destroy_image(game->mlx, game->enemy->img);
	if (game->enemy)
		free(game->enemy);
	if (game->enemys->img)
		mlx_destroy_image(game->mlx, game->enemys->img);
	if (game->enemys)
		free(game->enemys);
	if (game->player->img)
		mlx_destroy_image(game->mlx, game->player->img);
	if (game->player)
		free(game->player);
	if (game->keys->img)
		mlx_destroy_image(game->mlx, game->keys->img);
	if (game->keys)
		free(game->keys);
	draw_enemy2(game);
}
