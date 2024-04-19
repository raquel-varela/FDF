/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvarela- <rvarela-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:07:07 by rvarela-          #+#    #+#             */
/*   Updated: 2024/04/19 18:54:31 by rvarela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
//#include "../includes/fdf.h"

#define WIDTH 300
#define HEIGHT 300
#define ESC 53   // key escape
#define WHITE 0x00FFFFFF

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

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

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;


//cc -Wextra -Wall -Werror -lXext -lX11 -lbsd test_draw.c -L mlx/mlx.h mlx/libmlx.a


t_win new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}
void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h) {
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

int     exit_tutorial(t_win *window)
{
	if (window)
		mlx_destroy_window (window->mlx_ptr, window->win_ptr);
	exit(EXIT_SUCCESS);
}

int     read_keys(int key_pressed, void *param)
{
        t_img *img;

        img = (t_img *)param;
        if (key_pressed == ESC || !img)
                exit_tutorial(&img->win);
        else
                return (-1);
        mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img_ptr, 0, 0);
        return (0);
}

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)pixel = color;
	}
}

static void	bresenham(t_bresenham param, t_point a, t_point b, t_img img)
{
    param.dx = abs(b.x - a.x);
	param.dy = abs(b.y - a.y);
	param.step_x = 1;
	param.step_y = 1;
	if (b.x < a.x)
		param.step_x *= -1;
	if (b.y < a.y)
		param.step_y *= -1;
	param.x0 = a.x;
	param.y0 = a.y;
	if (param.dy <= param.dx)
	{
		param.p = 2 * param.dy - param.dx;
		while (param.x0 < b.x && param.x0 >= 0)
		{
			put_pixel(&img, param.x0, param.y0, WHITE);
			param.x0 += param.step_x;
			if (param.p >= 0)
			{
				param.p += 2* param.dy- 2* param.dx;
				param.y0 += param.step_y;
			}
			else
				param.p += 2* param.dy;
		}
	}
	else
	{
		param.p = 2 * param.dx - param.dy;
		while (param.y0 < b.y && param.y0 >= 0)
		{
			put_pixel(&img, param.x0, param.y0, WHITE);
			param.y0 += param.step_y;
            printf("y0 = %i \n", param.y0);
			if (param.p >= 0)
			{
				param.p += 2* param.dx - 2 * param.dy;
                printf("p = %i \n", param.p);
				param.x0 += param.step_x;
                printf("x0 = %i \n", param.x0);
			}
			else
            {
				param.p += 2* param.dx;
                printf("p = %i \n", param.p);
            }
		}
	}
	put_pixel(&img, b.x, b.y, WHITE);
}

int main(void)
{
    t_win       tutorial;
    t_img       image;
    //t_bresenham param;
	
    tutorial = new_program(300, 300, "TEST PROGRAM");
	if (!tutorial.mlx_ptr || !tutorial.win_ptr)
		return (1);
    image = new_img(300, 300, tutorial);
    //put_pixel_img(image, 150, 150, 0x00FFFFFF);
    bresenham((t_bresenham){}, (t_point){0, 0, 0, WHITE}, (t_point){100, 150, 0, WHITE}, image);
    mlx_put_image_to_window(image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);
	mlx_key_hook (tutorial.win_ptr, read_keys, &image);
    mlx_hook(tutorial.win_ptr, 17, 0, exit_tutorial, &tutorial);
    mlx_loop(tutorial.mlx_ptr); 
	return (0);

    /*void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return (1);
    win_ptr = mlx_new_window(mlx_ptr, 300, 300, "TEST WINDOW");
    if (!win_ptr)
        return (2);
    mlx_loop(mlx_ptr);
    return (0);*/
}
