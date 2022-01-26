#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include "error.h"

# define WIDTH			960
# define HEIGHT			540
# define MIN_IM 		-2.0
# define MIN_RE			-2.0
# define MAX_RE			2.0
# define MAX_IM			2.0
# define MAX_ITERATION	100
# define COLOR			0xffcccc

# define MANDELBROT		0
# define JULIA			1
# define RORSCHACH		2 //idk mb

typedef struct	s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractal
{
	int				name;
	t_complex		min;
	t_complex		max;
	t_complex		scale;
	t_complex		c;
	t_complex		k;
	int				max_iter;
	int				color;
}	t_fractal;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			ll;
	int			bpp;
	int			en;
	t_fractal	*fractal;	
}				t_win;




//win img initialisation
t_win	*new_window(int argc, char **argv);
t_win	*new_image(t_win *list);
void	my_mlx_put(t_win *data, int x, int y, int color);


//fractal handlers
t_fractal	*init_fractal(int argc, char **argv);


//basic ops
t_complex	multiple(t_complex a, t_complex b);
t_complex	add(t_complex a, t_complex b);
t_complex	divide(t_complex a, t_complex b);
double		mod(t_complex a);
int	ft_strcmp(const char *s1, const char *s2);


#endif