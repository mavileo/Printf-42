/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:42:47 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 02:42:46 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_x(char *nb, t_list *list, int prec_len)
{
	int		len_nb;
	char	c;

	if ((list->fillzer || list->point) && !list->left && !list->star_point)
		c = '0';
	else
		c = ' ';
	len_nb = ft_strlen(nb);
	ft_putstr(nb);
	while (prec_len-- - len_nb > 0)
		ft_putchar(c, 0);
}

void	ft_right_x(char *nb, t_list *list, int prec_len)
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
	ft_putstr(nb);
}

void	ft_print_x(unsigned int n, t_list *list, int prec_len, char type)
{
	int		len_nb;
	char	*nb;

	if (type == 'x')
		nb = ft_itoa_base(n, "0123456789abcdef");
	else
		nb = ft_itoa_base(n, "0123456789ABCDEF");
	len_nb = ft_strlen(nb);
	if (!prec_len)
		prec_len = list->prec_len;
	if (list->left)
		ft_left_x(nb, list, prec_len);
	else if (list->right)
		ft_right_x(nb, list, prec_len);
	else
		ft_putstr(nb);
	free(nb);
}
