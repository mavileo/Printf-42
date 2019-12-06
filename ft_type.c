/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 21:55:58 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 03:50:19 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type(const char *str, int i, t_list *stru)
{
	char *convers;

	convers = ft_strdup("cspdiuxX%");
	while (str[i] && !ft_check_convers(str[i], convers))
		i++;
	stru->type = str[i];
	free(convers);
	return (i);
}
