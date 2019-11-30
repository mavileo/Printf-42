/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:35 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/30 21:34:01 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	int				prec;
	int				len;
	int				fillzer;
	int				left;
	char			*s;
	void			*p;
	int				i;
	char			type;
	struct s_list	*next;
}				t_list;

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		ft_isprint(int c);
int		ft_atoi(const char *nb);
int		ft_isdigit(int c);
t_list	*ft_lstnew(void);

#endif