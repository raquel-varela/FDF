/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:51:32 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/28 18:59:58 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(sizeof(char) * total_size);
	if (!res)
	{
		free(res);
		return (NULL);
	}
	ft_strlcpy(res, s1, total_size);
	ft_strlcat(res, s2, total_size);
	return (res);
}
