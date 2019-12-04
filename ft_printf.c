/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:38 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/04 16:57:37 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(const char *str, t_list *list, va_list va_lst)
{
	int		prec_param;

	prec_param = 0;
	if (list->par_len)
		prec_param = va_arg(va_lst, int);
	if (list->type == 'c')
		ft_print_c(va_arg(va_lst, int), list, prec_param);
	else if (list->type == 's')
		ft_print_s(va_arg(va_lst, char *), list, prec_param);
	else if (list->type == 'd' || list->type == 'i')
		ft_print_nb(va_arg(va_lst, int), list, prec_param);
	//else if (list->type == 'p')
	//	ft_print_p(va_arg(va_lst, void *), list, prec_param);
	else if (list->type == 'x' || list->type == 'X')
		ft_print_x(va_arg(va_lst, unsigned int), list, prec_param, list->type);
}

int		ft_printf(const char *str, ...)
{
	int			i;
	t_list		*list;
	t_list		*tmp;
	va_list		va_lst;

	va_start(va_lst, str);
	i = 0;
	list = ft_newlist(ft_count_convers(str));
	tmp = list;
	while (str[i])
	{
		if (i)
			tmp = tmp->next;
		while (str[i] && str[i] != '%')
			ft_putchar(str[i++], 0);
		//if (!str[i])
			//return);
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_putchar('%', 0);
			else
			{
				i = ft_precision(str, i, tmp);
				i = ft_type(str, i, tmp);
				ft_print(str, tmp, va_lst);
			}
			i++;
		}
	}
	va_end(va_lst);
	return (ft_putchar(0, 1));
}

int main()
{
	char s[] = "%u\n";
	char s2[] = "salut ca va";
	int n = 5;
	int *i = &n;

	ft_printf("%X\n", 42);
	printf("%X\n\n", 42);

	ft_printf("%.10X\n", 42);
	printf("%.10X\n\n", 42);

	ft_printf("%-10X\n", 42);
	printf("%-10X\n\n", 42);

	ft_printf("%*X\n", 10, 42);
	printf("%*X\n\n", 10, 42);

	ft_printf("%-.10X\n", 42);
	printf("%-.10X\n\n", 42);

	ft_printf("%0.X\n", 42);
	printf("%0.X\n\n", 42);

	ft_printf("%.*X\n", 10, 42);
	printf("%.*X\n\n", 10, 42);

	ft_printf("%*0X\n", 10, 42);
	printf("%*0X\n\n", 10, 42);

	ft_printf("%X\n", 9999999);
	printf("%X\n\n", 9999999);


	return (0);
}
