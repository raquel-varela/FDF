/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:20:57 by rvarela           #+#    #+#             */
/*   Updated: 2023/10/27 16:00:12 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (0);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	while (ft_strchr(set, s1[j]) != 0 && j > i)
		j--;
	str = ft_substr(s1, i, j - i + 1);
	return (str);
}
