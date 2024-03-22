/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:33:37 by rvarela-          #+#    #+#             */
/*   Updated: 2023/10/29 08:43:05 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*function returns a pointer to the first occurrence of the
character c in the string s. return a pointer  to  the  matched
character  or NULL if the character is not found.  The terminating null
byte is considered part of the string, so that if  c  is  specified  as
'\0', these functions return a pointer to the terminator.*/
char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0' && *s != ch)
		s++;
	if (*s == ch)
		return ((char *)s);
	return (0);
}
