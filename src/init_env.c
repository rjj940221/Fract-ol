/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:46:07 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/28 16:16:09 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int exposed(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void init_env(t_env *e)
{
	e->select = 0;
	e->mouse.zoom = 1;
	e->mouse.x = 0;
	e->mouse.y = 0;
	e->c.real = 0;
	e->c.im = 0;
	e->c.n_real = 0;
	e->c.n_im = 0;
	e->c.o_real = 0;
	e->c.o_im = 0;
}
