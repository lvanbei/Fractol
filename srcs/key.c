/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:03:03 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/03/26 13:03:04 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	deal_key_2(int key, t_digit *win)
{
	if (key == RESET)
	{
		if (win->fract == MANDELBROT || win->fract == BURNINGSHIP)
			init_mandel(win);
		if (win->fract == JULIA)
			init_julia(win);
	}
	if (key == KEY_C)
	{
		win->color++;
		if (win->color >= 6)
			win->color = 0;
	}
	if (win->iteration < 0)
		win->iteration = 0;
	if (key == KEY_J)
		win->j_mouse = !win->j_mouse;
}

int		deal_key(int key, t_digit *win)
{
	if (key == 53)
	{
		mlx_clear_window(win->mlx_ptr, win->mlx_win);
		exit(0);
	}
	if (key == RIGHT)
		win->x1 -= 25 / win->zoom;
	if (key == LEFT)
		win->x1 += 25 / win->zoom;
	if (key == UP)
		win->y1 -= 25 / win->zoom;
	if (key == DOWN)
		win->y1 += 25 / win->zoom;
	if (key == MORE_DETAILS)
		win->iteration += 2;
	if (key == LESS_DETAILS)
		win->iteration -= 2;
	deal_key_2(key, win);
	which_one(win);
	return (0);
}

void	mouse_key_2(int key, int x, int y, t_digit *win)
{
	if (key == SCROLL_DOWN && (x < WIDTH_F + 10 && x > 10 &&
		y < HEIGHT + 10 && y > 10))
	{
		win->x1 = ((x / win->zoom) + win->x1) - (x / (win->zoom / 1.2));
		win->y1 = ((y / win->zoom) + win->y1) - (y / (win->zoom / 1.2));
		win->zoom /= 1.2;
		win->iteration--;
	}
	if (key == LEFT_CLIC && (x < WIDTH_F + 10 && x > 10 &&
		y < HEIGHT + 10 && y > 10))
	{
		win->x1 = ((x / win->zoom) + win->x1) - (x / (win->zoom * 1.2));
		win->y1 = ((y / win->zoom) + win->y1) - (y / (win->zoom * 1.2));
		win->zoom *= 1.2;
		win->iteration++;
	}
	if (key == SCROLL_UP && (x < WIDTH_F + 10 && x > 10 &&
		y < HEIGHT + 10 && y > 10))
	{
		win->x1 = ((x / win->zoom) + win->x1) - (x / (win->zoom * 1.2));
		win->y1 = ((y / win->zoom) + win->y1) - (y / (win->zoom * 1.2));
		win->zoom *= 1.2;
		win->iteration++;
	}
}

int		mouse_key(int key, int x, int y, t_digit *win)
{
	if (key == LEFT_CLIC && (x > 900 && x < 1200) && (y >= 400 && y < 600))
	{
		init_mandel(win);
		win->fract = MANDELBROT;
	}
	if (key == LEFT_CLIC && (x > 900 && x < 1200) && (y >= 200 && y < 400))
	{
		init_julia(win);
		win->fract = JULIA;
	}
	if (key == LEFT_CLIC && (x > 900 && x < 1200) && (y >= 0 && y < 200))
	{
		init_mandel(win);
		win->fract = BURNINGSHIP;
	}
	mouse_key_2(key, x, y, win);
	win->mouse_x = x;
	win->mouse_y = y;
	which_one(win);
	return (0);
}
