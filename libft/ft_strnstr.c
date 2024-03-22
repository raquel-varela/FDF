/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:00:37 by rvarela           #+#    #+#             */
/*   Updated: 2023/10/29 08:44:09 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*locates the first occurrence of the null-terminated string little in the 
string big, where not more than len characters are searched.  Characters that
appear after a ‘\0’ character are not searched. If little is an empty string, 
big is returned; if little occurs nowhere in big, NULL is returned; otherwise a
pointer to the first character of the first occurrence of little is returned.*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		while (big[i + j] == little[j] && big[i + j] != '\0' && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return (NULL);
}
