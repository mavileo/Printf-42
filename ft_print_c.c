/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:32:23 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/03 21:58:12 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, t_list *list, int prec_len)
{
	char space;

	if (list->fillzer && !list->left && !list->star_point)
		space = '0';
	else
		space = ' ';
	if (!prec_len)
		prec_len = list->prec_len;
	if (list->left)
	{
		ft_putchar(c, 0);
		while (--prec_len)
			ft_putchar(space, 0);
	}
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
