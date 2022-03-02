/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:33:38 by agrotzsc          #+#    #+#             */
/*   Updated: 2021/06/03 03:10:14 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c < -1)
		c += 256;
	else if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
