/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:02:49 by lvan-bei          #+#    #+#             */
/*   Updated: 2019/03/26 13:02:50 by lvan-bei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include <stdlib.h>
# include <pthread.h>
# include "../libft/libft.h"
# define ABS(value) ((value) < 0 ? (-value) : (value))
# define WIDTH 1250
# define WIDTH_F 850
# define HEIGHT 600
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define UP 125
# define DOWN 126
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define LEFT_CLIC 1
# define RIGHT_CLIC 2
# define MORE_DETAILS 34
# define LESS_DETAILS 40
# define RESET 36
# define KEY_C 8
# define KEY_J 38
# define RED 0xFF3333
# define GREEN 0x3FFF33
# define YELLOW 0x3333FF
# define PURPLE 0xCE33FF
# define MOTION_EVENT 6
# define PTR_MOTION_MASK (1L>>6)
# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0L
# define KEY_PRESS_EVENT 2
# define THREAD_NUMBER 32
# define MANDELBROT 11
# define JULIA 12
# define BURNINGSHIP 13

typedef struct	s_digit
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	char		*my_image_string;
	int			bpp;
	int			s_l;
	int			endian;
	double		zoom;
	double		iter;
	int			iteration;
	int			i;
	int			j;
	int			k;
	double		color;
	int			r;
	int			g;
	int			b;
	long double	c_r;
	long double	c_i;
	long double	z_r;
	long double	z_i;
	long double	x1;
	long double	y1;
	intmax_t	x;
	intmax_t	x_max;
	intmax_t	y;
	long double	tmp;
	pthread_t	p_thread[THREAD_NUMBER];
	int			fract;
	int			j_mouse;
	char		*text;
	char		*number;
	int			mouse_x;
	int			mouse_y;
}				t_digit;

int				deal_key(int key, t_digit *win);
void			*mandelbrot_loop(void *t);
void			init_win(t_digit *win, char *win_name);
void			mandelbrot_pthread(t_digit *win);
int				mouse_position(int x, int y, t_digit *win);
int				mouse_key(int key, int x, int y, t_digit *win);
void			init_mandel(t_digit *win);
void			init_julia(t_digit *win);
void			julia_iter(t_digit *win);
void			*julia_loop(void *t);
int				mouse_julia(int x, int y, t_digit *win);
void			julia_pthread(t_digit *win);
void			which_one(t_digit *win);
void			fill_pixel(t_digit *win, int x, int y, int color);
int				ft_close(t_digit *win);
void			burningship_pthread(t_digit *win);
void			*burningship_loop(void *t);
void			burningship_iter(t_digit *win);
void			background(t_digit *win);
void			put_string(t_digit *win);
void			menu(t_digit *win);
int				get_color(int color, t_digit *win);
void			summary(void);
void			besides(t_digit *win);
int				ft_error(void);
void			menu(t_digit *win);
void			mandelbrot_pxl(t_digit *win, int x, int y);
void			mandelbrot_loop_pxl(t_digit *win);
void			julia_pxl(t_digit *win, int x, int y);
void			julia_loop_pxl(t_digit *win);
void			burningship_pxl(t_digit *win, int x, int y);
void			burningship_loop_pxl(t_digit *win);

#endif
