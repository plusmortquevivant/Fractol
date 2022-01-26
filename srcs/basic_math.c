#include "../includes/fractol.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	temp;

	temp.re = a.re + b.re;
	temp.im = a.im + b.im;
	return (temp);
}

t_complex	multiple(t_complex a, t_complex b)
{
	t_complex	temp;

	temp.re = a.re * b.re - a.im * b.im;
	temp.im = a.re * b.im + b.re * a.im;
	return (temp);
}

t_complex	divide(t_complex a, t_complex b)
{
	t_complex	temp;

	temp.re = (a.re * b.re + a.im * b.im) / (a.im * a.im + b.im * b.im);
	temp.im = (- a.re * b.im + b.re * a.im) / (a.im * a.im + b.im * b.im);
	return (temp);
}

double	mod(t_complex a)
{
	double	mod;

	mod = sqrt(a.re * a.re + a.im * a.im);
	return(mod);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == '\0')
		{
			return (0);
		}
	}
	return (*(unsigned char *)s1 - *(unsigned char *)(s2 - 1));
}