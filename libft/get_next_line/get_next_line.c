/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student-21.school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:04:30 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/09 08:35:00 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		error_clean(char **rest, char **buf)
{
	if (*rest)
		free(*rest);
	if (*buf)
		free(*buf);
	return (-1);
}

int		rest_ch(char **rest, char **line, char **buf)
{
	char	*in_n;
	char	*tmp;

	if (*rest && (in_n = ft_strchr(*rest, '\n')))
	{
		*in_n = '\0';
		tmp = *rest;
		if (!(*line = ft_strdup(*rest)))
			return (error_clean(rest, buf));
		if (!(*rest = ft_strdup(++in_n)))
			return (error_clean(rest, buf));
		free(tmp);
		return (1);
	}
	else if (*rest)
	{
		if (!(*line = ft_strdup(*rest)))
			return (error_clean(rest, buf));
		free(*rest);
		*rest = NULL;
		return (0);
	}
	if (!(*line = ft_strdup("")))
		return (error_clean(rest, buf));
	return (0);
}

int		find_n(int *flag_rest, char **line, char **buf, char **rest)
{
	char	*in_n;

	if ((in_n = ft_strchr(*buf, '\n')))
	{
		*in_n = '\0';
		if (BUFFER_SIZE != 1)
			if (!(*rest = ft_strdup(++in_n)))
				return (error_clean(rest, buf));
		*flag_rest = 1;
	}
	if (!(*line = ft_strjoin(*line, *buf)))
		return (error_clean(rest, buf));
	return (0);
}

int		gnl_return(size_t read_bite, char **rest, int flag_rest, char **buf)
{
	if (read_bite || ft_strlen(*rest) || flag_rest)
	{
		free(*buf);
		return (1);
	}
	free(*buf);
	free(*rest);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rest;
	int			flag_rest;
	int			read_bite;

	if (!line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (read(fd, buf, 0) < 0 || (flag_rest = rest_ch(&rest, line, &buf)) == -1)
	{
		free(buf);
		return (-1);
	}
	read_bite = 0;
	while (!flag_rest && (read_bite = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_bite] = 0;
		if (find_n(&flag_rest, line, &buf, &rest) < 0)
			return (-1);
	}
	return (gnl_return(read_bite, &rest, flag_rest, &buf));
}
