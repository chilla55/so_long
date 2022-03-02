/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:28:21 by agrotzsc          #+#    #+#             */
/*   Updated: 2021/06/03 00:28:21 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtn;

	if (count * size > 4294967295)
		return (NULL);
	if (count == 0 || size == 0)
		rtn = malloc (1);
	else
		rtn = malloc(count * size);
	if (!rtn)
		return (NULL);
	ft_memset(rtn, '\0', count * size);
	return (rtn);
}
