/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/01 22:01:16 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(const char *str, t_list *list, int len, va_list va_lst)
{
	int		prec_param;

	prec_param = 0;
	if (list->par_len)
		prec_param = va_arg(va_lst, int);
	if (list->type == 'c')
		ft_print_c(va_arg(va_lst, int), list, prec_param, len);
	else if (list->type == 's')
		ft_print_s(va_arg(va_lst, char *), list, prec_param, len);
	else if (list->type == 's')
		ft_print_s(va_arg(va_lst, char *), list, prec_param, len);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	t_list		*list;
	t_list		*tmp;
	static int	len;
	va_list		va_lst;

	va_start(va_lst, str);
	i = 0;
	len = 0;
	list = ft_newlist(ft_count_convers(str));
	tmp = list;
	while (str[i])
	{
		if (i)
			tmp = tmp->next;
		len = len - i;
		while (str[i] && str[i] != '%')
			ft_putchar(str[i++]);
		len = len + i;
		//if (!str[i])
			//return (len);
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
			{
				ft_putchar('%');
				len++;
			}
			i = ft_precision(str, i, tmp);
			i = ft_type(str, i, tmp) + 1;
			ft_print(str, tmp, len, va_lst);
		}
	}
	va_end(va_lst);
	return (len);
}

#include <stdio.h>
int main()
{
	ft_printf("%*c", 3, 'a');
	return (0);
}