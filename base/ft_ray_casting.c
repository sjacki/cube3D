/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:17:35 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/12 00:37:56 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int				ft_loop_hook(t_struct *config)
{
	init_img(config);
	while (config->ray->x < config->r_width)
	{
		init_var(config);
		ray_1(config);
		ray_2(config);
		ray_3(config);
		ray_4(config);
		draw_texture(config);
	}
	spr(config);
	init_time(config);
	move_ch(config);
	main_draw_map(config);
	drawpl(config);
	end_ray(config);
	return (1);
}

void			ft_init_tex_2(t_struct *config)
{
	config->tex_we->tex = mlx_xpm_file_to_image(config->mlx, config->we_texture,
												&config->tex_we->width,
												&config->tex_we->height);
	config->tex_we->adr = mlx_get_data_addr(config->tex_we->tex,
											&config->tex_we->bpp,
											&config->tex_we->line_len,
											&config->tex_we->iend);
	config->sprite->tex = mlx_xpm_file_to_image(config->mlx, config->s_texture,
												&config->sprite->width,
												&config->sprite->height);
	config->sprite->adr = mlx_get_data_addr(config->sprite->tex,
											&config->sprite->bpp,
											&config->sprite->line_len,
											&config->sprite->iend);
	config->f_color = create_trgb(0, config->floor_color[0],
						config->floor_color[1], config->floor_color[2]);
	config->c_color = create_trgb(0, config->ceilling_color[0],
					config->ceilling_color[1], config->ceilling_color[2]);
}

void			ft_init(t_raycast *raycast, t_struct *config)
{
	count_spr(config);
	pos_sprt(config);
	if (!(config->sprite->x_buf = (int*)malloc(config->r_width * 4)))
	{
		ft_putstr_fd("malloc error\n", 1);
		exit(1);
	}
	ft_init_move_var(config, raycast);
	ft_dir_pl_1(config, raycast);
	ft_dir_pl_2(config, raycast);
	ft_init_tex_1(config);
	ft_init_tex_2(config);
	ft_not_valid_tex(config);
}

int				ft_mlx(t_struct *config)
{
	t_texture	tex_ea;
	t_texture	tex_we;
	t_texture	tex_so;
	t_texture	tex_no;
	t_sort		*sort;

	sort = NULL;
	config->sort = sort;
	config->mlx = mlx_init();
	ft_resolution_screen(config);
	ft_init_mlx(config);
	config->tex_ea = &tex_ea;
	config->tex_we = &tex_we;
	config->tex_so = &tex_so;
	config->tex_no = &tex_no;
	ft_init(config->ray, config);
	mlx_loop_hook(config->mlx, ft_loop_hook, config);
	mlx_loop(config->mlx);
	return (1);
}
