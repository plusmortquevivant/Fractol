/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:52:47 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:53:12 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define INVALID_DATA			-3
# define BAD_MEMALLOC			1
# define INIT_ERROR				-2
# define BAD_USAGE				-4

void	available_params(void);
void	inp_err(void);

#endif
