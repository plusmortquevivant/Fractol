/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:56:41 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:56:43 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/events.h"

int	close_win(int keycode, t_win *list)
{
	exit(0);
	(void)list;
	return (keycode);
}

static void	move_plane(int keycode, t_fractal *fractal)
{
	double	shift;

	shift = (fractal->max.re - fractal->min.re) * SHIFT_SCALE;
	if (keycode == KEY_A)
	{
		fractal->min.re -= shift;
		fractal->max.re -= shift;
	}
	else if (keycode == KEY_D)
	{
		fractal->min.re += shift;
		fractal->max.re += shift;
	}
	else if (keycode == KEY_W)
	{
		fractal->min.im += shift;
		fractal->max.im += shift;
	}
	else
	{
		fractal->min.im -= shift;
		fractal->max.im -= shift;
	}
}

int	key_hook(int keycode, t_win *list)
{
	t_fractal	*fractal;

	fractal = list->fractal;
	if (keycode == KEY_ESC)
		close_win(keycode, list);
	else if (keycode == KEY_Q)
		fractal->max_iter = (int)(fractal->max_iter * 0.95);
	else if (keycode == KEY_E)
		fractal->max_iter = (int)(fractal->max_iter * 1.05);
	else if (keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_W)
		move_plane(keycode, fractal);
	else if (keycode == KEY_C)
	{
		fractal->color += 1;
		fractal->color %= 4;
	}
	else
		return (keycode);
	draw_fractal(list);
	return (keycode);
}

static void	zoom(t_fractal *fractal, double x, double y, double zoom_scale)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = fractal->min.re + x * fractal->scale.re;
	mouse_y = fractal->max.im - y * fractal->scale.im;
	fractal->min.re = mouse_x + (fractal->min.re - mouse_x) * zoom_scale;
	fractal->min.im = mouse_y + (fractal->min.im - mouse_y) * zoom_scale;
	fractal->max.re = mouse_x + (fractal->max.re - mouse_x) * zoom_scale;
	fractal->max.im = mouse_y + (fractal->max.im - mouse_y) * zoom_scale;
}

int	mouse_button(int button, int x, int y, t_win *list)
{
	double	zoom_scale;

	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		if (button == MOUSE_SCROLL_UP)
			zoom_scale = ZOOM_IN_SCALE;
		else
			zoom_scale = ZOOM_OUT_SCALE;
		zoom(list->fractal, x, y, zoom_scale);
		draw_fractal(list);
	}
	return (0);
}
