/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:26:07 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/02/11 13:26:08 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	menu(t_digit *win)
{
	mandelbrot_loop_pxl(win);
	burningship_loop_pxl(win);
	init_julia(win);
	julia_loop_pxl(win);
	besides(win);
}

int		check_argc(char *name, t_digit *win)
{
	if (!(ft_strcmp(name, "mandelbrot")))
	{
		win->fract = MANDELBROT;
		init_mandel(win);
	}
	else if (!(ft_strcmp(name, "julia")))
	{
		win->fract = JULIA;
		init_julia(win);
	}
	else if (!(ft_strcmp(name, "burningship")))
	{
		win->fract = BURNINGSHIP;
		init_mandel(win);
	}
	else
		return (0);
	return (1);
}

void	which_one(t_digit *win)
{
	if (win->fract == MANDELBROT)
		mandelbrot_pthread(win);
	if (win->fract == JULIA)
		julia_pthread(win);
	if (win->fract == BURNINGSHIP)
		burningship_pthread(win);
}

void	init_win(t_digit *win, char *win_name)
{
	win->mlx_ptr = mlx_init();
	win->mlx_img = mlx_new_image(win->mlx_ptr, WIDTH_F, HEIGHT - 20);
	win->my_image_string = mlx_get_data_addr(win->mlx_img,
	&(win->bpp), &(win->s_l), &(win->endian));
	win->mlx_win = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, win_name);
}

int		main(int argc, char **argv)
{
	t_digit		win;

	if (argc != 2)
		return (ft_error());
	if (!(check_argc(argv[1], &win)))
		return (ft_error());
	init_win(&win, "Lvan-bei - Fractol - 19");
	summary();
	background(&win);
	menu(&win);
	which_one(&win);
	mlx_hook(win.mlx_win, DESTROY_NOTIFY, NO_EVENT_MASK, ft_close, &win);
	mlx_key_hook(win.mlx_win, deal_key, &win);
	mlx_mouse_hook(win.mlx_win, mouse_key, &win);
	mlx_hook(win.mlx_win, 4, NO_EVENT_MASK, mouse_key, &win);
	mlx_hook(win.mlx_win, 6, NO_EVENT_MASK, mouse_julia, &win);
	mlx_loop(win.mlx_ptr);
	return (0);
}
