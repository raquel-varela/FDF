/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela <rvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:34:29 by rvarela-          #+#    #+#             */
/*   Updated: 2024/03/30 08:58:19 by rvarela          ###   ########.fr       */
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
	int	width;
	int	height;

	
}	t_map;




//Handle errors
void	error_msg(char *msg);
void	input_check(int ac, char **av);




//read map

//init_mlx

//transform map

//draw map



#endif