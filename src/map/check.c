/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:39:12 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/05 17:22:49 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_ending_check(char *str, t_game *game)
{
	int	name_len;

	name_len = ft_strlen(str);
	if (str[name_len - 4] != '.' || str[name_len - 3] != 'b' || \
		str[name_len - 2] != 'e' || str[name_len - 1] != 'r')
		ft_print("Wrong map extension (.ber)!\n", game, 1, 1);
}

void	ft_load_map(char **argv, t_game *game)
{
	int		fd;
	char	*str;
	char	*res;
	char	initializor;

	initializor = 0;
	str = &initializor;
	res = (char *)ft_calloc(sizeof(char), 1);
	if (res == NULL)
		exit_game(game);
	fd = open(argv[1], O_RDONLY);
	if (read(fd, NULL, 0))
	{
		free(res);
		ft_print("Map file doesn't exist!\n", game, 1, 1);
	}
	while (read(fd, str, 1))
	{
		res = ft_strjoin_free_s1(res, str);
		if (res == NULL)
			exit_game(game);
	}
	close(fd);
	rowsncols(res, game);
}

void	rowsncols(char *res, t_game *game)
{
	int	i;
	int	collen;
	int	rowlen;
	int	mapsize;

	i = 0;
	mapsize = 0;
	collen = 0;
	rowlen = 1;
	mapsize = ft_strlen(res);
	while (i <= mapsize)
	{
		if (res[i] == '\n')
			rowlen++;
		i++;
	}
	i = 0;
	while (res[i] != '\n')
		i++;
	collen = i;
	game->map_cols = collen;
	game->map_rows = rowlen;
	rectangular_check(res, game);
}

void	rectangular_check(char *res, t_game *game)
{
	int	i;
	int	col_nb;

	i = 0;
	col_nb = 1;
	while (res[i])
	{
		if ((res[i] == '\n') || (res[i + 1] == '\0'))
		{
			if (res[i] == '\n' && col_nb - 1 == game->map_cols)
				col_nb = 0;
			else if (res[i + 1] == '\0' && col_nb == game->map_cols)
				col_nb = 0;
			else
				ft_print("Not rectangular\n", game, 1, 1);
		}
		col_nb++;
		i++;
	}
	wall_check(res, game);
}

void	last_row_wall_check(char *res, t_game *game)
{
	int	i;

	i = 0;
	while (res[i])
	{
		while (res[i + 1] != '\0')
		{
			if (res[i] != '1')
				ft_print("Map is not surrounded by walls!\n", game, 1, 1);
			i++;
		}
		if (res[i + 1] == '\0')
		{
			if (res[i] != '1')
				ft_print("Map is not surrounded by walls!\n", game, 1, 1);
		}
		i++;
	}
}
