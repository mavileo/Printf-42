/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 01:29:17 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_p(char *nb, t_list *list, int prec_len)
{
	int		len_nb;
	char	c;

	if ((list->fillzer || list->point) && !list->left && !list->star_point)
		c = '0';
	else
		c = ' ';
	len_nb = ft_strlen(nb);
	ft_putstr("0x");
	ft_putstr(nb);
	while (prec_len-- - len_nb > 0)
		ft_putchar(c, 0);
}

void	ft_right_p(char *nb, t_list *list, int prec_len)
{
	int		len_nb;
	char	c;

	if ((list->fillzer || list->point) && !list->left && !list->star_point)
		c = '0';
	else
		c = ' ';
	len_nb = ft_strlen(nb);
	while (prec_len-- - len_nb > 0)
		ft_putchar(c, 0);
	ft_putstr("0x");
	ft_putstr(nb);
}

void	ft_print_p(void *addr, t_list *list, int prec_len)
{
	int			len_nb;
	char		*nb;
	intptr_t	p;

	p = (intptr_t)addr;
	nb = ft_itoa_base(p, "0123456789abcdef");
	len_nb = ft_strlen(nb) + 2;
	if (!prec_len)
		prec_len = list->prec_len;
	if (list->left)
		ft_left_p(nb, list, prec_len);
	else if (list->right)
		ft_right_p(nb, list, prec_len);
	else
	{
		ft_putstr("0x");
		ft_putstr(nb);
	}
}
