/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:05:16 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/01 21:25:51 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(char *s, t_list *list, int prec_len, int res_len)
{
	int i;

	i = 0;
	if (!prec_len)
		prec_len = list->prec_len;
	if (!list->left && !list->right)
		res_len = res_len + ft_strlen(s);
	if (list->left)
	{
		res_len = res_len + prec_len + ft_strlen(s);
		ft_putstr(s);
		while (--prec_len - ft_strlen(s) > 0)
			ft_putchar(' ');
	}
	else if (list->right)
	{
		if (ft_strlen(s) > prec_len)
			res_len = res_len + prec_len;
		else
			res_len = res_len + ft_strlen(s);
		while (i < prec_len)
			ft_putchar(s[i++]);
	}
	else
		ft_putstr(s);
}
