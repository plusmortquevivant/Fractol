#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <math.h>

typedef struct	s_complex
{
	int Re;
	int Im;	
}				t_complex;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		line_l;
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


#endif