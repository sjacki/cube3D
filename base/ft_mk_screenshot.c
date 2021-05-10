/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mk_screenshot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:54:42 by alexandr          #+#    #+#             */
/*   Updated: 2021/05/11 01:50:37 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cube3d.h"

void		write_header(t_struct *config, int fd, int *num)
{
	unsigned int	x;
	unsigned char	buf[54];

	*num = (4 - (config->r_width * 3) % 4) % 4;
	x = 54 + (*num + (config->r_width * 3)) * config->r_height;
	ft_memset(buf, (unsigned char)0, 54);
	buf[0] = 'B';
	buf[1] = 'M';
	buf[2] = (unsigned char)x;
	buf[3] = (unsigned char)(x >> 8);
	buf[4] = (unsigned char)(x >> 16);
	buf[5] = (unsigned char)(x >> 24);
	buf[10] = (unsigned char)54;
	buf[14] = (unsigned char)40;
	buf[18] = (unsigned char)(config->r_width);
	buf[19] = (unsigned char)(config->r_width >> 8);
	buf[20] = (unsigned char)(config->r_width >> 16);
	buf[21] = (unsigned char)(config->r_width >> 24);
	buf[22] = (unsigned char)(config->r_height);
	buf[23] = (unsigned char)(config->r_height >> 8);
	buf[24] = (unsigned char)(config->r_height >> 16);
	buf[25] = (unsigned char)(config->r_height >> 24);
	buf[26] = (unsigned char)1;
	buf[28] = (unsigned char)24;
	write(fd, buf, 54);
}

void		ft_mk_screenshot(t_struct *config)
{
	int				fd;
	int				x;
	int				num;
	unsigned char	buf[3];

	buf[0] = (unsigned char)0;
	buf[1] = (unsigned char)0;
	buf[2] = (unsigned char)0;
	fd = open("screenshot/screen.bmp", O_RDWR | O_CREAT, S_IRWXU, S_IRWXG);
	write_header(config, fd, &num);
	while (--config->r_height >= 0)
	{
		x = -1;
		while (++x < config->r_width)
			write(fd, &((int*)config->addr)[config->r_height *\
					config->r_width + x], 3);
		write(fd, buf, num);
	}
	close(fd);
	exit(0);
}
