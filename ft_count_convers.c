/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_convers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:56:26 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/01 21:56:28 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_convers(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == '%')
			count++;
	return (count);
}
