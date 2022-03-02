/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:12:01 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 16:38:07 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect(t_game *game)
{
	game->collect_nbr--;
	if (game->collect_nbr == 0)
	{	
		if (game->exit->img)
			mlx_destroy_image(game->mlx, game->exit->img);
		if (game->exit)
			free(game->exit);
		game->exit = init_tile(game, "img/portal_open.xpm");
	}
}

void	print_movement(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->move_nbr);
	put_map(game);
	mlx_string_put(game->mlx, game->win, 30, 30, 123456, moves);
	free(moves);
}

void	player_movement(t_game *game, int x_diff, int y_diff)
{
	if ((game->arr[(game->player->y / 32) + x_diff] \
		[(game->player->x / 32) + y_diff]) != '1')
	{
		if ((game->arr[(game->player->y / 32) + x_diff] \
		[(game->player->x / 32) + y_diff]) == 'C')
			collect(game);
		if (((game->arr[(game->player->y / 32) + x_diff] \
		[(game->player->x / 32) + y_diff]) == 'E') && game->collect_nbr == 0)
			ft_print("You Won!\n", game, 2, 1);
		else if (((game->arr[(game->player->y / 32) + x_diff] \
		[(game->player->x / 32) + y_diff]) == 'E') && game->collect_nbr > 0)
			return ;
		if (((game->arr[(game->player->y / 32) + x_diff] \
		[(game->player->x / 32) + y_diff]) == 'X'))
			ft_print("You died!\n", game, 0, 1);
		if (((game->arr[(game->player->y / 32) + x_diff] \
		[(game->player->x / 32) + y_diff]) == 'x'))
			ft_print("You died!\n", game, 0, 1);
		game->arr[(game->player->y / 32)][(game->player->x / 32)] = '0';
		game->arr[(game->player->y / 32) + x_diff] \
		[(game->player->x / 32) + y_diff] = 'P';
		game->move_nbr++;
		draw_enemy(game);
		print_movement(game);
	}
}

int	key_hook(int key_code, t_game *game)
{
	if (key_code == 65307)
		ft_print("Level Aborted!\n", game, 0, 1);
	else if ((key_code == 119) || (key_code == 65362))
		player_movement(game, -1, 0);
	else if (key_code == 97 || key_code == 65361)
		player_movement(game, 0, -1);
	else if (key_code == 115 || key_code == 65364)
		player_movement(game, 1, 0);
	else if (key_code == 100 || key_code == 65363)
		player_movement(game, 0, 1);
	return (0);
}
