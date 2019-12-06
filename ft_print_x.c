/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 07:03:43 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_prec_x(char *str, t_list *list, char c, int use)
{
	int len;

	len = ft_strlen(str);
	if (use == 1)
	{
		if (list->prec_len < 0)
			list->prec_len = 0;
		while (list->width > list->prec_len + len)
		{
			ft_putchar(c, 0);
			list->width--;
		}
	}
	else
	{
		while (list->prec_len - ft_strlen(str) > 0)
		{
			ft_putchar('0', 0);
			list->prec_len--;
		}
	}
}

void	ft_left_x(char *str, t_list *list, char c)
{
	int i;

	i = 0;
	if (list->prec && !list->prec_len && !str && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	ft_putstr(str);
	if (list->width >= list->prec_len + ft_strlen(str))
		ft_width_prec_x(str, list, c, 1);
	if (list->prec)
		ft_width_prec_x(str, list, c, 2);
}

void	ft_right_x(char *str, t_list *list, char c)
{
	int i;

	i = 0;
	if (list->prec && !list->prec_len && !str && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	if (list->width >= list->prec_len + ft_strlen(str))
		ft_width_prec_x(str, list, c, 1);
	if (list->prec)
		ft_width_prec_x(str, list, c, 2);
	ft_putstr(str);
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

	if (nb == 0 && list->prec && !list->prec_len)
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
		ft_left_x(str, list, c);
	else
		ft_right_x(str, list, c);
}
