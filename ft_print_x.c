/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 21:38:31 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_prec_x(char *str, t_list *list, char c, int use)
{
	int		len;

	len = ft_strlen(str);
	if (list->prec_len > ft_strlen(str) && list->prec)
		len = list->prec_len;
	if (use == 1)
		while (list->width-- > len)
			ft_putchar(c, 0);
	if (use == 2)
	{
		len = list->prec_len;
		while (len-- - ft_strlen(str) > 0)
			ft_putchar('0', 0);
	}
}

void	ft_left_x(char *str, t_list *list, char c, int nb)
{
	int i;

	list->fillzer = 0;
	i = 0;
	if (list->prec && !list->prec_len && !nb && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	else
	{
		if (list->prec)
			ft_width_prec_x(str, list, c, 2);
		ft_putstr(str);
		ft_width_prec_x(str, list, c, 1);
	}
}

void	ft_right_x(char *str, t_list *list, char c, int nb)
{
	int i;

	i = 0;
	if (list->prec && !list->prec_len && !nb && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	else
	{
		ft_width_prec_x(str, list, c, 1);
		if (list->prec)
			ft_width_prec_x(str, list, c, 2);
		ft_putstr(str);
	}
}

char	*ft_nb_x(unsigned int n, char type)
{
	char *nb;

	if (type == 'x')
		nb = ft_itoa_base(n, "0123456789abcdef");
	else
		nb = ft_itoa_base(n, "0123456789ABCDEF");
	return (nb);
}

void	ft_print_x(unsigned int nb, t_list *list)
{
	char c;
	char *str;

	if (!nb && list->prec && !list->prec_len && !list->width)
		return ;
	str = ft_nb_x(nb, list->type);
	if (list->prec_len < 0)
		list->prec_len = ft_strlen(str);
	if (list->fillzer && !list->prec)
		c = '0';
	else
		c = ' ';
	if (!*str && !list->width)
		return ;
	if (list->width < 0)
	{
		list->left = 1;
		list->width = -list->width;
	}
	if (list->left && list->width)
		ft_left_x(str, list, c, nb);
	else
		ft_right_x(str, list, c, nb);
}
