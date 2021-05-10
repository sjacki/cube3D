/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_fun_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:44:27 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 20:45:22 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			pos_sprt(t_struct *config)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	if (config->sprite->sprt_len)
	{
		while (x < ft_arrlen(config->map))
		{
			while (y < (int)ft_strlen(*config->map))
			{
				if (config->map[x][y] == '2')
				{
					config->sort[i].x = x + 0.5;
					config->sort[i].y = y + 0.5;
					i++;
				}
				y++;
			}
			y = 0;
			x++;
		}
	}
}

void			ft_init_move_var(t_struct *config, t_raycast *raycast)
{
	config->fl_w = 0;
	config->fl_s = 0;
	config->fl_a = 0;
	config->fl_d = 0;
	config->fl_e = 0;
	config->fl_q = 0;
	raycast->frame = 20;
	raycast->dframe = 0;
	raycast->x = 1;
}

void			ft_dir_pl_1(t_struct *config, t_raycast *raycast)
{
	if (config->v_pl == 'S')
	{
		raycast->vx = 1;
		raycast->vy = 0;
		raycast->px = 0;
		raycast->py = 0.66;
	}
	if (config->v_pl == 'E')
	{
		raycast->vx = 0;
		raycast->vy = 1;
		raycast->px = 0.66;
		raycast->py = 0;
	}
}

void			ft_dir_pl_2(t_struct *config, t_raycast *raycast)
{
	if (config->v_pl == 'N')
	{
		raycast->vx = -1;
		raycast->vy = 0;
		raycast->px = 0;
		raycast->py = 0.66;
	}
	if (config->v_pl == 'W')
	{
		raycast->vx = 0;
		raycast->vy = -1;
		raycast->px = 0.66;
		raycast->py = 0;
	}
}

void			ft_init_tex_1(t_struct *config)
{
	config->tex_ea->tex = mlx_xpm_file_to_image(config->mlx, config->ea_texture,
												&config->tex_ea->width,
												&config->tex_ea->height);
	config->tex_ea->adr = mlx_get_data_addr(config->tex_ea->tex,
											&config->tex_ea->bpp,
											&config->tex_ea->line_len,
											&config->tex_ea->iend);
	config->tex_no->tex = mlx_xpm_file_to_image(config->mlx, config->no_texture,
												&config->tex_no->width,
												&config->tex_no->height);
	config->tex_no->adr = mlx_get_data_addr(config->tex_no->tex,
											&config->tex_no->bpp,
											&config->tex_no->line_len,
											&config->tex_no->iend);
	config->tex_so->tex = mlx_xpm_file_to_image(config->mlx, config->so_texture,
												&config->tex_so->width,
												&config->tex_so->height);
	config->tex_so->adr = mlx_get_data_addr(config->tex_so->tex,
											&config->tex_so->bpp,
											&config->tex_so->line_len,
											&config->tex_so->iend);
}
