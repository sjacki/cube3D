/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:40:54 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/11 03:59:03 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int				close_win(t_struct *config)
{
	mlx_destroy_window(config->mlx, config->mlx_win_3d);
	exit(0);
	return (0);
}

void			ver_line(int x, int draws, int drawe, t_struct *config)
{
	int z;

	z = 0;
	while (z < config->r_height)
	{
		if (z <= draws)
			my_put_px(config, x, z, config->c_color);
		if (z >= drawe)
			my_put_px(config, x, z, config->f_color);
		z++;
	}
}

void			ft_null_ray(t_raycast *ray)
{
	ray->oldpx = 0;
	ray->oldvx = 0;
	ray->speed = 0;
	ray->camx = 0;
	ray->camy = 0;
	ray->rayvx = 0;
	ray->rayvy = 0;
	ray->distx = 0;
	ray->disty = 0;
	ray->deldistx = 0;
	ray->deldisty = 0;
	ray->walldist = 0;
	ray->mx = 0;
	ray->my = 0;
	ray->walkx = 0;
	ray->walky = 0;
	ray->flag = 0;
	ray->walks = 0;
	ray->lenline = 0;
	ray->draws = 0;
	ray->drawe = 0;
	ray->ftime = 0;
	ray->movespeed = 0;
	ray->rotentionspeed = 0;
}

void			my_put_px(t_struct *config, int x, int y, int color)
{
	char	*dst;

	dst = config->addr + (y * config->line_length +
		x * (config->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			count_spr(t_struct *config)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	config->sprite->sprt_len = 0;
	while (x < ft_arrlen(config->map))
	{
		while (y < (int)ft_strlen(*config->map))
		{
			if (config->map[x][y] == '2')
				config->sprite->sprt_len++;
			y++;
		}
		y = 0;
		x++;
	}
	config->sort = (t_sort*)malloc(config->sprite->sprt_len * 32);
}
