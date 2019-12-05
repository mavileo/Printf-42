/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 19:55:54 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 02:24:45 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int count;

	count = 0;
	if (str)
	{
		while (str[count])
			ft_putchar(str[count++], 0);
	}
}
