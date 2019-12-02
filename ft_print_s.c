/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:05:16 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/02 22:39:40 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_s(t_list *list, int res_len, int prec_len, char *s)
{
	char	c;

	if (list->fillzer)
		c = '0';
	else
		c = ' ';
	res_len = res_len + prec_len + ft_strlen(s);
	ft_putstr(s);
	while (prec_len - ft_strlen(s) > 0)
	{
		ft_putchar(c);
		prec_len--;
	}
}

void	ft_right_s(t_list *list, int res_len, int prec_len, char *s)
{
	char	c;
	int		i;

	i = 0;
	if (list->fillzer)
		c = '0';
	else
		c = ' ';
	if (ft_strlen(s) > prec_len)
		res_len = res_len + prec_len;
	else
		res_len = res_len + ft_strlen(s);
	while (prec_len - ft_strlen(s) > 0)
	{
		ft_putchar(c);
		prec_len--;
	}
	if (!list->only_zer)
		while (i < prec_len && s[i])
			ft_putchar(s[i++]);
	else
		while (s[i])
			ft_putchar(s[i++]);
}

void	ft_print_s(char *s, t_list *list, int prec_len, int res_len)
{

	if (!prec_len)
		prec_len = list->prec_len;
	if (!list->left && !list->right)
		res_len = res_len + ft_strlen(s);
/* 	printf("list->fillzer %d\n", list->fillzer);
	printf("list->point %d\n", list->point);
	printf("list->left %d\n", list->left);
	printf("prec_len %d\n", prec_len); */
	if (list->left)
		ft_left_s(list, res_len, prec_len, s);
	else if (list->right || list->fillzer)
		ft_right_s(list, res_len, prec_len, s);
	else
		ft_putstr(s);
}
