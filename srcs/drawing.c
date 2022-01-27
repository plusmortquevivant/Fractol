#include "../includes/fractol.h"

void	my_mlx_put(t_win *list, int x, int y, int color)
{
	char	*dst;

	dst = list->addr + (y * list->ll + x * (list->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_color(int iteration, t_fractal *fractal)
{
	double	t;
	int		color;

	t = (double)iteration / fractal->max_iter;
	color = 0;
	if (fractal->color == 1)
		return ((int)(COLOR - (iteration == fractal->max_iter) * COLOR));
	return (color);
}
static double	get_escape_time(int *i, t_fractal *fractal)
{
	if (fractal->name == MANDELBROT)
		return (mandelbrot(i, fractal));
	else if (fractal->name == JULIA)
		return (julia(i, fractal));
	return (0.0);
}

void	draw_fractal(t_win *list)
{
	int			x;
	int			y;
	int			i;
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
			get_escape_time(&i, fractal);
			my_mlx_put(list, x, y, get_color(i, fractal));
		}
	}
	mlx_put_image_to_window(list->mlx,
		list->win, list->img, 0, 0);
}

