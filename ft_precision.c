/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:18:31 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 04:35:18 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags_width(const char *str, int i, t_list *list, char *convers)
{
	while (str[i] && !ft_check_convers(str[i], convers) && str[i] != '.')
	{
		if (str[i] == '0')
			list->fillzer = 1;
		if (str[i] == '-')
			list->left = 1;
		if (str[i] == '*')
			list->par_width = 1;
		i++;
	}
	return (i);
}

int		ft_prec(const char *str, int i, t_list *list)
{
	if (str[i] == '.')
	{
		list->prec = 1;
		i++;
	}
	if (str[i] == '*')
		list->par_prec = 1;
	else
		list->prec_len = ft_atoi(str + i);
	return (i);
}

int		ft_width_precision(const char *str, int i, t_list *list)
{
	char *convers;

	convers = ft_strdup("cspdiuxX%");
	list->width = ft_atoi(str + i);
	i = ft_flags_width(str, i, list, convers);
	i = ft_prec(str, i, list);
	if (list->left)
		list->fillzer = 0;
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	free(convers);
	return (i);
}
