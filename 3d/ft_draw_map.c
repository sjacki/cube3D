/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:51:48 by sjacki            #+#    #+#             */
/*   Updated: 2021/02/16 08:01:49 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static void			pl_conf(t_struct *config, int x, int y, int size)
{
	config->x_pl = (x * size) + (size / 2);
	config->y_pl = (y * size) + (size / 2) + size;
	config->v_pl = config->map[x][y];
	base_ray_dir(config);
	config->fl_find_pl++;
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
			if (ft_strrchr("WSNE", config->map[x][y]) &&
			(config->square_color = 0xFFDAB9) && !config->fl_find_pl)
				pl_conf(config, x, y, size);
			if (config->map[x][y] == ' ')
				config->square_color = 0x000000;
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
	draw_map(config, size);
}
