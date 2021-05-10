/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_fun_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:30:47 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/11 01:54:16 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			ft_resolution_screen(t_struct *config)
{
	int wid;
	int hi;

	mlx_get_screen_size(config->mlx, &wid, &hi);
	if (!config->fl_screen && (config->r_width > wid || config->r_height > hi))
	{
		config->r_width = wid;
		config->r_height = hi;
	}
	if (config->fl_screen && (config->r_width > wid || config->r_height > hi))
	{
		config->r_width = wid;
		config->r_height = hi;
	}
}

void			ft_init_mlx(t_struct *config)
{
	if (!config->fl_screen)
	{
		config->mlx_win_3d = mlx_new_window(config->mlx, config->r_width,
											config->r_height, "Cub3D");
		mlx_hook(config->mlx_win_3d, 2, 0, &press_key, config);
		mlx_hook(config->mlx_win_3d, 3, 0, &anpress_key, config);
		mlx_hook(config->mlx_win_3d, 17, 0, &close_win, config);
	}
}
