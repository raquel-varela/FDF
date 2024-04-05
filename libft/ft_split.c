/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:15:24 by rvarela           #+#    #+#             */
/*   Updated: 2024/04/05 16:23:41 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (words);
}

static char	**res_init(char *str, char sep)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (count_words(str, sep) + 2));
	if (!res)
		return (NULL);
	return (res);
}

char	**ft_split(char *str, char sep)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = 0;
	j = 0;
	k = 0;
	res = res_init(str, sep);
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		j = i;
		while (str[i] && str[i] != sep)
			i++;
		if (i > j)
		{
			res[k] = ft_strncpy(res[k], &str[j], i - j);
			k++;
		}
	}
	res[k] = NULL;
	return (res);
}
