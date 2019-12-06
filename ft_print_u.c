/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 21:23:44 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_u(unsigned int nb)
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

void	ft_width_prec_u(unsigned int nb, t_list *list, char c, int use)
{
	int		len;

	len = ft_len_u(nb);
	if (list->prec_len > ft_len_u(nb) && list->prec)
		len = list->prec_len;
	if (use == 1)
		while (list->width-- > len)
			ft_putchar(c, 0);
	if (use == 2)
	{
		len = list->prec_len;
		while (len-- - ft_len_u(nb) > 0)
			ft_putchar('0', 0);
	}
}

void	ft_left_u(unsigned int nb, t_list *list, char c)
{
	if (list->prec && !list->prec_len && !nb && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	if (list->prec)
		ft_width_prec_u(nb, list, c, 2);
	ft_putunsign(nb);
	ft_width_prec_u(nb, list, c, 1);
}

void	ft_right_u(unsigned int nb, t_list *list, char c)
{
	if (list->prec && !list->prec_len && !nb && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	ft_width_prec_u(nb, list, c, 1);
	if (list->prec)
		ft_width_prec_u(nb, list, c, 2);
	ft_putunsign(nb);
}

void	ft_print_u(unsigned int nb, t_list *list)
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
	if (nb < 0 && (list->fillzer || ((list->prec && list->prec_len >=
	ft_len_u(nb)))))
	{
		ft_putchar('-', 0);
		list->width--;
		nb = -nb;
	}
	if (list->left)
		ft_left_u(nb, list, c);
	else
		ft_right_u(nb, list, c);
}
