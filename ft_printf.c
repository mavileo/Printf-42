#include "ft_printf.h"

void	ft_print(t_list *list, va_list va_lst)
{
	int		prec_param;

	prec_param = 0;
	if (list->par_len)
		prec_param = va_arg(va_lst, int);
	if (list->type == 'c')
		ft_print_c(va_arg(va_lst, int), list, prec_param);
	else if (list->type == 's')
		ft_print_s(va_arg(va_lst, char *), list, prec_param);
	else if (list->type == 'd' || list->type == 'i' || list->type == 'u')
		ft_print_nb(va_arg(va_lst, int), list, prec_param);
	else if (list->type == 'p')
		ft_print_p(va_arg(va_lst, void *), list, prec_param);
	else if (list->type == 'x' || list->type == 'X')
		ft_print_x(va_arg(va_lst, unsigned int), list, prec_param, list->type);
	else if (list->type == 'u')
		ft_print_u(va_arg(va_lst, unsigned int), list, prec_param);
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
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				ft_putchar('%', 0);
			else
			{
				i = ft_precision(str, i, tmp);
				i = ft_type(str, i, tmp);
				ft_print(tmp, va_lst);
			}
			i++;
		}
	}
	va_end(va_lst);
	return (ft_putchar(0, 1));
}

int main()
{
	int i = 5;
	int *p = &i;

	ft_printf("%p\n", p);
	printf("%p\n", p);

	ft_printf("%2p\n", p);
	printf("%2p\n", p);

	ft_printf("%-15p\n", p);
	printf("%-15p\n", p);


	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);


	return (0);
}
