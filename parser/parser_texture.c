/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:06:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/28 18:50:08 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int		parser_texture_no(char *line, t_struct *config)
{
	line += 2;
	while (*line == ' ')
		line++;
	if (*line == '.')
		config->no_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("не валидна NO тектура\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}

int		parser_texture_so(char *line, t_struct *config)
{
	line += 2;
	while (*line == ' ')
		line++;
	if (*line == '.')
		config->so_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("не валидна SO тектура\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}

int		parser_texture_we(char *line, t_struct *config)
{
	line += 2;
	while (*line == ' ')
		line++;
	if (*line == '.')
		config->we_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("не валидна WE тектура\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}

int		parser_texture_ea(char *line, t_struct *config)
{
	line += 2;
	while (*line == ' ')
		line++;
	if (*line == '.')
		config->ea_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("не валидна EA тектура\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}

int		parser_texture_s(char *line, t_struct *config)
{
	line++;
	while (*line == ' ')
		line++;
	if (*line == '.')
		config->s_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("не валидна S тектура\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}
