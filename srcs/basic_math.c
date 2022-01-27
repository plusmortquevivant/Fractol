#include "../includes/fractol.h"

t_complex	multiple(t_complex a, t_complex b)
{
	t_complex	temp;

	temp.re = a.re * b.re - a.im * b.im;
	temp.im = a.re * b.im + b.re * a.im;
	return (temp);
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

static int	ft_isspace(int c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static int	ft_atoi(const char *nptr)
{
	int	sign;
	int	n;

	n = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else
	{
		sign = 1;
		if (*nptr == '+')
			nptr++;
	}
	while (ft_isdigit(*nptr))
		n = n * 10 + (*nptr++ - '0');
	return (sign * n);
}

static size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str)
	{
		str++;
	}
	return (str - s);
}

static char	*ft_strchr(const char *s, int c)
{
	const char	*str;
	char		ch;

	str = s;
	ch = c;
	while (*str)
	{
		str++;
	}
	while (str >= s)
	{
		if (*str-- == ch)
		{
			return ((char *)str + 1);
		}
	}
	return (NULL);
}

double	ft_atof(char *str)
{
	double	f_int;
	double	f_frac;
	double	sign;
	char	*str_frac;

	f_int = ft_atoi(str);
	if (f_int >= 0)
		sign = 1;
	else
	{
		sign = -1;
		f_int = 0 - f_int;
	}
	str_frac = ft_strchr(str, '.');
	if (str_frac++ != NULL)
		f_frac = ft_atoi(str_frac) / pow(10, ft_strlen(str_frac));
	else
		f_frac = 0.0;
	return (sign * (f_int + f_frac));
}