/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:03:15 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/03/26 13:03:16 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot_iter(t_digit *win)
{
	win->c_r = ((long double)win->x) / win->zoom + win->x1;
	win->c_i = ((long double)win->y) / win->zoom + win->y1;
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
		fill_pixel(win, win->x, win->y, 0x000000);
	else
		fill_pixel(win, win->x, win->y, get_color(win->i, win));
}

void	*mandelbrot_loop(void *t)
{
	t_digit *win;

	win = (t_digit *)t;
	while (win->x < win->x_max)
	{
		win->y = -1;
		while (++win->y < HEIGHT - 20)
			mandelbrot_iter(win);
		win->x++;
	}
	return (0);
}

void	init_mandel(t_digit *win)
{
	win->zoom = 180;
	win->iteration = 50;
	win->x1 = -2.776574;
	win->y1 = -1.713453;
	win->mouse_x = 0;
	win->mouse_y = 0;
	win->color = 0;
}

void	mandelbrot_pthread(t_digit *win)
{
	t_digit t[THREAD_NUMBER];

	win->j = 0;
	while (win->j < THREAD_NUMBER)
	{
		ft_memcpy(&t[win->j], win, sizeof(t_digit));
		t[win->j].x = win->j * WIDTH_F / THREAD_NUMBER;
		t[win->j].x_max = (win->j + 1) * WIDTH_F / THREAD_NUMBER;
		pthread_create(&(win->p_thread[win->j]), NULL, mandelbrot_loop,
			&t[win->j]);
		win->j++;
	}
	while (win->j--)
		pthread_join(win->p_thread[win->j], NULL);
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_win, win->mlx_img, 10, 10);
	put_string(win);
}
