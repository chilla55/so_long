/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:32:42 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 16:36:38 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (game == NULL)
		return (0);
	if (argc != 2)
		ft_print("Incorrect number of arguments!\n", game, 1, 1);
	else
		map_ending_check(argv[1], game);
	ft_load_map(argv, game);
	game_init(game, argv);
	put_map(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 33, (1L << 17), game_abort, game);
	mlx_hook(game->win, 23, (1L << 15), put_map, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (1);
}

int	game_abort(t_game *game)
{
	ft_print("Level Aborted!\n", game, 0, 1);
	return (0);
}
