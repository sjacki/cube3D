/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contr_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:00:34 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/16 08:50:18 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static void		move_pl(t_struct *config)
{
	if (config->fl_w && my_get_px(config, config->y_pl,
		config->x_pl - config->speed) != 34)
		config->x_pl -= config->speed;
	if (config->fl_s && my_get_px(config, config->y_pl,
		config->x_pl + config->speed) != 34)
		config->x_pl += config->speed;
	if (config->fl_a && my_get_px(config, config->y_pl -
		config->speed, config->x_pl) != 34)
		config->y_pl -= config->speed;
	if (config->fl_d && my_get_px(config, config->y_pl +
		config->speed, config->x_pl) != 34)
		config->y_pl += config->speed;
}

void			base_ray_dir(t_struct *config)
{
	if (config->v_pl == 'N')
		config->r_ray = 0;
	if (config->v_pl == 'S')
		config->r_ray = 180;
	if (config->v_pl == 'W')
		config->r_ray = 270;
	if (config->v_pl == 'E')
		config->r_ray = 90;
}

static void		draw_player(t_struct *config)
{
	config->square_color = 0x32CD32;
}

void			contr_pl(t_struct *config)
{
	move_pl(config);
	draw_player(config);
}
