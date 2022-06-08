/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:54:51 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:54:53 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check(char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	if (*str == '.' && i <= 5)
	{
		str++;
		while (ft_isdigit(*str))
		{
			str++;
			i++;
		}
		if (*str == '\0' && i > 0 && i <= 10)
			return (1);
	}
	else if (*str == '\0' && i > 0)
		return (1);
	return (0);
}

double	get_result2(char **nbr)
{
	double	result2;

	result2 = 0;
	while (ft_isdigit(**nbr))
		(*nbr)++;
	(*nbr)--;
	while (ft_isdigit(**nbr))
	{
		result2 = (result2 + (**nbr - '0')) / 10;
		(*nbr)--;
	}
	return (result2);
}

double	get_result1(char **nbr)
{
	double	result1;

	result1 = 0;
	while (ft_isdigit(**nbr))
	{
		result1 = result1 * 10 + (**nbr - '0');
		(*nbr)++;
	}
	return (result1);
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

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
