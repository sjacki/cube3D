/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:26:22 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/30 19:28:09 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_arrlen(char **arr)
{
	int		len;

	len = 0;
	if (!arr)
		return (-1);
	while (arr[len])
		len++;
	return (len);
}
