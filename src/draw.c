/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 09:24:33 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/28 16:44:43 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	if (e->select == 1)
	{

	}
	else if (e->select == 2)	
	{
		julia(e);
	}
	else if (e->select == 3)
	{

	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
