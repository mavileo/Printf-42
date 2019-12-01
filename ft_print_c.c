/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:32:23 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/01 21:55:19 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, t_list *list, int prec_len, int res_len)
{
	if (!prec_len)
		prec_len = list->prec_len;
	res_len = res_len + prec_len + 1;
	if (list->left)
	{
		ft_putchar(c);
		while (--prec_len)
			ft_putchar(' ');
	}
	else if (list->right)
	{
		while (--prec_len)
			ft_putchar(' ');
		ft_putchar(c);
	}
	else
		ft_putchar(c);
}
