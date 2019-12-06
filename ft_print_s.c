/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 07:38:54 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_s(t_list *list, char c, int len)
{
	while (list->width > len)
	{
		ft_putchar(c, 0);
		list->width--;
	}
}

void	ft_left_s(char *str, t_list *list, char c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (list->prec_len > ft_strlen(str) && list->prec)
		len = ft_strlen(str);
	else if (list->prec)
		len = list->prec_len;
	else
		len = list->prec_len + ft_strlen(str);
	while (str[i] && (list->prec_len-- || !list->prec))
		ft_putchar(str[i++], 0);
	ft_width_s(list, c, len);
}

void	ft_right_s(char *str, t_list *list, char c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (list->prec_len > ft_strlen(str) && list->prec)
		len = ft_strlen(str);
	else if (list->prec)
		len = list->prec_len;
	else
		len = list->prec_len + ft_strlen(str);
	ft_width_s(list, c, len);
	while (str[i] && (list->prec_len-- || !list->prec))
		ft_putchar(str[i++], 0);
}

void	ft_null(t_list *list, char c)
{
	if (!list->width)
		ft_putstr("(null)");
	else
		while (list->width-- > 0)
			ft_putchar(c, 0);
}

void	ft_print_s(char *str, t_list *list)
{
	char c;

	if (list->prec_len < 0)
		list->prec_len = ft_strlen(str);
	c = ' ';
	if (list->fillzer && !list->prec)
		c = '0';
	if (str == NULL)
		ft_null(list, c);
	if (str == NULL)
		return ;
	if (!*str && !list->width)
		return ;
	if (!*str && list->prec)
		ft_null(list, c);
	if (!*str && list->prec)
		return ;
	if (list->width < 0)
		list->left = 1;
	if (list->width < 0)
		list->width = -list->width;
	if (list->left)
		ft_left_s(str, list, c);
	else
		ft_right_s(str, list, c);
}
