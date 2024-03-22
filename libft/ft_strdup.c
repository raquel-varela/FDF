/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:53:14 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 08:43:15 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Returns a pointer to a new string which is a duplicate of the string s.
Memory for the new string is obtained  with  malloc(3),  and can be freed with 
free(3).*/
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
