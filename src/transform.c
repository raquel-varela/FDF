/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:25:57 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/28 16:00:36 by rvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	isometric_point(t_point *p)
{
	int	x_orig;
	int	y_orig;

	x_orig = p->x;
	y_orig = p->y;
	p->x = (x_orig - y_orig) * cos(M_PI * 30 / 180);
	p->y = (x_orig + y_orig) * sin(M_PI * 30 / 180) - p->z;
}

static void	scale_map(t_map *data, t_point *a, t_point *b)
{
	float	scale_factor;

	if (WIDTH / data->width <= HEIGHT / data->height)
		scale_factor = WIDTH / data->width;
	else
		scale_factor = HEIGHT / data->height;
	if (scale_factor < 4)
	{
		a->x *= 2;
		a->y *= 2;
		b->x *= 2;
		b->y *= 2;
	}
	else
	{
		a->x = round(a->x * (scale_factor / 2));
		a->y = round(a->y * (scale_factor / 2));
		b->x = round(b->x * (scale_factor / 2));
		b->y = round(b->y * (scale_factor / 2));
	}
}

static void	center_map(t_point *a, t_point *b)
{
	a->x += WIDTH * 2 / 5;
	a->y += HEIGHT / 5;
	b->x += WIDTH * 2 / 5;
	b->y += HEIGHT / 5;
}

void	transform_map(t_map *data, t_point *a, t_point *b)
{
	scale_map(data, a, b);
	isometric_point(a);
	isometric_point(b);
	center_map(a, b);
}
