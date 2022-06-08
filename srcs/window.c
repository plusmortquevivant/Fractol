/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:57:00 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:57:02 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/events.h"

t_win	*new_image(t_win *list)
{
	list->img = mlx_new_image(list->mlx, WIDTH, HEIGHT);
	if (!list->img)
		exit(INIT_ERROR);
	list->addr = mlx_get_data_addr(list->img,
			&list->bpp, &list->ll, &list->en);
	if (!list->addr)
		exit(INIT_ERROR);
	return (list);
}

t_win	*new_window(int argc, char **argv)
{
	t_win	*list;

	list = malloc(sizeof(t_win));
	if (!list)
		exit(BAD_MEMALLOC);
	list->mlx = mlx_init();
	if (!(list->mlx))
		exit(INIT_ERROR);
	list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "Fractlol");
	if (!(list->win))
		exit(INIT_ERROR);
	new_image(list);
	list->fractal = init_fractal(argc, argv);
	mlx_hook(list->win,
		EVENT_KEY_PRESS, MASK_KEY_PRESS, key_hook, list);
	mlx_hook(list->win,
		EVENT_DESTROY, MASK_DESTROY, close_win, list);
	mlx_hook(list->win,
		EVENT_BUTTON_PRESS, MASK_BUTTON_PRESS, mouse_button, list);
	mlx_loop(list->mlx);
	return (list);
}
