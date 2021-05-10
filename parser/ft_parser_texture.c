/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:06:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/05/10 22:26:28 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int		parser_texture_no(char *line, t_struct *config)
{
	if (config->no_texture && ft_putstr_fd("Error\nNot valid NO tex\n", 1))
		return (0);
	line += 2;
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->no_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("not valid NO tex\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}

int		parser_texture_so(char *line, t_struct *config)
{
	if (config->so_texture && ft_putstr_fd("Error\nNot valid SO tex\n", 1))
		return (0);
	line += 2;
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->so_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("Error\nNot valid SO tex\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}

int		parser_texture_we(char *line, t_struct *config)
{
	if (config->we_texture && ft_putstr_fd("Error\nNot valid WE tex\n", 1))
		return (0);
	line += 2;
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->we_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("Error\nNot valid WE tex\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}

int		parser_texture_ea(char *line, t_struct *config)
{
	if (config->ea_texture && ft_putstr_fd("Error\nNot valid EA tex\n", 1))
		return (0);
	line += 2;
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->ea_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("Error\nNot valid EA tex\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}

int		parser_texture_s(char *line, t_struct *config)
{
	if (config->s_texture && ft_putstr_fd("Error\nNot valid S tex\n", 1))
		return (0);
	line++;
	while (*line == ' ' || *line == '	')
		line++;
	if (*line == '.')
		config->s_texture = ft_strdup(line);
	else
	{
		ft_putstr_fd("Error\nNot valid S tex\n", 1);
		return (0);
	}
	config->mp5++;
	return (1);
}
