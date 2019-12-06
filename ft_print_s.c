/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 05:59:47 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_s(char *str, t_list *list, char c)
{
	int len;

	len = ft_strlen(str);
	if (list->prec_len < 0)
		list->prec_len = 0;
	while (list->width > list->prec_len + len)
	{
		ft_putchar(c, 0);
		list->width--;
	}
}

void	ft_left_s(char *str, t_list *list, char c)
{
	int i;

	i = 0;
	if (list->prec && !list->prec_len && !str && list->width)
	{
		while (list->width--)
			ft_putchar(c, 0);
		return ;
	}
	while (str[i] && (list->prec_len-- || !list->prec))
		ft_putchar(str[i++], 0);
	if (list->width >= list->prec_len + ft_strlen(str))
		ft_width_s(str, list, c);
}

void	ft_right_s(char *str, t_list *list, char c)
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
		ft_width_s(str, list, c);
	while (str[i] && (list->prec_len-- || !list->prec))
		ft_putchar(str[i++], 0);
}

void	ft_null(t_list *list, char c)
{
	if (!list->width)
		ft_putstr("(null)");
	else
		while (list->width--)
			ft_putchar(c, 0);
}

void	ft_print_s(char *str, t_list *list)
{
	char c;

	if (list->prec_len < 0)
		list->prec_len = ft_strlen(str);
	if (list->fillzer && !list->prec)
		c = '0';
	else
		c = ' ';
	if (str == NULL)
	{
		ft_null(list, c);
		return ;
	}
	if (!*str && !list->width)
		return ;
	if (list->width < 0)
	{
		list->left = 1;
		list->width = -list->width;
	}
	if (list->left)
		ft_left_s(str, list, c);
	else
		ft_right_s(str, list, c);
}
