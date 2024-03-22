/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:11:10 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/20 16:33:00 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nb_counter(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		i;

	i = nb_counter(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	array = (char *)malloc(sizeof(char) * (nb_counter(n) + 1));
	if (!array)
		return (NULL);
	if (n == 0)
		array[0] = '0';
	if (n < 0)
	{
		array[0] = '-';
		n = n * (-1);
	}
	array[i] = '\0';
	i--;
	while (n != 0)
	{
		array[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (array);
}
