/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:52:17 by rvarela-          #+#    #+#             */
/*   Updated: 2023/12/22 18:50:36 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		str[j + i] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (0);
	while (*str != '\0' && *str != c)
		str++;
	if (*str == c)
		return (str);
	return (0);
}
