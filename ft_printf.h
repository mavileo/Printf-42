/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:35 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/29 16:41:13 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef struct	s_struct
{
	int		prec;
	int		len;
	int		fillzer;
	int		left;
	char	*s;
	void	*p;
	int		i;
	char	type;
	t_struct *next;
}				t_struct;

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_isprint(int c);
int		ft_atoi(const char *nb);
int		ft_isdigit(int c);

#endif