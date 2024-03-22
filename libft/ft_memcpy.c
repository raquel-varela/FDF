/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:53:20 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 08:41:32 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memcpy() function copies n bytes from memory area src to memory area dest
(doesn't take into acount NUL terminating). 
The memory areas must not overlap and returns a pointer to dest.*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (0);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
