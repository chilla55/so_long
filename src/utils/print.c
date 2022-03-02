/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:29:24 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/03/02 16:41:14 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_print(char *s, t_game *game, int type, int exit)
{
	if (type == 1)
		write(2, "Error!\n", 7);
	else if (type == 2)
		write(2, "Congrats!\n", 10);
	while (*s)
	{
		write(2, s, 1);
		s++;
	}
	if (exit == 1)
		exit_game(game);
	return (0);
}
