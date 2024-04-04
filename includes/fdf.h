/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:34:29 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/01 22:25:28 by rvarela          ###   ########.fr       */
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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_img
{
	int	width;
	int	height;

	
}	t_img;

typedef struct s_map
{
	int		width;
	int		height;
	char	**char_map;
	t_point	**z_matrix;

	
}	t_map;




//Handle errors
void	error_msg(char *msg);
void	input_check(int ac, char **av);
void	free_tab(char **tab);
void	free_matrix(t_map *data, int i);

//read map
void	get_char_map(t_map *data_map, char *file);
void	get_z(t_map *data_map);

//init_mlx

//transform map

//draw map



#endif