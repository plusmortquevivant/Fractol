/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:55:01 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:55:03 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	my_mlx_put(t_win *list, int x, int y, int color)
{
	char	*dst;

	dst = list->addr + (y * list->ll + x * (list->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	get_color(double r, int iteration, t_fractal *fractal)
{
	double	t;

	t = (double)iteration / fractal->max_iter;
	if (fractal->color == 0)
		return ((int)(COLOR - (iteration == fractal->max_iter) * COLOR));
	if (fractal->color == 1)
		return ((int)(8.5 * (1 - t) * pow(t, 2) * 255) & 0xffff);
	if (fractal->color == 1)
		return (((int)(8.5 * (1 - t) * pow(t, 2) * 255) & 0xffff) |
		((int)(8.5 * pow((1 - t), 2) * pow(t, 1) * 255) & 0xffff) |
		((int)(8.5 * (1 - t) * pow(t, 2) * 255) & 0xffff));
	if (fractal->color == 2)
		return (((int)(3 * (1 - t) * pow(t, 2) * 255) << 16) |
		((int)(6 * pow((1 - t), 2) * pow(t, 1) * 255) << 8) |
		((int)(9 * (1 - t) * pow(t, 2) * 255) & 0xff));
	if (fractal->color == 3)
		return (((int)(3 * (1 - t) * t * 255)) << 16 |
		(((int)(15 * pow((1 - t), 2) * t * 255)) << 8) |
		((int)(iteration * (1 - iteration) * COLOR) & 0xffffff));
	return (r);
}

static double	get_escape_time(int *i, t_fractal *fractal)
{
	if (fractal->name == MANDELBROT)
		return (mandelbrot(i, fractal));
	else if (fractal->name == JULIA)
		return (julia(i, fractal));
	else if (fractal->name == RORSCHARCH)
		return (rorscharch(i, fractal));
	else
		return (0.0);
}

void	draw_fractal(t_win *list)
{
	int			x;
	int			y;
	int			i;
	double		r;
	t_fractal	*fractal;

	fractal = list->fractal;
	fractal->scale.re = (fractal->max.re - fractal->min.re) / WIDTH;
	fractal->scale.im = (fractal->max.im - fractal->min.im) / HEIGHT;
	y = -1;
	while (++y < HEIGHT)
	{
		fractal->c.im = fractal->max.im - y * fractal->scale.im;
		x = -1;
		while (++x < WIDTH)
		{
			fractal->c.re = fractal->min.re + x * fractal->scale.re;
			r = get_escape_time(&i, fractal);
			my_mlx_put(list, x, y, get_color(r, i, fractal));
		}
	}
	mlx_put_image_to_window(list->mlx,
		list->win, list->img, 0, 0);
}
