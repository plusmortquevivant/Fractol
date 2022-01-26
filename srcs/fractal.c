#include "../includes/fractol.h"

void	choose_your_fighter(t_fractal *fractal, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "MANDELBROT") == 0)
		fractal->name = MANDELBROT;
	else if (ft_strcmp(argv[1], "JULIA") == 0)
		fractal->name = JULIA;
	else if (ft_strcmp(argv[1], "RORSCHACH") == 0)
		fractal->name = RORSCHACH;
	else
	{
		printf("Invalid fractal name.\n");
		printf("Choose ur fighter: MANDELBROT, JULIA, RORSCHACH\n");
		exit(INVALID_NAME);
	}
	(void)argc;
}

t_fractal	*init_fractal(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal *));
	if (!fractal)
		return (BAD_MEMALLOC);
	choose_your_fighter(fractal, argc, argv);
	fractal->min.re = MIN_RE;
	fractal->min.im = MIN_IM;
	fractal->max.re = MAX_RE;
	fractal->max.im = MAX_IM;
	fractal->max_iter = MAX_ITERATION;
	fractal->color = 0;
	return (fractal);
}