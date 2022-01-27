/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:14:09 by arichie           #+#    #+#             */
/*   Updated: 2022/01/28 01:14:11 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	available_params(void)
{
	printf("USAGE: ./fractol \"fractal_name\" \"k_re\" \"k_im\"\n");
	printf("Available fractal names:\n");
	printf("\tmandelbrot\n");
	printf("\tjulia\n");
	printf("\trorscharch\n");
	printf("Examples of initial k_re and k_im for julia:\n");
	printf("\t-0.835\t0.232\n");
	printf("\t-0.8\t0.156\n");
	printf("\t0.285\t0.01\n");
}

void	inp_err(void)
{
	printf("Data input error\n");
	exit(INVALID_DATA);
}
