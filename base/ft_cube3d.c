/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:22:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/12 01:32:33 by alexandr         ###   ########.fr       */
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
	config->fl_screen = 0;
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

void			main_1(t_struct *config, int argc, char **argv)
{
	int		fd;

	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))
			config->fl_screen = 1;
		else
		{
			ft_putstr_fd("Error\nNot valid second argument\n", 1);
			exit(1);
		}
	}
	if ((fd = open(config->argv1, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error\nСould not open configuration\n", 1);
		exit(1);
	}
	parser(fd, config);
	ft_mlx(config);
}

void			cub_check(char **argv)
{
	int x;

	x = 0;
	while (argv[1][x] != '.')
		x++;
	if (ft_strncmp(argv[1] + x, ".cub", ft_strlen(argv[1]) - x))
	{
		ft_putstr_fd("Error\nNot valid conf. file\n", 1);
		exit(1);
	}
}

int				main(int argc, char **argv)
{
	t_struct	config;
	t_raycast	raycast;
	t_sprite	sprite;

	config.ray = &raycast;
	config.sprite = &sprite;
	config.argv1 = argv[1];
	null_struct(&config);
	if (argc == 2 || argc == 3)
	{
		cub_check(argv);
		main_1(&config, argc, argv);
	}
	else
	{
		ft_putstr_fd("Error\nNot valid count config\n", 1);
		exit(1);
	}
	free_struct(&config);
	return (0);
}
