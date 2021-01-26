/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacki <sjacki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:27:23 by sjacki            #+#    #+#             */
/*   Updated: 2021/01/20 06:01:35 by sjacki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "string.h"
# include "unistd.h"
# include <stdarg.h>

typedef struct	s_struct
{
	char	type;
	int		minus;
	int		zero;
	int		width;
	int		point;
	int		pre;
	int		len;
	int		star;
	int		p;
	int		pmin;
	int		widmin;
}				t_struct;

int				ft_printf(const char *str, ...);
int				ft_parcer(const char **format, t_struct *flag, va_list ap);
int				ft_processor(t_struct *flag, va_list ap);
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
char			*ft_strchr(char *s, int c);
int				ft_atoi(const char *str);
int				ft_putnbr_fd(int n, int fd);
int				ft_len_int(int n);
char			*ft_itoa(int n);
int				ft_putstr_fd(char *s, int fd, t_struct *flag);
void			ft_processor_d_i(t_struct *flag, va_list ap);
void			putminus(t_struct *flag, int *buf);
void			putminus_u(t_struct *flag, unsigned int *buf);
void			ft_width_point(t_struct *flag);
void			ft_processor_u(t_struct *flag, va_list ap);
int				powerdex(int power);
int				ft_len_u(unsigned int n);
int				ft_putnbr_fd_u(unsigned int n, int fd);
void			ft_processor_c(t_struct *flag, va_list ap);
int				ft_putchar_fd(char c, int fd);
void			ft_processor_s(t_struct *flag, va_list ap);
void			ft_processer_percent(t_struct *flag);
void			ft_processor_x(t_struct *flag, va_list ap);
void			ft_putnbr_hex(t_struct *flag, unsigned int buf);
int				ft_len_hex(unsigned int buf);
void			ft_processor_p(t_struct *flag, va_list ap);
void			ft_putnbr_hex_p(t_struct *flag, unsigned long long buf);
int				ft_len_hex_p(unsigned long long buf, t_struct *flag);
void			chastch(t_struct *flag, char *buf);
#endif
