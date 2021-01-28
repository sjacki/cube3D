/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:25:50 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/28 17:17:03 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/header/libft.h"
# include <fcntl.h>

typedef struct  s_struct
{
    int      r_width;
    int         r_height;
    char        *no;
    char        *so;
    char        *we;
    char        *ea;
    char        *s;
    int         f[2];
    int         c[2];
}				t_struct;
int             parser(int fd);
#endif
