/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 21:38:54 by mavileo          ###   ########.fr       */
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

void	ft_width_prec_nb(long nb, t_list *list, int use)
{
	char	c;
	int		len;

	len = ft_len_nb(nb);
	if (list->prec_len > ft_len_nb(nb) && list->prec)
		len = list->prec_len;
	c = ' ';
	if (list->fillzer && !list->prec)
		c = '0';
	if (use == 1)
		while (list->width-- > len)
			ft_putchar(c, 0);
	if (use == 2)
	{
		len = list->prec_len;
		while (len-- - ft_len_nb(nb) > 0)
			ft_putchar('0', 0);
	}
}

void	ft_left_nb(long nb, t_list *list, char c)
{
	list->fillzer = 0;
	if (list->prec && !list->prec_len && !nb && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	else
	{
		if (list->prec)
			ft_width_prec_nb(nb, list, 2);
		ft_putnbr(nb);
		ft_width_prec_nb(nb, list, 1);
	}
}

void	ft_right_nb(long nb, t_list *list, char c)
{
	if (list->prec && !list->prec_len && !nb && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	else
	{
		ft_width_prec_nb(nb, list, 1);
		if (list->prec)
			ft_width_prec_nb(nb, list, 2);
		ft_putnbr(nb);
	}
}

void	ft_print_nb(long nb, t_list *list)
{
	char c;

	c = ' ';
	if (list->fillzer && !list->prec)
		c = '0';
	if (list->width < 0)
	{
		list->left = 1;
		list->width = -list->width;
	}
	if (list->prec && !list->prec_len && !nb && !list->width)
		return ;
	if (nb < 0 && ((list->fillzer && !list->prec) || ((list->prec &&
	list->prec_len >= ft_len_nb(nb)))))
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
