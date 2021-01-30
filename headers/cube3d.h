/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:25:50 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/29 19:46:12 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../libft/header/libft.h"
# include <fcntl.h>

typedef struct	s_struct
{
	int			r_width;
	int			r_height;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*s_texture;
	int			floor_color[3];
	int			ceilling_color[3];
	size_t		mp5;
}				t_struct;

int				parser(int fd, t_struct *config);
int				parser_texture_no(char *line, t_struct *config);
int				parser_texture_so(char *line, t_struct *config);
int				parser_texture_we(char *line, t_struct *config);
int				parser_texture_ea(char *line, t_struct *config);
int				parser_texture_s(char *line, t_struct *config);
#endif
