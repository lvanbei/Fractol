/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:28:37 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/03/26 14:28:38 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_error(void)
{
	ft_putendl("\033[32;01mUsage ./fractol : ");
	ft_putendl("\033[33;01m--> mandelbrot");
	ft_putendl("\033[34;01m--> julia");
	ft_putendl("\033[35;01m--> burningship");
	return (0);
}

int		ft_close(t_digit *win)
{
	mlx_clear_window(win->mlx_ptr, win->mlx_win);
	exit(1);
	return (0);
}

int		get_color(int color, t_digit *win)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (win->color)
	{
		if (win->color == 1)
			return (color * RED);
		if (win->color == 2)
			return (color * YELLOW);
		if (win->color == 3)
			return (color * GREEN);
		if (win->color == 4)
			return (color * PURPLE);
		if (win->color == 5)
			return (color * 256266);
	}
	t = (float)color / (float)win->iteration;
	r = ((int)(9.0 * (1.0 - t) * t * t * t * 255.0) << 16);
	g = ((int)(15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0) << 8);
	b = (int)(8.5 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0);
	return (r | g | b);
}

void	fill_pixel(t_digit *win, int x, int y, int color)
{
	char	r;
	char	g;
	char	b;
	int		len;

	len = 4 * ((WIDTH_F) * y + x);
	r = (int)((color & 16711680) >> 16);
	g = (int)((color & 65280) >> 8);
	b = (int)(color & 255);
	win->my_image_string[len] = b;
	win->my_image_string[len + 1] = g;
	win->my_image_string[len + 2] = r;
}

void	burningship_loop_pxl(t_digit *win)
{
	int x;
	int y;

	x = 900;
	while (x < 1200)
	{
		y = 1;
		if (y - 1 == 0)
			mlx_pixel_put(win->mlx_ptr, win->mlx_win, x - 1, y - 1, 0x0072EA);
		while (++y < 200)
			burningship_pxl(win, x, y);
		if (y == 200)
			mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, y - 1, 0x0072EA);
		x++;
	}
}
