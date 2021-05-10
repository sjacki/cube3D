/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:31:26 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 21:53:54 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void				move_e(t_struct *config)
{
	config->ray->oldvx = config->ray->vx;
	config->ray->vx = config->ray->vx * cos(-config->ray->rotentionspeed) -
					config->ray->vy * sin(-config->ray->rotentionspeed);
	config->ray->vy = config->ray->oldvx * sin(-config->ray->rotentionspeed)
					+ config->ray->vy * cos(-config->ray->rotentionspeed);
	config->ray->oldpx = config->ray->px;
	config->ray->px = config->ray->px * cos(-config->ray->rotentionspeed) -
						config->ray->py * sin(-config->ray->rotentionspeed);
	config->ray->py = config->ray->oldpx * sin(-config->ray->rotentionspeed)
					+ config->ray->py * cos(-config->ray->rotentionspeed);
}

void				move_q(t_struct *config)
{
	config->ray->oldvx = config->ray->vx;
	config->ray->vx = config->ray->vx * cos(config->ray->rotentionspeed) -
						config->ray->vy * sin(config->ray->rotentionspeed);
	config->ray->vy = config->ray->oldvx * sin(config->ray->rotentionspeed)
					+ config->ray->vy * cos(config->ray->rotentionspeed);
	config->ray->oldpx = config->ray->px;
	config->ray->px = config->ray->px * cos(config->ray->rotentionspeed) -
						config->ray->py * sin(config->ray->rotentionspeed);
	config->ray->py = config->ray->oldpx * sin(config->ray->rotentionspeed)
					+ config->ray->py * cos(config->ray->rotentionspeed);
}

void				move_ch(t_struct *config)
{
	if (config->fl_w)
		move_w(config);
	if (config->fl_s)
		move_s(config);
	if (config->fl_d && (config->v_pl == 'N' || config->v_pl == 'E'))
		move_d(config);
	if (config->fl_d && (config->v_pl == 'W' || config->v_pl == 'S'))
		move_a(config);
	if (config->fl_a && (config->v_pl == 'N' || config->v_pl == 'E'))
		move_a(config);
	if (config->fl_a && (config->v_pl == 'W' || config->v_pl == 'S'))
		move_d(config);
	if (config->fl_e && (config->v_pl == 'N' || config->v_pl == 'E'))
		move_e(config);
	if (config->fl_e && (config->v_pl == 'W' || config->v_pl == 'S'))
		move_q(config);
	if (config->fl_q && (config->v_pl == 'N' || config->v_pl == 'E'))
		move_q(config);
	if (config->fl_q && (config->v_pl == 'W' || config->v_pl == 'S'))
		move_e(config);
}
