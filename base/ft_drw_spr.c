/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drw_spr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:20:05 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 23:47:33 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			sort_sprite(t_struct *config, int x, int i, int z)
{
	t_sort	temp;

	x = 0;
	while (x < config->sprite->sprt_len)
	{
		config->sort[x].dist = pow(config->x_pl - config->sort[x].x, 2)\
		+ pow(config->y_pl - config->sort[x].y, 2);
		x++;
	}
	while (i < config->sprite->sprt_len - 1)
	{
		while (z < config->sprite->sprt_len - 1)
		{
			if (config->sort[z].dist < config->sort[z + 1].dist)
			{
				temp = config->sort[z];
				config->sort[z] = config->sort[z + 1];
				config->sort[z + 1] = temp;
			}
			z++;
		}
		z = 0;
		i++;
	}
}

static int		end_draw(t_struct *config, int x, int y)
{
	unsigned int	*color;
	int				y_t;
	int				temp;

	temp = (y - config->sprite->move_scr) * 256 -\
	config->r_height / 2 * 256 + config->sprite->spr_hi * 128;
	y_t = ((temp * config->sprite->height) / config->sprite->spr_hi) / 256;
	y_t = y_t < 0 ? 0 : y_t;
	color = (unsigned int*)(config->sprite->adr + config->sprite->line_len\
			* y_t + config->sprite->x_t * (config->sprite->bpp / 8));
	if ((int)*color != 0)
		my_put_px(config, x, y, (int)*color);
	return (1);
}

static void		init_spr(t_struct *config, int i)
{
	config->sprite->spr_x = config->sort[i].x - config->x_pl;
	config->sprite->spr_y = config->sort[i].y - config->y_pl;
	config->sprite->inde = 1.0 / (config->ray->px * config->ray->vy -\
	config->ray->vx * config->ray->py);
	config->sprite->trans_x = config->sprite->inde * (config->ray->vy *\
	config->sprite->spr_x - config->ray->vx * config->sprite->spr_y);
	config->sprite->trans_y = config->sprite->inde * (-config->ray->py *\
	config->sprite->spr_x + config->ray->px * config->sprite->spr_y);
	config->sprite->spr_scr = (int)((config->r_width / 2) *\
	(1 + config->sprite->trans_x / config->sprite->trans_y));
	config->sprite->move_scr = (int)(0.0 / config->sprite->trans_y);
	config->sprite->spr_hi = abs((int)(config->r_height\
	/ config->sprite->trans_y)) / 1;
	config->sprite->draw_up_y = -config->sprite->spr_hi / 2 +\
	config->r_height / 2 + config->sprite->move_scr;
}

static void		up_init(t_struct *config)
{
	if (config->sprite->draw_up_y < 0)
		config->sprite->draw_up_y = 0;
	config->sprite->draw_down_y = config->sprite->spr_hi / 2 +\
	config->r_height / 2 + config->sprite->move_scr;
	if (config->sprite->draw_down_y >= config->r_height)
		config->sprite->draw_down_y = config->r_height - 1;
	config->sprite->spr_wi = abs((int)(config->r_height /\
		config->sprite->trans_y)) / 1;
	config->sprite->draw_up_x = -config->sprite->spr_wi /\
		2 + config->sprite->spr_scr;
	if (config->sprite->draw_up_x < 0)
		config->sprite->draw_up_x = 0;
	config->sprite->draw_down_x = config->sprite->spr_wi /\
		2 + config->sprite->spr_scr;
	if (config->sprite->draw_down_x >= config->r_width)
		config->sprite->draw_down_x = config->r_width - 1;
}

void			drw_spr(t_struct *config, int x, int y, int i)
{
	while (++i < config->sprite->sprt_len)
	{
		init_spr(config, i);
		up_init(config);
		x = config->sprite->draw_up_x - 1;
		while (++x < (config->sprite->draw_down_x - 1))
		{
			config->sprite->x_t = (int)(x - (-config->sprite->spr_wi / 2 +\
			config->sprite->spr_scr)) * config->sprite->width /\
								config->sprite->spr_wi;
			config->sprite->x_t = config->sprite->x_t < 0 ?\
								0 : config->sprite->x_t;
			if (config->sprite->trans_y > 0 && x > 0 && x < config->r_width &&\
			config->sprite->trans_y < config->sprite->x_buf[x] + 0.7)
			{
				y = config->sprite->draw_up_y - 1;
				while (++y < (config->sprite->draw_down_y - 1))
					end_draw(config, x, y);
			}
		}
	}
}
