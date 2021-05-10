/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:06:17 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/10 21:10:43 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void		map_pars(t_struct *config, char *line, char **map, int longer_line)
{
	config->b = 0;
	if (ft_strlen(line) > 0 && !config->trig && ++config->trig)
	{
		while (longer_line + 1 > config->b++)
			if (!(*map = ft_strjoin(*map, " ")))
			{
				ft_putstr_fd("Error\nMalloc error\n", 1);
				exit(1);
			}
		if (!(*map = ft_strjoin(*map, "\n")))
		{
			ft_putstr_fd("Error\nMalloc error\n", 1);
			exit(1);
		}
	}
	if (!ft_strlen(line) && config->trig)
	{
		ft_putstr_fd("Error\nMap have empty line\n", 1);
		exit(1);
	}
	if (!(*map = ft_strjoin(*map, line)))
	{
		ft_putstr_fd("Error\nMalloc error\n", 1);
		exit(1);
	}
}
