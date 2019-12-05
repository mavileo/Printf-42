/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 01:40:10 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	t_list		*list;
	t_list		*tmp;
	va_list		va_lst;

	va_start(va_lst, str);
	list = ft_newlist(ft_count_convers(str));
	tmp = list;
	ft_loop(str, tmp, va_lst);
	va_end(va_lst);
	return (ft_putchar(0, 1));
}
