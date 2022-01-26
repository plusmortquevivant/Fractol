#include "../includes/fractol.h"

void	my_mlx_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

t_win	*new_image(t_win *list)
{
	list->img = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	if (!list->img)
		return (INIT_ERROR);
	list->addr = mlx_get_data_addr(list->img, &list->bpp, &list->ll, &list->en);	
	if (!list->addr)
		return (INIT_ERROR);
	//my_mlx_put(list, sin(x), x, 0x00FF0000);
	//mlx_put_image_to_window(list->mlx, list->win, list->img, 0, 0);
	return (list);
}

t_win	*new_window(int argc, char **argv)
{
	t_win	*list;

	list = malloc(sizeof(t_win));
	if (!list)
		return (BAD_MEMALLOC);
	list->mlx = mlx_init();
	if (!(list->mlx))
		return (INIT_ERROR);
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "Fractol");
	if (!(list->win))
		return (INIT_ERROR);
	new_image(list);
	//generate fractal init_fractal(argc, argv);
	list->fractal = init_fractal(argc, argv);
	// hooks
	//draw fractal
	mlx_loop(list->mlx);

	return (list);
}