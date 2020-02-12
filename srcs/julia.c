/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:03:10 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/03/26 13:03:11 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_julia(int x, int y, t_digit *win)
{
	if (win->j_mouse && win->fract == JULIA)
	{
		win->c_r = x * 3 - 500;
		win->c_i = y * 3;
		which_one(win);
	}
	return (0);
}

void	julia_iter(t_digit *win)
{
	win->z_r = win->x / win->zoom + win->x1;
	win->z_i = win->y / win->zoom + win->y1;
	win->i = 0;
	while (win->z_r * win->z_r + win->z_i * win->z_i < 1L << 16 &&
		win->i < win->iteration)
	{
		win->tmp = win->z_r;
		win->z_r = win->z_r * win->z_r - win->z_i * win->z_i - 0.8
		+ (win->c_r / WIDTH_F);
		win->z_i = 2 * win->z_i * win->tmp + win->c_i / WIDTH_F;
		win->i++;
	}
	if (win->i == win->iteration)
		fill_pixel(win, win->x, win->y, 0x000000);
	else
		fill_pixel(win, win->x, win->y, get_color(win->i, win));
}

void	*julia_loop(void *t)
{
	t_digit *win;

	win = (t_digit *)t;
	while (win->x < win->x_max)
	{
		win->y = -1;
		while (++win->y < HEIGHT - 20)
			julia_iter(win);
		win->x++;
	}
	return (0);
}

void	init_julia(t_digit *win)
{
	win->zoom = 200;
	win->x1 = -2.125;
	win->y1 = -1.4;
	win->c_r = 16.0;
	win->c_i = 192.0;
	win->iteration = 50;
	win->j_mouse = 0;
	win->color = 0;
}

void	julia_pthread(t_digit *win)
{
	t_digit t[THREAD_NUMBER];

	win->j = 0;
	while (win->j < THREAD_NUMBER)
	{
		ft_memcpy(&t[win->j], win, sizeof(t_digit));
		t[win->j].x = win->j * WIDTH_F / THREAD_NUMBER;
		t[win->j].x_max = (win->j + 1) * WIDTH_F / THREAD_NUMBER;
		pthread_create(&(win->p_thread[win->j]), NULL, julia_loop, &t[win->j]);
		win->j++;
	}
	while (win->j--)
		pthread_join(win->p_thread[win->j], NULL);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, win->mlx_img, 10, 10);
	put_string(win);
}
