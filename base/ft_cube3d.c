/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:22:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/29 20:18:56 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static void		free_struct(t_struct *config)
{
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

int				main(int argc, char **argv)
{
	int			fd;
	t_struct	config;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
		{
			ft_putstr_fd("Не удалось открыть конфиг\n", 1);
			return (-1);
		}
		if (!parser(fd, &config))
			return (-1);
	}
	else
	{
		ft_putstr_fd("неверное количесто аргументов\n", 1);
		return (-1);
	}
	free_struct(&config);
	return (0);
}
