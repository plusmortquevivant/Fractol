#include "../includes/fractol.h"

t_win	*new_image(t_win *list)
{
	list->img = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	if (!list->img)
		return (INIT_ERROR);
	list->addr = mlx_get_data_addr(list->img, &list->bpp, &list->ll, &list->en);	
	if (!list->addr)
		return (INIT_ERROR);
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
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "Fractlol");
	if (!(list->win))
		return (INIT_ERROR);
	new_image(list);
	list->fractal = init_fractal(argc, argv);
	// hooks
	draw_fractal(list);
	mlx_loop(list->mlx);

	return (list);
}

