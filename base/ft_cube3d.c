/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:22:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/04 00:34:08 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static void		free_struct(t_struct *config)
{
	int x;

	x = 0;
	if (config->ea_texture)
		free(config->ea_texture);
	if (config->no_texture)
		free(config->no_texture);
	if (config->we_texture)
		free(config->we_texture);
	if (config->so_texture)
		free(config->so_texture);
	if (config->s_texture)
		free(config->s_texture);
}

static void		null_struct(t_struct *config)
{
	config->conf_count = 0;
	config->map_trigger = 0;
	config->trig = 0;
	config->r_height = 0;
	config->r_width = 0;
	config->flag_floor = 0;
	config->flag_ceilling = 0;
	config->mp5 = 0;
	config->fl_w = 0;
	config->ea_texture = NULL;
	config->no_texture = NULL;
	config->we_texture = NULL;
	config->so_texture = NULL;
	config->s_texture = NULL;
	config->fl_find_pl = 0;
	config->speed = 0.5;
	config->hud_scale = 4;
}

int				main(int argc, char **argv)
{
	int			fd;
	t_struct	config;
  	t_raycast raycast;
	config.ray = &raycast;

	config.argv1 = argv[1];
	null_struct(&config);
	if (argc == 2)
	{
		if ((fd = open(config.argv1, O_RDONLY)) < 0)
		{
			ft_putstr_fd("Error\nСould not open configuration\n", 1);
			exit(1);
		}
		parser(fd, &config);
		ft_mlx(&config);
	}
	else
	{
		ft_putstr_fd("Error\nNot valid count config\n", 1);
		exit(1);
	}
	free_struct(&config);
	return (0);
}
