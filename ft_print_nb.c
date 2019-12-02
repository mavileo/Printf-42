/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/02 22:31:10 by mavileo          ###   ########.fr       */
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

void	ft_left_nb(int nb, t_list *list, int prec_len, char c)
{
	int len_nb;

	len_nb = ft_len_nb(nb);
	ft_putnbr(nb);
	while (prec_len-- - len_nb > 0)
		ft_putchar(c);
}

void	ft_right_nb(int nb, t_list *list, int prec_len, char c)
{
	int len_nb;

	len_nb = ft_len_nb(nb);
	while (prec_len-- - len_nb > 0)
		ft_putchar(c);
	ft_putnbr(nb);
}

void	ft_print_nb(int nb, t_list *list, int prec_len, int res_len)
{
	int		len_nb;
	char	c;

	len_nb = ft_len_nb(nb);
	if (!prec_len)
		prec_len = list->prec_len;
/* 	printf("list->fillzer %d\n", list->fillzer);
	printf("list->point %d\n", list->point);
	printf("list->left %d\n", list->left);
	printf("list->star_point %d\n", list->star_point); */
	if ((list->fillzer || list->point) && !list->left && !list->star_point)
		c = '0';
	else
		c = ' ';
	res_len = res_len + prec_len + len_nb;
	if (list->left)
		ft_left_nb(nb, list, prec_len, c);
	else if (list->right)
		ft_right_nb(nb, list, prec_len, c);
	else
		ft_putnbr(nb);
}
