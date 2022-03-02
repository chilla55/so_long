/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ident.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:56:10 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 16:09:21 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	char_ident(t_game *game, int i, int j)
{
	if (game->arr[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->floor->img, j * 32, i * 32);
	else if (game->arr[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->wall->img, j * 32, i * 32);
	else if (game->arr[i][j] == 'P')
	{
		game->player->x = j * 32;
		game->player->y = i * 32;
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player->img, j * 32, i * 32);
	}
	else if (game->arr[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->keys->img, j * 32, i * 32);
	else if (game->arr[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->exit->img, j * 32, i * 32);
	else if (game->arr[i][j] == 'X')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->enemy->img, j * 32, i * 32);
	else if (game->arr[i][j] == 'x')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->enemys->img, j * 32, i * 32);
}
