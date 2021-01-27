/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 22:00:25 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/27 19:26:49 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int             parser(int fd)
{
    char    *line;

    while (get_next_line(fd, &line))
    {
        ft_printf ("%s\n", line);
        free (line);
    }
    ft_printf ("%s\n", line);
    free (line);
    return (1);
}