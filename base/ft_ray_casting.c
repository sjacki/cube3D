/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:17:35 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/16 08:01:39 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int				close_win(t_struct *config)
{
	mlx_destroy_window(config->mlx, config->mlx_win_3d);
	exit(0);
	return (0);
}

int				ft_loop_hook(t_struct *config)
{
	config->mlx_img = mlx_new_image(config->mlx, config->r_width,
										config->r_height);
	config->addr = mlx_get_data_addr(config->mlx_img, &config->bits_per_pixel,
									&config->line_length, &config->endian);
	main_draw_map(config);
	contr_pl(config);
	mlx_put_image_to_window(config->mlx, config->mlx_win_3d,
							config->mlx_img, 0, 0);
	mlx_destroy_image(config->mlx, config->mlx_img);
	return (1);
}

void			my_put_px(t_struct *config, int x, int y, int color)
{
	char	*dst;

	dst = config->addr + (y * config->line_length +
		x * (config->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int				my_get_px(t_struct *config, int x, int y)
{
	char	*dst;

	dst = config->addr + (y * config->line_length +
		x * (config->bits_per_pixel / 8));
	return (*dst);
}

int				ray_casting(t_struct *config)
{
	config->mlx = mlx_init();
	config->mlx_win_3d = mlx_new_window(config->mlx, config->r_width,
											config->r_height, "Cub3D");
	mlx_hook(config->mlx_win_3d, 02, 0L, press_key, config);
	mlx_hook(config->mlx_win_3d, 03, 0L, anpress_key, config);
	mlx_hook(config->mlx_win_3d, 17, 0L, close_win, config);
	mlx_loop_hook(config->mlx, ft_loop_hook, config);
	mlx_loop(config->mlx);
	return (1);
}
