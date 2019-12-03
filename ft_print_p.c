/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/04 00:11:13 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_p(int nb)
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

void	ft_left_p(int nb, t_list *list, int prec_len)
{
	int		len_nb;
	char	c;

	if ((list->fillzer || list->point) && !list->left && !list->star_point)
		c = '0';
	else
		c = ' ';
	len_nb = ft_len_p(nb);
	ft_putnbr(nb);
	while (prec_len-- - len_nb > 0)
		ft_putchar(c, 0);
}

void	ft_right_p(int nb, t_list *list, int prec_len)
{
	int		len_nb;
	char	c;

	if ((list->fillzer || list->point) && !list->left && !list->star_point)
		c = '0';
	else
		c = ' ';
	len_nb = ft_len_p(nb);
	while (prec_len-- - len_nb > 0)
		ft_putchar(c, 0);
	ft_putnbr(nb);
}

void	ft_print_p(void *addr, t_list *list, int prec_len)
{
	int		len_nb;

	uintptr_t p;

	p = (uintptr_t)addr;
	printf("address of a = 0x%"PRIXPTR, uip);
	len_nb = ft_len_p(nb);
	if (!prec_len)
		prec_len = list->prec_len;
	if (list->left)
		ft_left_p(nb, list, prec_len);
	else if (list->right)
		ft_right_p(nb, list, prec_len);
	else
		ft_putnbr(nb);
}
