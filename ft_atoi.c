/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 23:02:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 03:16:54 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *nb)
{
	int count;
	int res;

	count = 0;
	res = 0;
	while (nb[count] && ((nb[count] >= 8 && nb[count] <= 13) ||
	nb[count] == ' ' || nb[count] == '-' || nb[count] == '0' ||
	nb[count] == '+'))
		count++;
	while (nb[count] && nb[count] >= '0' && nb[count] <= '9')
	{
		res = res * 10 + nb[count] - 48;
		count++;
	}
	return (res);
}
