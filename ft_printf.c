/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/29 16:39:14 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_convers(char c)
{
	char	list[] = "cspdiuxX";
	int		i;

	i = 0;
	while (list[i])
		if (c == list[i++])
			return (1);
	return (0);
}

t_struct	precision(const char *str, int i)
{
	t_struct stru;
	printf("tghrth %s")
	while (!check_convers(str[i]) && !ft_isdigit(str[i]))
	{
		if (str[i] == '0')
			stru.fillzer = 1;
		if (str[i] == '-')
		{
			stru.fillzer = 0;
			stru.left = 1;
		}
		if (str[i] == '.')
		{
			stru.fillzer = 1;
			stru.left = 0;
		}
		if (str[i] == '*')
			stru.prec = 1;
	}
	stru.len = ft_atoi(str + i);
	while (!check_convers(str[i]) && ft_isdigit(str[i]))
		i++;
	stru.i = i;
	return (stru);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	t_struct stru;

	i = 0;
	va_start(args, str);
	while (is_print(str[i]))
	{
		while (is_print(str[i]) && str[i] != '%')
			ft_putchar(str[i++]);
		if (!str[i])
			return (i);
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_putchar('%');
			stru = precision(str, i);
			i = stru.i;
		}
	}
	ve_end(args);
}
