#include "fractol.h"

t_complex	add(t_complex a, t_complex b)
{
	t_complex	temp;

	temp.Re = a.Re + b.Re;
	temp.Im = a.Im + b.Im;
	return (temp);
}

t_complex	multiple(t_complex a, t_complex b)
{
	t_complex	temp;

	temp.Re = a.Re * b.Re - a.Im * b.Im;
	temp.Im = a.Re * b.Im + b.Re * a.Im;
	return (temp);
}

t_complex	divide(t_complex a, t_complex b)
{
	t_complex	temp;

	temp.Re = (a.Re * b.Re + a.Im * b.Im) / (a.Im * a.Im + b.Im * b.Im);
	temp.Im = (- a.Re * b.Im + b.Re * a.Im) / (a.Im * a.Im + b.Im * b.Im);
	return (temp);
}

double	mod(t_complex a)
{
	double	mod;

	mod = sqrt(a.Re * a.Re + a.Im * a.Im);
	return(mod);
}