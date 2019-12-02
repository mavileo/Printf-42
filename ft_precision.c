/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:18:31 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/02 22:11:18 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_point(t_list *list)
{
	list->right = 1;
	list->point = 1;
	list->left = 0;
	if (list->par_len)
		list->star_point = 1;
}

void	ft_star(t_list *list)
{
	list->right = 1;
	list->par_len = 1;
	if (list->point && list->fillzer)
		list->star_point = 1;
	if (list->point)
		list->point_star = 1;
}

void	ft_dash(t_list *list)
{
	list->fillzer = 0;
	list->left = 1;
}

void	ft_zer(t_list *list)
{
	list->fillzer = 1;
	if (!list->point && !list->left && !list->right && !list->point)
		list->only_zer = 1;
}

int		ft_precision(const char *str, int i, t_list *list)
{
	list->prec_len = ft_atoi(str + i + 1);
	while (!ft_check_convers(str[i]) && !(str[i] > 48 && str[i] < 58))
	{
		if (str[i] == '0')
			ft_zer(list);
		if (str[i] == '-')
			ft_dash(list);
		if (str[i] == '.')
			ft_point(list);
		if (str[i] == '*')
			ft_star(list);
		i++;
	}
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	list->i = i;
	return (i);
}
