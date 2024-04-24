/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:48:42 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/21 15:44:49 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_x_line(t_map *data, int x, int y)
{
	t_point	a;
	t_point	b;

	a.x = x;
	a.y = y;
	a.z = data->z_matrix[y][x].z;
	a.color = data->z_matrix[y][x].color;
	b.x = x + 1;
	b.y = y;
	b.z = data->z_matrix[y][x + 1].z;
	b.color = data->z_matrix[y][x + 1].color;
	draw_line(data, &a, &b);
}

static void	draw_y_line(t_map *data, int x, int y)
{
	t_point	a;
	t_point	b;

	a.x = x;
	a.y = y;
	a.z = data->z_matrix[y][x].z;
	a.color = data->z_matrix[y][x].color;
	b.x = x;
	b.y = y + 1;
	b.z = data->z_matrix[y + 1][x].x;
	b.color = data->z_matrix[y + 1][x].color;
	draw_line(data, &a, &b);
}

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
