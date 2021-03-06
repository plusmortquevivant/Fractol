/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:53:26 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:53:28 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include "error.h"

# define WIDTH			800
# define HEIGHT			600
# define MIN_IM 		-2.0
# define MIN_RE			-2.0
# define MAX_RE			2.0
# define MAX_ITERATION	100
# define COLOR			0xffffff

# define MANDELBROT		0
# define JULIA			1
# define RORSCHARCH		2

typedef struct s_complex
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

typedef struct s_win
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

t_win		*new_window(int argc, char **argv);
t_win		*new_image(t_win *list);
t_fractal	*init_fractal(int argc, char **argv);
double		mandelbrot(int *i, t_fractal *fractal);
double		julia(int *i, t_fractal *fractal);
void		draw_fractal(t_win *list);
int			rorscharch(int *i, t_fractal *fractal);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
int			check(char *str);
double		get_result2(char **nbr);
double		get_result1(char **nbr);

#endif
