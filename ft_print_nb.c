/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 05:43:35 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_nb(int nb)
{
	int len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_left_nb(int nb, t_list *list, int prec_len)
{
	int		len_nb;
	char	c;

	len_nb = ft_len_nb(nb);
	if (nb == 0)
		len_nb = 1;
	if ((list->fillzer || list->point) && !list->left && !list->star_point)
		c = '0';
	else
		c = ' ';
	ft_putnbr(nb);
	while (prec_len-- - len_nb > 0)
		ft_putchar(c, 0);
}

void	ft_right_nb(int nb, t_list *list, int prec_len)
{
	int		len_nb;
	char	c;

	len_nb = ft_len_nb(nb);
	if (nb == 0 && !(list->fillzer && list->point && list->par_len))
		len_nb = 1;
	if ((list->fillzer || list->point) && !list->left && !list->star_point)
		c = '0';
	else
		c = ' ';
	while (prec_len-- - len_nb > 0)
		ft_putchar(c, 0);
	if (list->fillzer && list->point && list->par_len)
		return ;
	ft_putnbr(nb);
}

void	ft_print_nb(int nb, t_list *list, int prec_len)
{
	if (prec_len < 0)
	{
		prec_len = -prec_len;
		list->left = 1;
	}
	if (!prec_len)
		prec_len = list->prec_len;
	if (list->point_star && nb < 0)
	{
		ft_putchar('-', 0);
		nb = -nb;
	}
	if (list->left)
		ft_left_nb(nb, list, prec_len);
	else if (list->right)
		ft_right_nb(nb, list, prec_len);
	else
		ft_putnbr(nb);
}
