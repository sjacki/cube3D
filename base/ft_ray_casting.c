/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:17:35 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/13 22:15:03 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void			draw_square(int x, int y, int size, t_mlx *mlx_struct)
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
			mlx_pixel_put(mlx_struct->mlx, mlx_struct->mlx_win_2d,
							x, y, mlx_struct->square_color);
			y++;
			xd--;
		}
		x++;
		yd--;
	}
}

void			resol_map(t_struct *config, t_mlx *mlx_struct)
{
	int size;
	int x;
	int y;

	x = 1;
	y = 0;
	size = ((config->r_height / 2) / (ft_arrlen(config->map)));
	if (((config->r_width / 2) / (ft_strlen(*config->map))) <
		(size_t)((config->r_height / 2) / (ft_arrlen(config->map))))
	{
		size = (((config->r_width / 2) / (ft_strlen(*config->map))));
	}
	while (config->map[x])
	{
		y = 0;
		while (config->map[x][y])
		{
			if (config->map[x][y] == ' ')
				mlx_struct->square_color = 0x000000;
			if (config->map[x][y] == '0')
				mlx_struct->square_color = 0xFFDAB9;
			if (config->map[x][y] == '1')
				mlx_struct->square_color = 0xB22222;
			if (config->map[x][y] == '2')
				mlx_struct->square_color = 0x00FFFF;
			if (ft_strrchr("WSNE", config->map[x][y]))
				mlx_struct->square_color = 0x32CD32;
			draw_square((y + 1) * size, x * size, size, mlx_struct);
			y++;
		}
		x++;
	}
	for(int i = 0; i < ft_arrlen(config->map); i++)
		ft_printf("%s\n", config->map[i]);
}

int			ray_casting(t_struct *config)
{
	t_mlx mlx_struct;
	
	mlx_struct.mlx = mlx_init();
	mlx_struct.mlx_win_3d = mlx_new_window(mlx_struct.mlx, config->r_width,
											config->r_height, "Cub3D");
	mlx_struct.mlx_win_2d = mlx_new_window(mlx_struct.mlx, config->r_width / 2,
											config->r_height / 2, "Cub2D");
	resol_map(config, &mlx_struct);
	mlx_loop(mlx_struct.mlx);
	return (1);
}
