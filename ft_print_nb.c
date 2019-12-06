/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 04:57:12 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_nb(long nb)
{
	int len;

	len = 0;
	if (nb < 0)
		len++;
	if (nb == 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_width_prec_nb(long nb, t_list *list, char c, int use)
{
	if (use == 1)
	{
		while (list->width > list->prec_len + ft_len_nb(nb))
		{
			ft_putchar(c, 0);
			list->width--;
		}
	}
	if (use == 2)
	{
		while (list->prec_len - ft_len_nb(nb) > 0)
		{
			ft_putchar('0', 0);
			list->prec_len--;
		}
	}
}

void	ft_left_nb(long nb, t_list *list, char c)
{
	if (list->prec && !list->prec_len && !nb && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	if (list->prec)
		ft_width_prec_nb(nb, list, c, 2);
	ft_putnbr(nb);
	if (list->width >= list->prec_len + ft_len_nb(nb))
		ft_width_prec_nb(nb, list, c, 1);
}

void	ft_right_nb(long nb, t_list *list, char c)
{
	if (list->prec && !list->prec_len && !nb && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	if (list->width >= list->prec_len + ft_len_nb(nb))
		ft_width_prec_nb(nb, list, c, 1);
	if (list->prec)
		ft_width_prec_nb(nb, list, c, 2);
	ft_putnbr(nb);
}

void	ft_print_nb(long nb, t_list *list)
{
	char c;

	if (list->width < 0)
	{
		list->left = 1;
		list->width = -list->width;
	}
	if (list->fillzer && !list->prec)
		c = '0';
	else
		c = ' ';
	if (list->prec && !list->prec_len && !nb && !list->width)
		return ;
	if (nb < 0 && (list->fillzer || (list->prec && list->prec_len)))
	{
		ft_putchar('-', 0);
		list->width--;
		nb = -nb;
	}
	if (list->left)
		ft_left_nb(nb, list, c);
	else
		ft_right_nb(nb, list, c);
}
