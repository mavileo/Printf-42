/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 22:15:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/07 05:43:36 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_s(char *str, t_list *list, char c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	list->fillzer = 0;
	if (list->prec && (list->prec_len > ft_strlen(str) || list->prec_len < 0))
		len = ft_strlen(str);
	else if (list->prec && !list->prec_len && list->width)
		len = 0;
	else if (list->prec && list->prec_len > 0)
		len = list->prec_len;
	else
		len = list->prec_len + ft_strlen(str);
	while (str[i] && (list->prec_len-- || !list->prec))
		ft_putchar(str[i++], 0);
	while (list->width-- > len)
		ft_putchar(c, 0);
}

void	ft_right_s(char *str, t_list *list, char c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	if (list->prec && (list->prec_len > ft_strlen(str) || list->prec_len < 0))
		len = ft_strlen(str);
	else if (list->prec && !list->prec_len && list->width)
		len = 0;
	else if (list->prec)
		len = list->prec_len;
	else
		len = list->prec_len + ft_strlen(str);
	while (list->width-- > len)
		ft_putchar(c, 0);
	while (str[i] && (list->prec_len-- || !list->prec))
		ft_putchar(str[i++], 0);
}

void	ft_null(t_list *list, char c)
{
	int		len;
	char	*nul;

	len = 6;
	if (list->prec && (list->prec_len >= 0 && list->prec_len < 6))
		len = list->prec_len;
	nul = ft_substr("(null)", 0, len);
	if (list->prec_len < 0 && !list->width)
		ft_putstr(nul);
	else if (list->left)
		ft_left_s(nul, list, c);
	else
		ft_right_s(nul, list, c);
	free(nul);
}

void	ft_print_s(char *str, t_list *list)
{
	char c;

	if (list->width < 0)
		list->left = 1;
	if (list->width < 0)
		list->width = -list->width;
	c = ' ';
	if (list->fillzer && !list->prec && !list->left)
		c = '0';
	if (str == NULL)
		ft_null(list, c);
	if (str == NULL || (!*str && !list->width))
		return ;
	if (list->prec_len < 0)
		list->prec_len = ft_strlen(str);
	if (!*str)
		while (list->width--)
			ft_putchar(c, 0);
	if (!*str)
		return ;
	if (list->left)
		ft_left_s(str, list, c);
	else
		ft_right_s(str, list, c);
}
