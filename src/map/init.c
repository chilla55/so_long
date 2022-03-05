/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:35:49 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 19:47:30 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_data	*init_tile(t_game *game, char *path)
{
	t_data	*tile;
	int		height;
	int		width;

	height = 32;
	width = 32;
	tile = ft_calloc(sizeof(t_data), 1);
	if (tile == NULL)
		exit_game(game);
	tile->bits_per_pixel = 0;
	tile->line_length = 0;
	tile->endian = 0;
	tile->x = 0;
	tile->y = 0;
	tile->img = mlx_xpm_file_to_image(game->mlx, path, &height, &width);
	tile->addr = mlx_get_data_addr(tile->img, &tile->bits_per_pixel + 1, \
	&tile->line_length, &tile->endian);
	return (tile);
}

char	**init_map(t_game *game, char **argv)
{
	int		i;
	int		j;
	int		fd1;
	char	**arr;

	i = 0;
	arr = malloc(game->map_rows * sizeof(char *));
	if (arr == NULL)
		exit_game(game);
	fd1 = open(argv[1], O_RDONLY);
	while (i < game->map_rows)
	{
		arr[i] = ft_calloc(game->map_cols * sizeof(char), 1);
		if (arr[i] == NULL)
			exit_game(game);
		j = 0;
		while (j < game->map_cols)
		{
			read(fd1, &arr[i][j], 1);
			j++;
		}
		i++;
	}
	close(fd1);
	return (arr);
}

int	put_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			char_ident(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	ran_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			if (game->arr[i][j] == 'X')
			{
				if ((j + i) % 2 == 1)
					game->arr[i][j] = 'x';
			}
			j++;
		}
		i++;
	}
}
