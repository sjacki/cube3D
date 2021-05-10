/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_fun_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:30:47 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 23:31:16 by alexandr         ###   ########.fr       */
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
		config->r_width = 10000;
		config->r_height = 10000;
	}
}