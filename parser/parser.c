/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:00:25 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/28 00:25:06 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

static int      parser_conf(char *line, t_struct *config)
{
    while (*line == ' ')
        line++;
    if (*line == 'R')
    {
        line++;
        while (*line == ' ')
            line++;
        if (ft_isdigit(*line))
            config->R_WIDTH = ft_atoi(line);
        else
            return (0);
        while (ft_isdigit(*line))
            line++;
        while (*line == ' ')
            line++;
        if (ft_isdigit(*line))
            config->R_HEIGHT = ft_atoi(line);
        else
            return (0);
        while (ft_isdigit(*line))
            line++;
         while (*line == ' ')
            line++;
        if (*line == '\0')
            return (1);
        else
            return (0);
    }
    return (1);
}

int             parser(int fd)
{
    char        *line;
    t_struct    config;

    while (get_next_line(fd, &line))
    {
        if(!(parser_conf(line, &config)))
        {
           free (line);
           return (0);
        }
    }
    ft_printf("width: %d\nheight: %d\n", config.R_WIDTH, config.R_HEIGHT);
    return (1);
}