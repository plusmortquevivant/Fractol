#include "../includes/fractol.h"

void	choose_your_fighter(t_fractal *fractal, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fractal->name = MANDELBROT;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		fractal->name = JULIA;
		if (argc == 2)
		{
			fractal->k.re = -0.4;
			fractal->k.im = 0.6;
		}
		else if (argc == 4)
		{
			fractal->k.re = ft_atof(argv[2]);
			fractal->k.im = ft_atof(argv[3]);
		}
		else
			exit(INVALID_NAME);
	}
	else if (ft_strcmp(argv[1], "rorscharch") == 0)
		fractal->name = RORSCHACH;
	else
	{
		printf("Invalid fractal name.\n");
		printf("Choose ur fighter: mandelbrot, julia, rorscharch\n");
		exit(INVALID_NAME);
	}
}

t_fractal	*init_fractal(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (BAD_MEMALLOC);
	choose_your_fighter(fractal, argc, argv);
	fractal->min.re = MIN_RE;
	fractal->min.im = MIN_IM;
	fractal->max.re = MAX_RE;
	fractal->max.im = MIN_IM + (MAX_RE - MIN_RE) * HEIGHT / WIDTH;
	fractal->max_iter = MAX_ITERATION;
	fractal->color = 0;
	return (fractal);
}