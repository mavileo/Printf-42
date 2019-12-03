/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:05:16 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/03 23:11:32 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_s(t_list *list, int prec_len, char *s)
{
	char	c;

	if (list->fillzer)
		c = '0';
	else
		c = ' ';
	ft_putstr(s);
	while (prec_len - ft_strlen(s) > 0)
	{
		ft_putchar(c, 0);
		prec_len--;
	}
}

void	ft_right_s(t_list *list, int prec_len, char *s)
{
	char	c;
	int		i;

	i = 0;
	if (list->fillzer)
		c = '0';
	else
		c = ' ';
	while (prec_len - ft_strlen(s) > 0)
	{
		ft_putchar(c, 0);
		prec_len--;
	}
	if (!list->only_zer)
		while (i < prec_len && s[i])
			ft_putchar(s[i++], 0);
	else
		while (s[i])
			ft_putchar(s[i++], 0);
}

int		ft_only_point(t_list *list, int prec_len, char *s)
{
	if (!list->left && !list->par_len && list->point)
		if (prec_len >= ft_strlen(s))
			return (1);
	if (prec_len >= ft_strlen(s) && list->point_star)
		return (1);
	return (0);
}

void	ft_print_s(char *s, t_list *list, int prec_len)
{
	char	c;

	if (s == NULL)
		return ;
	if (list->fillzer)
		c = '0';
	else
		c = ' ';
	if (!prec_len)
		prec_len = list->prec_len;
	if (list->left)
		ft_left_s(list, prec_len, s);
	else if ((list->right || list->fillzer) &&
	!ft_only_point(list, prec_len, s) && !list->star_point)
		ft_right_s(list, prec_len, s);
	else if (list->star_point)
		while (prec_len-- > 0)
			ft_putchar(c, 0);
	else
		ft_putstr(s);
}
