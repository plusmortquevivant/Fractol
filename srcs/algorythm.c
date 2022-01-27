#include "../includes/fractol.h"
// static int	check_convergency(int *i, t_complex z, t_fractal *fractal)
// {
// 	static t_complex	old_z;
// 	static int			period;

// 	if (*i == 0)
// 	{
// 		old_z.re = 0;
// 		old_z.im = 0;
// 		period = 0;
// 		return (0);
// 	}
// 	if ((fabs(z.re - old_z.re) < EPSILON) && (fabs(z.im - old_z.im) < EPSILON))
// 	{
// 		*i = fractal->max_iter;
// 		return (1);
// 	}
// 	period++;
// 	if (period > 20)
// 	{
// 		old_z.im = z.im;
// 		old_z.re = z.re;
// 		period = 0;
// 	}
// 	return (0);
// }

double	mandelbrot(int *i, t_fractal *fractal)
{
	t_complex	z;
	t_complex	z2;

	*i = 0;
	z.re = fractal->c.re;
	z.im = fractal->c.im;
	z2.re = z.re * z.re;
	z2.im = z.im * z.im;
//	check_convergency(i, z.re, z.im, fractal);
	while (z2.re + z2.im <= 4 && *i < fractal->max_iter)
//		   && !check_convergency(i,z , fractal))
	{
		z.im = (z.re + z.re) * z.im + fractal->c.im;
		z.re = z2.re - z2.im + fractal->c.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		i++;
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
//	check_convergency(i, z.re, z.im, fractal);
	while (z2.re + z2.im <= 4 && *i < fractal->max_iter)
		//    && !check_convergency(i, z, fractal))
	{
		z.im = (z.re + z.re) * z.im + fractal->k.im;
		z.re = z2.re - z2.im + fractal->k.re;
		z2.re = z.re * z.re;
		z2.im = z.im * z.im;
		i++;
	}
	return (z2.re + z2.im);
}

// int			rorscharch(int *i, t_fractal *fractal)
// {

// }
