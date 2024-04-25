/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:33:37 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/25 10:56:02 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_img	new_img(t_map data)
{
	t_img	img;

	img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (!img.img_ptr)
		error_msg("Failled to create an image!");
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bpp, &img.line_len, \
		&img.endian);
	img.width = WIDTH;
	img.height = HEIGHT;
	return (img);
}

static void	new_fdf_window(t_map *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
			data->map_name);
}

static int	exit_window(t_map *win)
{
	if (win)
	{
		mlx_destroy_image(win->mlx_ptr, win->img.img_ptr);
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		free(win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	read_keys(int key_pressed, void *param)
{
	t_map	*win;

	win = (t_map *)param;
	if (key_pressed == ESC || !win)
		exit_window(win);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	*data_map;

	input_check(ac, av);
	data_map = (t_map *)malloc(sizeof(t_map));
	if (!data_map)
		error_msg("Failed to create data!");
	get_char_map(data_map, av[1]);
	get_z(data_map);
	data_map->map_name = ft_strjoin("rvarela-   FDF map:    ", av[1]);
	new_fdf_window(data_map);
	data_map->img = new_img(*data_map);
	draw_map(data_map);
	mlx_put_image_to_window(data_map->mlx_ptr, data_map->win_ptr, \
		data_map->img.img_ptr, 0, 0);
	mlx_key_hook(data_map->win_ptr, &read_keys, data_map);
	mlx_hook(data_map->win_ptr, 17, 0, exit_window, data_map);
	mlx_loop(data_map->mlx_ptr);
	free(data_map);
	exit(EXIT_SUCCESS);
}
