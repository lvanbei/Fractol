/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:03:22 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/03/26 13:03:23 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot_pxl(t_digit *win, int x, int y)
{
	double zoom;
	double x1;
	double y1;

	zoom = 60;
	x1 = -17.65;
	y1 = -8.2;
	win->c_r = ((long double)x) / zoom + x1;
	win->c_i = ((long double)y) / zoom + y1;
	win->z_r = 0;
	win->z_i = 0;
	win->i = 0;
	while (win->i < win->iteration &&
		win->z_r * win->z_r + win->z_i * win->z_i < 1L << 16)
	{
		win->tmp = win->z_r;
		win->z_r = (win->z_r * win->z_r) - (win->z_i * win->z_i) + win->c_r;
		win->z_i = 2 * win->tmp * win->z_i + win->c_i;
		win->i++;
	}
	if (win->i == win->iteration)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y, 0x0);
	else
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y, get_color(win->i, win));
}

void	mandelbrot_loop_pxl(t_digit *win)
{
	int x;
	int y;

	x = 900;
	while (x < 1200)
	{
		y = 400;
		if (y - 1 == 399)
			mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y - 1, 0x0072EA);
		while (++y < 600)
			mandelbrot_pxl(win, x, y);
		if (y == 600)
			mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y - 1, 0x0072EA);
		x++;
	}
}

void	julia_pxl(t_digit *win, int x, int y)
{
	double x1;
	double y1;
	double zoom;

	x1 = -13.2;
	y1 = -3.8;
	zoom = 80;
	win->z_r = x / zoom + x1;
	win->z_i = y / zoom + y1;
	win->i = 0;
	while (win->z_r * win->z_r + win->z_i * win->z_i < 1L << 16 &&
		win->i < win->iteration)
	{
		win->tmp = win->z_r;
		win->z_r = win->z_r * win->z_r - win->z_i * win->z_i - 0.8 +
		(win->c_r / WIDTH_F);
		win->z_i = 2 * win->z_i * win->tmp + win->c_i / WIDTH_F;
		win->i++;
	}
	if (win->i == win->iteration)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y, 0x0);
	else
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y, get_color(win->i, win));
}

void	julia_loop_pxl(t_digit *win)
{
	int x;
	int y;

	x = 900;
	while (++x < 1200)
	{
		y = 200;
		if (y - 1 == 199)
			mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y - 1, 0x0072EA);
		while (++y < 400)
			julia_pxl(win, x, y);
		if (y == 400)
			mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y - 1, 0x0072EA);
	}
	if (win->fract == MANDELBROT)
		init_mandel(win);
}

void	burningship_pxl(t_digit *win, int x, int y)
{
	double zoom;
	double x1;
	double y1;

	zoom = 60;
	x1 = -17.65;
	y1 = -2.0;
	win->c_r = ((long double)x) / zoom + x1;
	win->c_i = ((long double)y) / zoom + y1;
	win->z_r = 0;
	win->z_i = 0;
	win->i = 0;
	while (win->i < win->iteration && win->z_r * win->z_r + win->z_i *
		win->z_i < 1L << 16)
	{
		win->tmp = win->z_r;
		win->z_r = (win->z_r * win->z_r) - (win->z_i * win->z_i) + win->c_r;
		win->z_i = ABS(2 * win->tmp * win->z_i) + win->c_i;
		win->i++;
	}
	if (win->i == win->iteration)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y, 0x0);
	else
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y, get_color(win->i, win));
}
