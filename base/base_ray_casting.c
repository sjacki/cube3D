/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:17:35 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/08 13:58:57 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int			ray_casting(t_struct *config)
{
	int x = 0;
	int y = 0;
	void	*mlx;
	void	*mlx_win;
	(void)config;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, config->r_width, config->r_height, "Cub3D");
	while (config->map[x])
	{
		y = 0;
		while (config->map[x][y])
		{
			if (config->map[x][y] == '1')
				mlx_pixel_put(mlx, mlx_win, y + 100, x + 100, 0xFF0000);
			if (config->map[x][y] == '0')
				mlx_pixel_put(mlx, mlx_win, y + 100, x + 100, 0xFFFFFF);
			y++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (1);
}