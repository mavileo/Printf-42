/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/01 17:03:22 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_convers(char c)
{
	char	*list;
	int		i;
	int		res;

	list = ft_strdup("cspdiuxX");
	i = 0;
	res = 0;
	while (list[i])
		if (c == list[i++])
			res = 1;
	return (res);
}

int		precision(const char *str, int i, t_list *stru)
{
	stru->fillzer = 0;
	stru->left = 1;
	stru->prec = 1;
	while (!check_convers(str[i]) && !ft_isdigit(str[i]))
	{
		if (str[i] == '0')
			stru->fillzer = 1;
		if (str[i] == '-')
		{
			stru->fillzer = 0;
			stru->left = 1;
		}
		if (str[i] == '.')
		{
			stru->fillzer = 1;
			stru->left = 0;
		}
		if (str[i] == '*')
			stru->prec = 1;
	}
	stru->len = ft_atoi(str + i);
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	stru->i = i;
	return (i);
}

int		type(const char *str, int i, t_list *stru)
{
	while (!check_convers(str[i]))
		i++;
	stru->type = str[i];
	return (i);
}

int		count_convers(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == '%')
			count++;
	return (count);
}

t_list	*ft_newlist(int nb)
{
	t_list	*elem;
	t_list	*res;

	res = NULL;
	while (nb > 0)
	{
		if (!(elem = malloc(sizeof(t_list))))
			return (NULL);
		elem->prec = 0;
		elem->len = 0;
		elem->fillzer = 0;
		elem->left = 0;
		elem->s = NULL;
		elem->p = NULL;
		elem->i = 0;
		elem->type = 0;
		elem->next = res;
		res = elem;
		nb--;
	}
	return (res);
}

//void	print(const char *str)

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = lst;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	t_list		*list;
	t_list		*tmp;
	static int	len;

	i = 0;
	len = 0;
	list = ft_newlist(count_convers(str));
	tmp = list;
	while (ft_isprint(str[i]))
	{
		printf("i1 %d\n", i);
		if (i)
			tmp = tmp->next;
		printf("i2 %d\n", i);
		len = len - i;
		while (ft_isprint(str[i]) && str[i] != '%')
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
			i = precision(str, i, tmp);
			i = type(str, i, tmp) + 1;
		printf("i3 %d\n", i);
		}
		printf(" 1 \n");
		printf("type 1 %c\n", list->type);
		printf("lstsize %d \n", ft_lstsize(list));
		printf("type 2 %c\n", list->next->type);
	}

	return (0);
}

#include <stdio.h>
int main()
{
	ft_printf("rgrbrbh%d\nyhygb %s");
}