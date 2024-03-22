/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:39:36 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 12:24:41 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Allocates with malloc and returns a substring from the string ’s’
substring begins at index ’start’ and is of max size ’len
if (len > ft_strlen(s + start)) is to check if the length of the 
substring returned by the function does not exceed the length 
of the substring starting from the start*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	j = 0;
	while (j < len)
	{
		sub[j] = s[start + j];
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
