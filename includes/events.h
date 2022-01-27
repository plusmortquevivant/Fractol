/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arichie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 23:53:18 by arichie           #+#    #+#             */
/*   Updated: 2022/01/27 23:53:21 by arichie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define MOUSE_SCROLL_UP		4
# define MOUSE_SCROLL_DOWN		5

# define KEY_ESC				53
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_F					3
# define KEY_Q					12
# define KEY_W					13
# define KEY_E					14
# define KEY_C					8

# define EVENT_KEY_PRESS		2
# define EVENT_KEY_RELEASE		3
# define EVENT_BUTTON_PRESS		4
# define EVENT_BUTTON_RELEASE	5
# define EVENT_MOTION_NOTIFY	6
# define EVENT_EXPOSE			12
# define EVENT_DESTROY			17

# define MASK_KEY_PRESS			1L
# define MASK_KEY_RELEASE		2L
# define MASK_BUTTON_PRESS		4L
# define MASK_BUTTON_RELEASE	8L
# define MASK_POINTER_MOTION	64L
# define MASK_EXPOSE			32768L
# define MASK_DESTROY			131072L

# define ZOOM_IN_SCALE			1.20
# define ZOOM_OUT_SCALE			0.80
# define SHIFT_SCALE			0.05

int	key_hook(int keycode, t_win *list);
int	close_win(int keycode, t_win *list);
int	mouse_button(int button, int x, int y, t_win *list);

#endif
