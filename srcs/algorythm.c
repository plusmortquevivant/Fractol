/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:54:40 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:54:42 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	mandelbrot(int *i, t_fractal *fractal)
{
	t_complex	z;
	t_complex	z2;

	*i = 0;
	z.re = fractal->c.re;
	z.im = fractal->c.im;
	z2.re = z.re * z.re;
	z2.im = z.im * z.im;
	while (z2.re + z2.im <= 4 && *i < fractal->max_iter)
	{
		z.im = (z.re + z.re) * z.im + fractal->c.im;
		z.re = z2.re - z2.im + fractal->c.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		(*i)++;
	}
	return (z2.re + z2.im);
}

double	julia(int *i, t_fractal *fractal)
{
	t_complex	z;
	t_complex	z2;

	*i = 0;
	z.re = fractal->c.re;
	z.im = fractal->c.im;
	z2.re = z.re * z.re;
	z2.im = z.im * z.im;
	while (z2.re + z2.im <= 4 && *i < fractal->max_iter)
	{
		z.im = (z.re + z.re) * z.im + fractal->k.im;
		z.re = z2.re - z2.im + fractal->k.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		(*i)++;
	}
	return (z2.re + z2.im);
}

int	rorscharch(int *i, t_fractal *fractal)
{
	t_complex	z;
	t_complex	z2;

	*i = 0;
	z.re = fractal->c.re;
	z.im = fractal->c.im;
	z2.re = z.re * z.re;
	z2.im = z.im * z.im;
	while (z2.re + z2.im < 4 && *i < fractal->max_iter)
	{
		z.re = z2.re - z2.im - fractal->k.re;
		z.im = (2 * z.im) * fabs(z.re) - fractal->k.im;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		(*i)++;
	}
	return (z2.re + z2.im);
}
