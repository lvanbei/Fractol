/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:02:36 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/03/26 16:40:47 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_string(t_digit *win)
{
	win->number = ft_itoa(ABS((long long)win->zoom));
	win->text = ft_strjoin("zoom : ", win->number);
	mlx_string_put(win->mlx_ptr, win->mlx_win, 20, 20, 0xFFFFFF, win->text);
	ft_strdel(&win->text);
	ft_strdel(&win->number);
	win->number = ft_itoa(win->mouse_x);
	win->text = ft_strjoin("mouse X : ", win->number);
	mlx_string_put(win->mlx_ptr, win->mlx_win, 20, 20 + 20, 0xFFFFFF,
		win->text);
	ft_strdel(&win->text);
	ft_strdel(&win->number);
	win->number = ft_itoa(win->mouse_y);
	win->text = ft_strjoin("mouse Y : ", win->number);
	mlx_string_put(win->mlx_ptr, win->mlx_win, 20, 20 + 40, 0xFFFFFF,
		win->text);
	ft_strdel(&win->text);
	ft_strdel(&win->number);
	win->number = ft_itoa(win->iteration);
	win->text = ft_strjoin("iteration : ", win->number);
	mlx_string_put(win->mlx_ptr, win->mlx_win, 20, 20 + 60, 0xFFFFFF,
		win->text);
	ft_strdel(&win->text);
	ft_strdel(&win->number);
}

void	background(t_digit *win)
{
	int x;
	int y;

	x = 8;
	while (x++ <= WIDTH_F + 9)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, 9, 0x0072EA);
	x = 8;
	while (x++ <= WIDTH_F + 9)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, x, HEIGHT - 10, 0x0072EA);
	y = 8;
	while (y++ <= HEIGHT - 11)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, 9, y, 0x0072EA);
	y = 8;
	while (y++ <= HEIGHT - 11)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, WIDTH_F + 10, y, 0x0072EA);
}

void	summary(void)
{
	ft_putendl("\033[36;01m/---- Fractol Summary ----\\");
	ft_putendl("\033[33;01m  --- Only KeyBoard ---");
	ft_putendl("\033[33;01m Arrows : fractal position");
	ft_putendl("\033[33;01m Key_C : Change color");
	ft_putendl("\033[33;01m Key_K : decreases iteration");
	ft_putendl("\033[33;01m Key_I : increases iteration");
	ft_putendl("\033[33;01m Key_ENTER : reset parameters");
	ft_putendl("\033[33m      -- Only Julia --");
	ft_putendl("\033[33m Key_J : Lock/Unlock");
	ft_putendl("\033[31;01m   --- Only Mouse ---");
	ft_putendl("\033[31;01mLeft_Clic : zoom");
	ft_putendl("\033[31;01mMouse_roll : zoom and dezoom");
	ft_putendl("\033[36;01m\\------------------------/");
}

void	besides(t_digit *win)
{
	int y;

	y = -1;
	while (++y < 600)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, 899, y, 0x0072EA);
	y = -1;
	while (++y < 600)
		mlx_pixel_put(win->mlx_ptr, win->mlx_win, 1200, y, 0x0072EA);
	mlx_pixel_put(win->mlx_ptr, win->mlx_win, 1199, 0, 0x0072EA);
}
