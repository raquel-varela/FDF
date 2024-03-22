/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:39:49 by marvin            #+#    #+#             */
/*   Updated: 2023/10/08 21:39:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* copies n bytes from memory area src to memory area dest.  The memory areas
may overlap: copying takes place as though the bytes in src are first copied
into a temporary array that does not overlap src or dest, and the bytes are
then copied from the temporary array to dest. Returns a pointer to dest.*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!src && !dest)
		return (0);
	if (dest > src)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
