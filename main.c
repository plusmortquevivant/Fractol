#include "fractol.h"



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
		return (NULL);
	list->addr = mlx_get_data_addr(list->img, &list->bpp, &list->ll, &list->en);	
	if (!list->addr)
		return (NULL);
	//my_mlx_put(list, sin(x), x, 0x00FF0000);
	//mlx_put_image_to_window(list->mlx, list->win, list->img, 0, 0);
	return (list);
}

t_win	*new_windows(int argc, char **argv)
{
	t_win	*list;

	list = malloc(sizeof(t_win));
	if (!list)
		return (NULL);
	list->mlx = mlx_init();
	if (!(list->mlx))
		return (NULL);
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "Fractol");
	if (!(list->win))
		return (NULL);
	new_image(list);
	//generate fractal 
	// hooks
	//draw fractal
	mlx_loop(list->mlx);

	return (list);
}

int main(int argc, char **argv)
{
	// t_complex x;
	// t_complex y;
	// t_complex temp;
	if (argc < 2)
		return (1);
	new_windows(argc, argv);

	//list.mlx = mlx_init();
	//list.win = mlx_new_window(list.mlx, 960, 540, "sup");
	//list.img = mlx_new_image(list.mlx, 960, 540);
	//list.addr = mlx_get_data_addr(list.img, &list.bpp, &list.ll, &list.en);
	// my_mlx_put(&list, 5, 5, 0x00FF0000);
	// mlx_put_image_to_window(list.mlx, list.win, list.img, 0, 0);
	//mlx_loop(list.mlx);
	return (0);
}