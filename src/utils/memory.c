/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:37:13 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/05 17:16:20 by agrotzsc         ###   ########.fr       */
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

void	img_free(t_game *game, t_data *tile)
{
	if (tile->img)
		mlx_destroy_image(game->mlx, tile->img);
	free(tile);
}

void	mem_free2(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
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
		if (game->enemy)
			img_free(game, game->enemy);
		if (game->enemys)
			img_free(game, game->enemys);
		if (game->arr)
			free(game->arr);
		mem_free2(game);
	}
	free(game);
}
