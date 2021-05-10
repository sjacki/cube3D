/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ch_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:31:26 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 19:39:22 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void				move_w(t_struct *config)
{
	if (config->map[(int)(config->x_pl + config->ray->vx *
			config->ray->movespeed)][(int)(config->y_pl)] != '1' &&
			config->map[(int)(config->x_pl + config->ray->vx *
			config->ray->movespeed)][(int)(config->y_pl)] != '2')
		config->x_pl += config->ray->vx * config->ray->movespeed;
	if (config->map[(int)(config->x_pl)][(int)(config->y_pl +
			config->ray->vy * config->ray->movespeed)] != '1' &&
			config->map[(int)(config->x_pl)][(int)(config->y_pl +
			config->ray->vy * config->ray->movespeed)] != '2')
		config->y_pl += config->ray->vy * config->ray->movespeed;
}

void				move_a(t_struct *config)
{
	if (config->map[(int)(config->x_pl - config->ray->vy *
			config->ray->movespeed)][(int)(config->y_pl)] != '1' &&
			config->map[(int)(config->x_pl - config->ray->vy *
			config->ray->movespeed)][(int)(config->y_pl)] != '2')
		config->x_pl -= config->ray->vy * config->ray->movespeed;
	if (config->map[(int)(config->x_pl)][(int)(config->y_pl +
			config->ray->vx * config->ray->movespeed)] != '1' &&
			config->map[(int)(config->x_pl)][(int)(config->y_pl +
			config->ray->vx * config->ray->movespeed)] != '2')
		config->y_pl += config->ray->vx * config->ray->movespeed;
}

void				move_d(t_struct *config)
{
	if (config->map[(int)(config->x_pl + config->ray->vy *
			config->ray->movespeed)][(int)(config->y_pl)] != '1' &&
			config->map[(int)(config->x_pl + config->ray->vy *
			config->ray->movespeed)][(int)(config->y_pl)] != '2')
		config->x_pl += config->ray->vy * config->ray->movespeed;
	if (config->map[(int)(config->x_pl)][(int)(config->y_pl -
			config->ray->vx * config->ray->movespeed)] != '1' &&
			config->map[(int)(config->x_pl)][(int)(config->y_pl -
			config->ray->vx * config->ray->movespeed)] != '2')
		config->y_pl -= config->ray->vx * config->ray->movespeed;
}

void				move_s(t_struct *config)
{
	if (config->map[(int)(config->x_pl - config->ray->vx *
			config->ray->movespeed)][(int)(config->y_pl)] != '1' &&
			config->map[(int)(config->x_pl - config->ray->vx *
			config->ray->movespeed)][(int)(config->y_pl)] != '2')
		config->x_pl -= config->ray->vx * config->ray->movespeed;
	if (config->map[(int)(config->x_pl)][(int)(config->y_pl -
			config->ray->vy * config->ray->movespeed)] != '1' &&
			config->map[(int)(config->x_pl)][(int)(config->y_pl -
			config->ray->vy * config->ray->movespeed)] != '2')
		config->y_pl -= config->ray->vy * config->ray->movespeed;
}
