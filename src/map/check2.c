/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 00:33:18 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 00:37:52 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	character_check(char *res, t_game *game)
{
	int	i;

	i = 0;
	while (res[i] != '\0')
	{
		if (!((res[i] == '1') || (res[i] == '0') || (res[i] == 'P') || \
			(res[i] == 'C') || (res[i] == 'E') || (res[i] == 'X') || \
			(res[i] == '\n') || (res[i] == '\0')))
			ft_print("Non valid character\n", game, 1, 1);
		i++;
	}
	free(res);
}

void	value_check(char *res, int counter, t_game *game)
{
	int	count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (res[counter])
	{
		if (res[counter] == 'P')
			count[0]++;
		else if (res[counter] == 'C')
			count[1]++;
		else if (res[counter] == 'E')
			count[2]++;
		counter++;
	}
	game->collect_nbr = count[1];
	if (count[0] <= 0)
		ft_print("Missing player\n", game, 1, 1);
	else if (count[0] > 1)
		ft_print("Multiple player\n", game, 1, 1);
	if (count[1] <= 0)
		ft_print("No Collectibles\n", game, 1, 1);
	if (count[2] <= 0)
		ft_print("No Exit\n", game, 1, 1);
}

void	wall_check(char *res, t_game *game)
{
	int	i;
	int	row_count;

	i = 0;
	row_count = 1;
	while (res[i])
	{
		while (i < game->map_cols)
		{
			if (res[i] != '1')
				ft_print("Missing wall\n", game, 1, 1);
			i++;
		}
		if (res[i] == '\n')
		{
			row_count++;
			if ((res[i - 1] != '1') || (res[i + 1] != '1'))
				ft_print("Missing wall\n", game, 1, 1);
		}
		else if (row_count == game->map_rows)
			last_row_wall_check(&res[i], game);
		i++;
	}
	value_check(res, 0, game);
	character_check(res, game);
}
