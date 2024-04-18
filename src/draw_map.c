/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:48:42 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/14 19:02:39 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_map(t_map *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_x_line(data, x, y);
			if (y < data->height - 1)
				draw_y_line(data, x, y);
			x++;
		}
		free (data->z_matrix[y]);
		y++;
	}
	free(data->z_matrix);
}
