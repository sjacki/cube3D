/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:07:06 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/16 05:34:02 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int			anpress_key(int keycode, t_struct *config)
{
	if (keycode == 13)
		config->fl_w = 0;
	if (keycode == 1)
		config->fl_s = 0;
	if (keycode == 0)
		config->fl_a = 0;
	if (keycode == 2)
		config->fl_d = 0;
	if (keycode == 12 || keycode == 123)
		config->fl_q = 0;
	if (keycode == 14 || keycode == 124)
		config->fl_e = 0;
	ft_printf("%d\n", keycode);
	return (keycode);
}

int			press_key(int keycode, t_struct *config)
{
	if (keycode == 53)
		close_win(config);
	if (keycode == 13)
		config->fl_w = 1;
	if (keycode == 1)
		config->fl_s = 1;
	if (keycode == 0)
		config->fl_a = 1;
	if (keycode == 2)
		config->fl_d = 1;
	if (keycode == 12 || keycode == 123)
		config->fl_q = 1;
	if (keycode == 14 || keycode == 124)
		config->fl_e = 1;
	ft_printf("%d\n", keycode);
	return (keycode);
}
