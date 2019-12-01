/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:18:31 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/01 21:27:15 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(const char *str, int i, t_list *stru)
{
	stru->prec_len = ft_atoi(str + i + 1);
	while (!ft_check_convers(str[i]) && !ft_isdigit(str[i]))
	{
		if (str[i] == '0')
			stru->fillzer = 1;
		if (str[i] == '-')
			stru->left = 1;
		if (str[i] == '.')
			stru->right = 1;
		if (str[i] == '*')
		{
			stru->right = 1;
			stru->par_len = 1;
		}
		i++;
	}
	if (stru->left)
		stru->fillzer = 0;
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	stru->i = i;
	return (i);
}
