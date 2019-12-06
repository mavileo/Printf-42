/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_convers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:18:09 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 22:54:48 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_convers(char c, char *list)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (list[i])
		if (c == list[i++])
			res = 1;
	return (res);
}
