/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 08:12:56 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/28 16:44:03 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (void)
{
	t_env	e;

	init_env(&e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_W, WIN_H, "Fract'ol");
	if (e.select == 0)
	{	
		mlx_string_put(e.mlx, e.win, 50, 50, 0x7f7f7f, "Select a fractal:");
		mlx_string_put(e.mlx, e.win, 50, 70, 0x7f7f7f, "1. Mandelbrot set");
		mlx_string_put(e.mlx, e.win, 50, 90, 0x7f7f7f, "2. Julia set");
		mlx_string_put(e.mlx, e.win, 50, 110, 0x7f7f7f, "3. Burning ship");
	}
	mlx_key_hook(e.win, &key_press, &e);
	mlx_mouse_hook(e.win, &mouse_button, &e);
	mlx_hook(e.win, 6, (1L << 6), &mouse_move, &e);
	mlx_hook(e.win, 17, 0L, &quitwin, &e);
	mlx_expose_hook(e.win, &exposed, &e);
	mlx_loop(e.mlx);
	return (0);
}
