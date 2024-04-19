/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:34:29 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/19 17:11:28 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1080
# define WHITE 0x00FFFFFF
# define ESC 65307

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_img
{
	t_map	win;
	int		width;
	int		height;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		width;
	int		height;
	char	*map_name;
	char	**char_map;
	t_point	**z_matrix;
	t_img	img;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_map;

typedef struct s_bresenham
{
	int	x0;
	int	y0;
	int	dx;
	int	dy;
	int	step_x;
	int	step_y;
	int	p;
}	t_bresenham;

//Handle errors
void	error_msg(char *msg);
void	input_check(int ac, char **av);
void	free_tab(char **tab);
void	free_matrix(t_map *data, int i);
void	free_matrix_error(t_map	*data, int i, char *msg);

//read map
void	get_char_map(t_map *data_map, char *file);
void	get_z(t_map *data_map);

//draw map
void	draw_map(t_map *data);
void	draw_line(t_map *data, t_point *a, t_point *b);


//init_mlx

//transform map




#endif