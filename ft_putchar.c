/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:36:48 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 05:32:59 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c, int end)
{
	static int	res = 0;
	int			ret;

	ret = 0;
	if (end == 1)
	{
		ret = res;
		res = 0;
		return (ret);
	}
	write(1, &c, 1);
	res++;
	return (res);
}
