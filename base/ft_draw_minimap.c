/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:42:51 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 19:48:14 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

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
	size /= 4;
	config->px_size = size;
	draw_map(config, size);
}

void				drawpl(t_struct *config)
{
	config->square_color = 0x000000;
	draw_square((config->y_pl * config->px_size) + (config->px_size / 2),
				(config->x_pl * config->px_size)
				- (config->px_size / 2), config->px_size / 2, config);
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

int					create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
