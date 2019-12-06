/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 06:46:30 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_prec_p(char *str, t_list *list, char c, int use)
{
	int len;

	len = ft_strlen(str) + 2;
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

void	ft_left_p(char *str, t_list *list, char c)
{
	int i;

	i = 0;
	if (list->prec && !list->prec_len && !str && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	ft_putstr("0x");
	ft_putstr(str);
	if (list->width >= list->prec_len + ft_strlen(str) + 2)
		ft_width_prec_p(str, list, c, 1);
	if (list->prec)
		ft_width_prec_p(str, list, c, 2);
}

void	ft_right_p(char *str, t_list *list, char c)
{
	int i;

	i = 0;
	if (list->prec && !list->prec_len && !str && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	if (list->width >= list->prec_len + ft_strlen(str) + 2)
		ft_width_prec_p(str, list, c, 1);
	if (list->prec)
		ft_width_prec_p(str, list, c, 2);
	ft_putstr("0x");
	ft_putstr(str);
}

void	ft_print_p(void *addr, t_list *list)
{
	char c;
	char *str;

	if (addr == (void*)-1)
		str = ft_strdup("ffffffffffffffff");
	else
		str = ft_itoa_base((intptr_t)addr, "0123456789abcdef");
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
		ft_left_p(str, list, c);
	else
		ft_right_p(str, list, c);
}
