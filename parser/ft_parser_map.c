/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:29:29 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/30 14:51:18 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int			parser_map(t_struct *config)
{
	char		*line;
	int			err_gnl;
	int			fd;
	size_t		x;

	x = 0;
	fd = open(config->argv1, O_RDONLY);
	while ((err_gnl = get_next_line(fd, &line)))
	{
		if (config->conf_count < x)
			ft_printf("%s\n", line);
		free(line);
		x++;
	}
	if (config->conf_count <= x)
		ft_printf("%s\n", line);
	free(line);
	return (1);
}
