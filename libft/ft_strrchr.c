/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:21:22 by rvarela           #+#    #+#             */
/*   Updated: 2023/10/13 14:21:22 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	while (s_len > 0 && s[s_len] != (char)c)
		s_len--;
	if (s[s_len] == (char)c)
		return ((char *)&s[s_len]);
	return (0);
}
