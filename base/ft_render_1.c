/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:31:38 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 20:32:27 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			draw_texture(t_struct *config)
{
	while (config->ray->y < config->ray->drawe)
	{
		config->ray->tex_y = (int)config->ray->tex_pos;
		if (config->ray->tex_y >= config->ray->height)
			config->ray->tex_y = config->ray->height - 1;
		else if (config->ray->tex_y < 0)
			config->ray->tex_y = 0;
		config->ray->tex_pos += config->ray->step;
		config->ray->color = (unsigned int*)(config->ray->adr + config->ray->\
		line_len * config->ray->tex_y + config->ray->tex_x *\
		(config->ray->bpp / 8));
		my_put_px(config, config->ray->x, config->ray->y,\
				(int)*config->ray->color);
		config->ray->y++;
	}
	ver_line(config->ray->x, config->ray->draws, config->ray->drawe, config);
	config->ray->x++;
}

void			ray_4(t_struct *config)
{
	if (config->ray->drawe >= config->r_height)
		config->ray->drawe = config->r_height - 1;
	if (config->ray->walks == 0)
		config->ray->wall_x = config->y_pl + config->ray->walldist *\
		config->ray->rayvy;
	else
		config->ray->wall_x = config->x_pl + config->ray->walldist *\
		config->ray->rayvx;
	config->ray->wall_x -= floor(config->ray->wall_x);
	ft_select_tex(config);
	config->ray->tex_x = (int)(config->ray->wall_x *\
						(double)(config->ray->width));
	if ((config->ray->walks == 0 && config->ray->rayvx > 0) ||\
			(config->ray->walks == 1 && config->ray->rayvy < 0))
		config->ray->tex_x = config->ray->width - config->ray->tex_x - 1;
	if (config->ray->tex_x >= config->ray->width)
		config->ray->tex_x = config->ray->width - 1;
	else if (config->ray->tex_x < 0)
		config->ray->tex_x = 0;
	config->ray->step = 1.0 * config->ray->height / config->ray->lenline;
	config->ray->tex_pos = (config->ray->draws - config->r_height\
						/ 2 + config->ray->lenline / 2) * config->ray->step;
	config->ray->y = config->ray->draws - 1;
}

void			ray_3(t_struct *config)
{
	if (config->ray->walks == 0)
		config->ray->walldist = (config->ray->mx - config->x_pl +
						(1 - config->ray->walkx) / 2) / config->ray->rayvx;
	else
		config->ray->walldist = (config->ray->my - config->y_pl +
						(1 - config->ray->walky) / 2) / config->ray->rayvy;
	if (config->sprite->sprt_len)
		config->sprite->x_buf[config->ray->x] = config->ray->walldist;
	config->ray->lenline = (int)(config->r_height /\
							fabs(config->ray->walldist));
	config->ray->draws = -config->ray->lenline / 2 + config->r_height / 2;
	if (config->ray->draws < 0)
		config->ray->draws = 0;
	config->ray->drawe = config->ray->lenline / 2 + config->r_height / 2;
}

void			init_img(t_struct *config)
{
	config->mlx_img = mlx_new_image(config->mlx, config->r_width,
									config->r_height);
	config->addr = mlx_get_data_addr(config->mlx_img, &config->bits_per_pixel,
									&config->line_length, &config->endian);
}

void			init_var(t_struct *config)
{
	ft_null_ray(config->ray);
	config->ray->camx = 2 * config->ray->x / (double)config->r_width - 1;
	config->ray->rayvx = config->ray->vx + config->ray->px
						* config->ray->camx;
	config->ray->rayvy = config->ray->vy + config->ray->py
						* config->ray->camx;
	config->ray->mx = (int)(config->x_pl);
	config->ray->my = (int)(config->y_pl);
	config->ray->deldistx = (config->ray->rayvy == 0) ? 0 :
	((config->ray->rayvx == 0) ? 1 : fabs(1 / config->ray->rayvx));
	config->ray->deldisty = (config->ray->rayvx == 0) ? 0 :
	((config->ray->rayvy == 0) ? 1 : fabs(1 / config->ray->rayvy));
	config->ray->flag = 0;
}
