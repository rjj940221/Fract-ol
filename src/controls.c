/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 09:22:26 by arnovan-          #+#    #+#             */
/*   Updated: 2016/09/28 16:46:31 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		quitwin(t_env *e)
{
	//free variables	
	mlx_destroy_image(e->mlx, e->img);
	exit(0);
}

int	key_press(int keycode, t_env *e)
{
	if (keycode == KB_1)
	{
		e->select = 1;
		draw(e);
	}
	else if (keycode == KB_2)
	{
		e->select = 2;
		draw(e);
	}
	else if (keycode == KB_3)
	{
		e->select = 3;
		draw(e);
	}
	else if (keycode == KB_ESC)
		quitwin(e);
	return (0);
}

int	mouse_button(int key, int x, int y, t_env *e)
{
	if (e->select != 0)
	{
		if (key == 4)
		{
			e->mouse.z_x = (double)x * 0.001;
			e->mouse.z_y = (double)y * 0.001;
			e->mouse.zoom += 0.3;
		}
		else if (key == 5)
		{
			e->mouse.z_x = x;
			e->mouse.z_y = y;
			e->mouse.zoom -= 0.3;
		}
		mlx_destroy_image(e->mlx, e->img);
		draw(e);
	}
	return (0);
}

int	mouse_move(int x, int y, t_env *e)
{
	if (e->select != 0)
	{
		printf("mouse %i\n", x);
		e->mouse.x = (double)x * 0.001;
		e->mouse.y = (double)y * 0.001;
		mlx_destroy_image(e->mlx, e->img);
		draw(e);
	}
	return (0);
}
