/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:22:10 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/27 19:30:23 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

int main(int argc, char **argv)
{
    int     fd;

    if (argc == 2)
    {
        if ((fd = open(argv[1], O_RDONLY)) < 0)
        {   
            ft_putstr_fd("Не удалось считать сцену\n", 1);
            return (-1);
        }
        parser(fd);
    }
    else if (argc < 2)
        ft_putstr_fd("Не подана сцена\n", 1);
    else if (argc > 2)
        ft_putstr_fd("Подано больше одного аргумента\n", 1);
    return (0);
}