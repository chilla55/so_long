/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:29:41 by agrotzsc          #+#    #+#             */
/*   Updated: 2021/08/09 16:05:00 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_length(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	itoa_loop(int n, int len, char *str)
{
	if (n != 0 && len >= 0)
	{
		str[len-- - 1] = n % 10 + 48;
		n = n / 10;
		itoa_loop(n, len, str);
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = itoa_length(n);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[len-- - 1] = '8';
			n = n / 10;
		}
		n *= -1;
	}
	itoa_loop(n, len, str);
	return (str);
}
