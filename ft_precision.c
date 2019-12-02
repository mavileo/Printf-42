/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:18:31 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/02 01:09:47 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_point(t_list *stru)
{
	stru->right = 1;
	stru->point = 1;
	stru->left = 0;
	if (stru->par_len)
		stru->star_point = 1;
}

int		ft_precision(const char *str, int i, t_list *stru)
{
	stru->prec_len = ft_atoi(str + i + 1);
	while (!ft_check_convers(str[i]) && !(str[i] > 48 && str[i] < 58))
	{
		if (str[i] == '0')
			stru->fillzer = 1;
		if (str[i] == '-')
			stru->fillzer = 0;
		if (str[i] == '-')
			stru->left = 1;
		if (str[i] == '.')
			ft_point(stru);
		if (str[i] == '*')
			stru->right = 1;
		if (str[i] == '*')
			stru->par_len = 1;
		}
		i++;
	}
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	stru->i = i;
	return (i);
}
