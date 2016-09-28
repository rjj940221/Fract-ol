/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:12:11 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/28 17:12:17 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_env *e)
{
	int x;
	int y;
	int max;
	int i;
	//	uint32_t colour;

	e->c.real = -0.7;
	e->c.im = 0.27015;
	max = 128;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			i = 0;
			e->c.n_real = 1.5 * (x - WIN_W * 0.5) / (0.5 * e->mouse.zoom * WIN_W) + e->mouse.z_x;
			e->c.n_im = (y - WIN_H * 0.5) / (0.5 * e->mouse.zoom * WIN_H) + e->mouse.z_y;
			while (i < max && (e->c.n_real * e->c.n_real + e->c.n_im * e->c.n_im) <= 4)
			{
				e->c.o_real = e->c.n_real;
				e->c.o_im = e->c.n_im;
				e->c.n_real = e->c.o_real * e->c.o_real - e->c.o_im * e->c.o_im + e->c.real;
				e->c.n_im = 2 * e->c.o_real * e->c.o_im + e->c.im;
				i++;
			}
			e->data[(x * 4) + (y * e->size_line) + 2] = i;
			e->data[(x * 4) + (y * e->size_line) + 1] = i;
			e->data[(x * 4) + (y * e->size_line)] = i;
			x++;
		}
		y++;
	}
}
