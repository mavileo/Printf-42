/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:32:23 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/02 20:15:41 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, t_list *list, int prec_len, int res_len)
{
	char space;

	if (list->fillzer && !list->left && !list->star_point)
		space = '0';
	else
		space = ' ';
	if (!prec_len)
		prec_len = list->prec_len;
	res_len = res_len + prec_len + 1;
	if (list->left)
	{
		ft_putchar(c);
		while (--prec_len)
			ft_putchar(space);
	}
	else if ((list->right && !list->point && !(list->fillzer && list->point))
	|| list->only_zer || list->star_point)
	{
		while (--prec_len && !list->point_star)
			ft_putchar(space);
		ft_putchar(c);
	}
	else
		ft_putchar(c);
}
