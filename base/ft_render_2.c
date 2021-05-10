/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:31:38 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/11 00:00:55 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			ray_1(t_struct *config)
{
	if (config->ray->rayvx < 0)
	{
		config->ray->walkx = -1;
		config->ray->distx = (config->x_pl - config->ray->mx) *
							config->ray->deldistx;
	}
	else
	{
		config->ray->walkx = 1;
		config->ray->distx = (config->ray->mx + 1.0 - config->x_pl)
								* config->ray->deldistx;
	}
	if (config->ray->rayvy < 0)
	{
		config->ray->walky = -1;
		config->ray->disty = (config->y_pl - config->ray->my)
		* config->ray->deldisty;
	}
	else
	{
		config->ray->walky = 1;
		config->ray->disty = (config->ray->my + 1.0 - config->y_pl)
								* config->ray->deldisty;
	}
}

void			ray_2(t_struct *config)
{
	while (config->ray->flag == 0)
	{
		if (config->ray->distx < config->ray->disty)
		{
			config->ray->distx += config->ray->deldistx;
			config->ray->mx += config->ray->walkx;
			config->ray->walks = 0;
		}
		else
		{
			config->ray->disty += config->ray->deldisty;
			config->ray->my += config->ray->walky;
			config->ray->walks = 1;
		}
		if (config->map[config->ray->mx][config->ray->my] == '1')
			config->ray->flag = 1;
	}
}

void			spr(t_struct *config)
{
	if (config->sprite->sprt_len)
	{
		sort_sprite(config, 0, 0, 0);
		drw_spr(config, 0, 0, -1);
	}
}

void			init_time(t_struct *config)
{
	config->ray->x = 1;
	config->ray->ftime = (config->ray->frame - config->ray->dframe) / 1000.0;
	config->ray->movespeed = config->ray->ftime * 5.0;
	config->ray->rotentionspeed = config->ray->ftime * 3.0;
}

void			end_ray(t_struct *config)
{
	if (config->fl_screen)
		ft_mk_screenshot(config);
	mlx_put_image_to_window(config->mlx, config->mlx_win_3d,
							config->mlx_img, 0, 0);
	mlx_destroy_image(config->mlx, config->mlx_img);
	config->mlx_img = NULL;
	config->addr = NULL;
}
