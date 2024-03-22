/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:12:37 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 08:38:54 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*converts the initial portion of the string pointed to by nptr to int.does 
not detect errors.*/
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	return (sign * nbr);
}
