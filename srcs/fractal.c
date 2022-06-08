/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:56:27 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:56:33 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	ft_double(char *nbr)
{
	double	result1;
	double	result2;
	int		neg;
	double	res;

	if (nbr == NULL)
		return (0);
	neg = 0;
	if (*nbr == '-')
	{
		neg = 1;
		nbr++;
	}
	result1 = get_result1(&nbr);
	result2 = 0;
	if (*nbr == '.')
	{
		nbr++;
		result2 = get_result2(&nbr);
	}
	res = result1 + result2;
	if (neg)
		res *= -1;
	return (res);
}

static void	julia_params(int argc, char **argv, t_fractal *fractal)
{
	double	max_im;

	max_im = MIN_IM + (MAX_RE - MIN_RE) * HEIGHT / WIDTH;
	if (argc == 2)
	{
		fractal->k.re = 0.285;
		fractal->k.im = 0.01;
	}
	else if (argc == 4)
	{
		if (!check(argv[2]) || !check(argv[3]))
			inp_err();
		fractal->k.re = ft_double(argv[2]);
		if ((fractal->k.re > MAX_RE) || (fractal->k.re < MIN_RE))
			inp_err();
		fractal->k.im = ft_double(argv[3]);
		if ((fractal->k.im > max_im) || (fractal->k.im < MIN_IM))
			inp_err();
	}
	else
		inp_err();
}

static void	check_args(int argc)
{
	if (argc != 2)
		inp_err();
}

static void	choose_your_fighter(t_fractal *fractal, int argc, char **argv)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		check_args(argc);
		fractal->name = MANDELBROT;
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		fractal->name = JULIA;
		julia_params(argc, argv, fractal);
	}
	else if (ft_strcmp(argv[1], "rorscharch") == 0)
	{
		check_args(argc);
		fractal->name = RORSCHARCH;
		if (argc == 2)
		{
			fractal->k.re = -0.40;
			fractal->k.im = 0.001;
		}
	}
	else
		inp_err();
}

t_fractal	*init_fractal(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		exit(BAD_MEMALLOC);
	choose_your_fighter(fractal, argc, argv);
	fractal->min.re = MIN_RE;
	fractal->min.im = MIN_IM;
	fractal->max.re = MAX_RE;
	fractal->max.im = MIN_IM + (MAX_RE - MIN_RE) * HEIGHT / WIDTH;
	fractal->max_iter = MAX_ITERATION;
	fractal->color = 0;
	return (fractal);
}
