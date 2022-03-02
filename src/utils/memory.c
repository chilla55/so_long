/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:37:13 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 17:16:11 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_arr(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		if (game->arr[i])
			free(game->arr[i]);
		i++;
	}
}

void	des_img(t_game *game)
{
	if (game->player->img)
		mlx_destroy_image(game->mlx, game->player->img);
	if (game->floor->img)
		mlx_destroy_image(game->mlx, game->floor->img);
	if (game->wall->img)
		mlx_destroy_image(game->mlx, game->wall->img);
	if (game->keys->img)
		mlx_destroy_image(game->mlx, game->keys->img);
	if (game->exit->img)
		mlx_destroy_image(game->mlx, game->exit->img);
	if (game->enemy->img)
		mlx_destroy_image(game->mlx, game->enemy->img);
	if (game->enemys->img)
		mlx_destroy_image(game->mlx, game->enemys->img);
}

void	img_free(t_game *game, t_data *tile)
{
	if (tile->img)
		mlx_destroy_image(game->mlx, tile->img);
	free(tile);
}

void	mem_free2(t_game *game)
{
	if (game->enemy)
		free(game->enemy);
	if (game->enemys)
		free(game->enemys);
}

void	mem_free(t_game *game)
{
	if (game->arr)
	{
		free_arr(game);
		if (game->floor)
			img_free(game, game->floor);
		if (game->player)
			img_free(game, game->player);
		if (game->wall)
			img_free(game, game->wall);
		if (game->exit)
			img_free(game, game->exit);
		if (game->keys)
			img_free(game, game->keys);
		if (game->arr)
			free(game->arr);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		if (game->mlx)
			free(game->mlx);
		mem_free2(game);
	}
	free(game);
}
