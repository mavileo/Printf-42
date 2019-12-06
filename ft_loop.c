/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:37:12 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 02:29:58 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_loop(const char *str, t_list *tmp, va_list va_lst)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i)
			tmp = tmp->next;
		while (str[i] && str[i] != '%')
			ft_putchar(str[i++], 0);
		if (str[i] == '%')
		{
			i++;
			i = ft_width_precision(str, i, tmp);
			i = ft_type(str, i, tmp);
			ft_which_type(tmp, va_lst);
			i++;
		}
	}
}
