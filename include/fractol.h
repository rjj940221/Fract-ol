/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 08:18:47 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/28 17:11:46 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

//////////////////
# include <math.h>
# include <stdio.h>
///////////////////////////

# define WIN_W 640
# define WIN_H 480

# define KB_ESC 53
# define KB_1 18
# define KB_2 19
# define KB_3 20

typedef struct	s_constant
{
	double real;
	double im;
	double n_real;
	double n_im;
	double o_real;
	double o_im;
}				t_constant;

typedef struct	s_mouse
{
	double		x;
	double		y;
	double		z_x;
	double		z_y;
	double		zoom;
}				t_mouse;

typedef struct	s_env
{
	int			select;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_mouse		mouse;
	t_constant	c;

}				t_env;

int		quitwin(t_env *e);

void	init_env(t_env *e);

int		key_press(int keycode, t_env *e);
int		mouse_button(int keycode, int x, int y, t_env *e);
int		mouse_move(int x, int y, t_env *e);
int		exposed(t_env *e);
void	draw(t_env *e);
void	julia(t_env *e);
void	mandelbrot(t_env *e);
void	burningship(t_env *e);

#endif
