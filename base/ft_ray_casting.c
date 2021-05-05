/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:17:35 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/04 19:32:34 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int         create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void				draw_square(int x, int y, int size, t_struct *config)
{
	int xd;
	int yd;
	int y_bef;

	y_bef = y;
	yd = size;
	xd = size;
	while (yd)
	{
		xd = size;
		y = y_bef;
		while (xd)
		{
			my_put_px(config, x, y, config->square_color);
			y++;
			xd--;
		}
		x++;
		yd--;
	}
}

static void			draw_map(t_struct *config, int size)
{
	int x;
	int y;

	x = 1;
	while (config->map[x])
	{
		y = 0;
		while (config->map[x][y])
		{
			if (config->map[x][y] == ' ' && y++)
				continue;
			if (config->map[x][y] == '0')
				config->square_color = 0xFFDAB9;
			if (config->map[x][y] == '1')
				config->square_color = 0xB22222;
			if (config->map[x][y] == '2')
				config->square_color = 0x00FFFF;
			draw_square((y + 1) * size, x * size, size, config);
			y++;
		}
		x++;
	}
}

void				main_draw_map(t_struct *config)
{
	int size;
	int x;
	int y;

	x = 1;
	y = 0;
	size = (config->r_height / (ft_arrlen(config->map)));
	if ((config->r_width / (ft_strlen(*config->map))) <
		(size_t)(config->r_height / (ft_arrlen(config->map))))
		size = ((config->r_width) / (ft_strlen(*config->map)));
	size /= 3;
	config->px_size = size;
	draw_map(config, size);
}

void	drawpl(t_struct *config)
{
	draw_square((config->y_pl * config->px_size) + (config->px_size / 2), (config->x_pl * config->px_size)
              - (config->px_size / 2), config->px_size / 2, config);
}

int				close_win(t_struct *config)
{
	mlx_destroy_window(config->mlx, config->mlx_win_3d);
	exit(1);
	return (0);
}

void			verLine(int x, int draws, int drawe, int color, t_struct *config)
{
	int z;

	z = 0;
	while(z <= config->r_height)
	{
    if (z < draws)
      my_put_px(config, x, z, config->c_color);
		if (z >= draws && z <= drawe)
			my_put_px(config, x, z, color);
    if (z > drawe)
      my_put_px(config, x, z, config->f_color);
		z++;
	}
}

void            ft_null_ray(t_raycast *ray)
{
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

int				ft_loop_hook(t_struct *config)
{
  config->mlx_img = mlx_new_image(config->mlx, config->r_width,
										              config->r_height);
	config->addr = mlx_get_data_addr(config->mlx_img, &config->bits_per_pixel,
									                &config->line_length, &config->endian);
  for(int x = 0; x < config->r_width; x++)
  {
      ft_null_ray(config->ray);
      config->ray->camx = 2 * x / (double)config->r_width - 1; 
      config->ray->rayvx = config->ray->vx + config->ray->px * config->ray->camx;
      config->ray->rayvy = config->ray->vy + config->ray->py * config->ray->camx;
      config->ray->mx = (int)(config->x_pl);
      config->ray->my = (int)(config->y_pl);
      config->ray->deldistx = (config->ray->rayvy == 0) ? 0 : ((config->ray->rayvx == 0) ? 1 : fabs(1 / config->ray->rayvx));
      config->ray->deldisty = (config->ray->rayvx == 0) ? 0 : ((config->ray->rayvy == 0) ? 1 : fabs(1 / config->ray->rayvy));
      config->ray->flag = 0;
      if(config->ray->rayvx < 0)
      {
        config->ray->walkx = -1;
        config->ray->distx = (config->x_pl - config->ray->mx) * config->ray->deldistx;
      }
      else
      {
        config->ray->walkx = 1;
        config->ray->distx = (config->ray->mx + 1.0 - config->x_pl) * config->ray->deldistx;
      }
      if(config->ray->rayvy < 0)
      {
        config->ray->walky = -1;
        config->ray->disty = (config->y_pl - config->ray->my) * config->ray->deldisty;
      }
      else
      {
        config->ray->walky = 1;
        config->ray->disty = (config->ray->my + 1.0 - config->y_pl) * config->ray->deldisty;
      }
      while (config->ray->flag == 0)
      {
        if(config->ray->distx < config->ray->disty)
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
        if(config->map[config->ray->mx][config->ray->my] == '1')
          config->ray->flag = 1;
      }
      if(config->ray->walks == 0)
        config->ray->walldist = (config->ray->mx - config->x_pl + (1 - config->ray->walkx) / 2) / config->ray->rayvx;
      else
        config->ray->walldist = (config->ray->my - config->y_pl + (1 - config->ray->walky) / 2) / config->ray->rayvy;
      config->ray->lenline = (int)(config->r_height / config->ray->walldist);
      config->ray->draws = -config->ray->lenline / 2 + config->r_height / 2;
      if(config->ray->draws < 0)
        config->ray->draws = 0;
      config->ray->drawe = config->ray->lenline / 2 + config->r_height / 2;
      if(config->ray->drawe >= config->r_height)
        config->ray->drawe = config->r_height - 1;
      verLine(x, config->ray->draws, config->ray->drawe, 0xB22222, config);
    }
    config->ray->ftime = (config->ray->frame - config->ray->dframe) / 1000.0;
    config->ray->movespeed = config->ray->ftime * 5.0;
    config->ray->rotentionspeed = config->ray->ftime * 3.0;
    if(config->fl_w)
    {
      if(config->map[(int)(config->x_pl + config->ray->vx * config->ray->movespeed)][(int)(config->y_pl)] != '1' && config->map[(int)(config->x_pl + config->ray->vx * config->ray->movespeed)][(int)(config->y_pl)] != '2')
        config->x_pl += config->ray->vx * config->ray->movespeed;
      if(config->map[(int)(config->x_pl)][(int)(config->y_pl + config->ray->vy * config->ray->movespeed)] != '1' && config->map[(int)(config->x_pl)][(int)(config->y_pl + config->ray->vy * config->ray->movespeed)] != '2')
        config->y_pl += config->ray->vy * config->ray->movespeed;
    }
    if(config->fl_a)
    {
      if(config->map[(int)(config->x_pl - config->ray->vy * config->ray->movespeed)][(int)(config->y_pl)] != '1' && config->map[(int)(config->x_pl - config->ray->vy * config->ray->movespeed)][(int)(config->y_pl)] != '2')
        config->x_pl -= config->ray->vy * config->ray->movespeed;
      if(config->map[(int)(config->x_pl)][(int)(config->y_pl + config->ray->vx * config->ray->movespeed)] != '1' && config->map[(int)(config->x_pl)][(int)(config->y_pl + config->ray->vx * config->ray->movespeed)] != '2')
        config->y_pl += config->ray->vx * config->ray->movespeed;
    }
    if(config->fl_d)
    {
      if(config->map[(int)(config->x_pl + config->ray->vy * config->ray->movespeed)][(int)(config->y_pl)] != '1' && config->map[(int)(config->x_pl + config->ray->vy * config->ray->movespeed)][(int)(config->y_pl)] != '2')
        config->x_pl += config->ray->vy * config->ray->movespeed;
      if(config->map[(int)(config->x_pl)][(int)(config->y_pl - config->ray->vx * config->ray->movespeed)] != '1' && config->map[(int)(config->x_pl)][(int)(config->y_pl - config->ray->vx * config->ray->movespeed)] != '2')
        config->y_pl -= config->ray->vx * config->ray->movespeed;
    }
    if(config->fl_s)
    {
      if(config->map[(int)(config->x_pl - config->ray->vx * config->ray->movespeed)][(int)(config->y_pl)] != '1' && config->map[(int)(config->x_pl - config->ray->vx * config->ray->movespeed)][(int)(config->y_pl)] != '2')
        config->x_pl -= config->ray->vx * config->ray->movespeed;
      if(config->map[(int)(config->x_pl)][(int)(config->y_pl - config->ray->vy * config->ray->movespeed)] != '1' && config->map[(int)(config->x_pl)][(int)(config->y_pl - config->ray->vy * config->ray->movespeed)] != '2')
        config->y_pl -= config->ray->vy * config->ray->movespeed;
    }
    if(config->fl_e)
    {
      double oldDirX = config->ray->vx;
      config->ray->vx = config->ray->vx * cos(-config->ray->rotentionspeed) - config->ray->vy * sin(-config->ray->rotentionspeed);
      config->ray->vy = oldDirX * sin(-config->ray->rotentionspeed) + config->ray->vy * cos(-config->ray->rotentionspeed);
      double oldPlaneX = config->ray->px;
      config->ray->px = config->ray->px * cos(-config->ray->rotentionspeed) - config->ray->py * sin(-config->ray->rotentionspeed);
      config->ray->py = oldPlaneX * sin(-config->ray->rotentionspeed) + config->ray->py * cos(-config->ray->rotentionspeed);
    }
    if(config->fl_q)
    {
      double oldDirX = config->ray->vx;
      config->ray->vx = config->ray->vx * cos(config->ray->rotentionspeed) - config->ray->vy * sin(config->ray->rotentionspeed);
      config->ray->vy = oldDirX * sin(config->ray->rotentionspeed) + config->ray->vy * cos(config->ray->rotentionspeed);
      double oldPlaneX = config->ray->px;
      config->ray->px = config->ray->px * cos(config->ray->rotentionspeed) - config->ray->py * sin(config->ray->rotentionspeed);
      config->ray->py = oldPlaneX * sin(config->ray->rotentionspeed) + config->ray->py * cos(config->ray->rotentionspeed);
    }
   	main_draw_map(config);
		drawpl(config);
	mlx_put_image_to_window(config->mlx, config->mlx_win_3d,
							config->mlx_img, 0, 0);
	mlx_destroy_image(config->mlx, config->mlx_img);
  config->mlx_img = NULL;
  config->addr = NULL;
	return (1);
}

void			my_put_px(t_struct *config, int x, int y, int color)
{
	char	*dst;

	dst = config->addr + (y * config->line_length +
		x * (config->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void      ft_init(t_raycast *raycast, t_struct *config)
{
  config->fl_w = 0;
  config->fl_s = 0;
  config->fl_a = 0;
  config->fl_d = 0;
  config->fl_e = 0;
  config->fl_q = 0;
  raycast->frame = 20;
  raycast->dframe = 0;
  if (config->v_pl == 'W')
  {
    raycast->vx = -1;
    raycast->vy = 0;
    raycast->px = 0;
    raycast->py = 0.66;
  }
  if (config->v_pl == 'E')
  {
    raycast->vx = -1;
    raycast->vy = 0;
    raycast->px = 0;
    raycast->py = 0.66;
  }
  if (config->v_pl == 'S')
  {
    raycast->vx = -1;
    raycast->vy = 0;
    raycast->px = 0;
    raycast->py = 0.66;
  }
  if (config->v_pl == 'N')
  {
    raycast->vx = -1;
    raycast->vy = 0;
    raycast->px = 0;
    raycast->py = 0.66;
  }
  config->f_color = create_trgb(0, config->floor_color[0],
                                config->floor_color[1], config->floor_color[2]);
  config->c_color = create_trgb(0, config->ceilling_color[0],
                                config->ceilling_color[1], config->ceilling_color[2]);
  config->tex_ea = mlx_xpm_file_to_image(config->mlx, config->ea_texture, &config->r_width, &config->r_height);
  
}

int				ft_mlx(t_struct *config)
{
	config->mlx = mlx_init();
	config->mlx_win_3d = mlx_new_window(config->mlx, config->r_width,
											config->r_height, "Cub3D");
	mlx_hook(config->mlx_win_3d, 2, 0, &press_key, config);
	mlx_hook(config->mlx_win_3d, 3, 0, &anpress_key, config);
	mlx_hook(config->mlx_win_3d, 17, 0, &close_win, config);
  ft_init(config->ray, config);
	mlx_loop_hook(config->mlx, ft_loop_hook, config);
	mlx_loop(config->mlx);
	return (1);
}
