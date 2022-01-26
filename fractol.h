#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 960
# define HEIGHT 540
typedef struct	s_complex
{
	double	Re;
	double	Im;
}				t_complex;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		ll;
	int		bpp;
	int		en;
}				t_win;

typedef struct	s_point
{
	int	x;
	int y;
	int re_x;
	int im_y;
}				t_point;



t_complex	multiple(t_complex a, t_complex b);
t_complex	add(t_complex a, t_complex b);
t_complex	divide(t_complex a, t_complex b);
double		mod(t_complex a);

#endif