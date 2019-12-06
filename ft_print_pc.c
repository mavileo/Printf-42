/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 07:01:09 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_prec_pc(t_list *list, int use, char space)
{
	if (use == 1)
	{
		while (list->width > list->prec_len + 1)
		{
			ft_putchar(space, 0);
			list->width--;
		}
	}
	if (use == 2)
	{
		while (list->prec_len - 1 > 0)
		{
			ft_putchar('0', 0);
			list->prec_len--;
		}
	}
}

void	ft_left_pc(t_list *list, char c, char space)
{
	if (list->prec && !list->prec_len && !c && list->width)
	{
		while (list->width--)
			ft_putchar(space, 0);
		return ;
	}
	ft_putchar(c, 0);
	if (list->width > list->prec_len)
		ft_width_prec_pc(list, 1, space);
}

void	ft_right_pc(t_list *list, char c, char space)
{
	if (list->prec && !list->prec_len && !c && list->width)
	{
		while (list->width--)
			ft_putchar(space, 0);
		return ;
	}
	if (list->width > list->prec_len)
		ft_width_prec_pc(list, 1, space);
	ft_putchar(c, 0);
}

void	ft_print_pc(char c, t_list *list)
{
	char space;

	if (list->width < 0)
	{
		list->left = 1;
		list->width = -list->width;
	}
	if (list->fillzer && !list->prec)
		space = '0';
	else
		space = ' ';
	if (list->prec && !list->prec_len && !c && !list->width)
		return ;
	if (list->left)
		ft_left_pc(list, c, space);
	else
		ft_right_pc(list, c, space);
}
