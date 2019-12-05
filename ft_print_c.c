/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:32:23 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 06:55:29 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left(char c, int prec_len, char space)
{
	ft_putchar(c, 0);
	while (--prec_len)
		ft_putchar(space, 0);
}

void	ft_print_c(char c, t_list *list, int prec_len)
{
	char space;

	if (prec_len < 0)
	{
		list->left = 1;
		prec_len = -prec_len;
	}
	if (list->fillzer && !list->left && !list->star_point)
		space = '0';
	else
		space = ' ';
	if (!prec_len)
		prec_len = list->prec_len;
	if (list->left)
		ft_left(c, prec_len, space);
	else if ((list->right && !list->point && !(list->fillzer && list->point))
	|| list->only_zer || list->star_point)
	{
		while (--prec_len && !list->point_star)
			ft_putchar(space, 0);
		ft_putchar(c, 0);
	}
	else
		ft_putchar(c, 0);
}
