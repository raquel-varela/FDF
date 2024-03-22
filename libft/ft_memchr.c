/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:15:52 by rvarela           #+#    #+#             */
/*   Updated: 2023/10/29 08:41:20 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*function scans the initial n bytes of the memory area pointed to by s for the
first instance of c.  Both c and the bytes of the memory area pointed to by s
are interpreted as unsigned char. Functions return a pointer to the matching 
byte or NULL if the character does not occur in the given memory area.*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
