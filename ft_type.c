/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:55:58 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/01 21:56:00 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(const char *str, int i, t_list *stru)
{
	while (!ft_check_convers(str[i]))
		i++;
	stru->type = str[i];
	return (i);
}
