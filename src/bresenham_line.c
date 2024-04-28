/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:49:20 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/28 15:50:23 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*Calculate P parameter to decide weather to increment each axis*/
static void	bresenham_param(t_bresenham *param, t_point *a, t_point *b)
{
	param->dx = abs(b->x - a->x);
	param->dy = abs(b->y - a->y);
	param->step_x = 1;
	param->step_y = 1;
	if (b->x < a->x)
		param->step_x *= -1;
	if (b->y < a->y)
		param->step_y *= -1;
	param->x0 = a->x;
	param->y0 = a->y;
}

static void	slope_incr_x(t_map *data, t_point *a, t_point *b, \
	t_bresenham *param)
{
	param->p = 2 * param->dy - param->dx;
	while (param->x0 < WIDTH && param->x0 >= 0 && param->x0 != b->x)
	{
		put_pixel(&data->img, param->x0, param->y0, get_color(a, b));
		param->x0 += param->step_x;
		if (param->p >= 0)
		{
			param->p += (2 * param->dy - 2 * param->dx);
			param->y0 += param->step_y;
		}
		else
			param->p += 2 * param->dy;
	}
	put_pixel(&data->img, b->x, b->y, get_color(a, b));
}

static void	slope_incr_y(t_map *data, t_point *a, t_point *b, \
	t_bresenham *param)
{
	param->p = 2 * param->dx - param->dy;
	while (param->y0 < HEIGHT && param->y0 >= 0 && param->y0 != b->y)
	{
		put_pixel(&data->img, param->x0, param->y0, get_color(a, b));
		param->y0 += param->step_y;
		if (param->p >= 0)
		{
			param->p += (2 * param->dx - 2 * param->dy);
			param->x0 += param->step_x;
		}
		else
			param->p += 2 * param->dx;
	}
	put_pixel(&data->img, b->x, b->y, get_color(a, b));
}

static void	bresenham(t_map *data, t_bresenham *param, t_point *a, t_point *b)
{
	if (abs(param->dy) <= abs(param->dx))
		slope_incr_x(data, a, b, param);
	else
		slope_incr_y(data, a, b, param);
}

void	draw_line(t_map *data, t_point *a, t_point *b)
{
	t_bresenham	param;

	transform_map(data, a, b);
	bresenham_param(&param, a, b);
	bresenham(data, &param, a, b);
}
