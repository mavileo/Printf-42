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
	//else if (list->type == 'p')
	//	ft_print_p(va_arg(va_lst, void *), list, prec_param);
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
	char s2[] = "salut ca va bien";
	char c = 'a';

	printf("\n\n----------NUMBERS----------\n\n");

	ft_printf("%-.10d\n", 50);
	printf("%-.10d\n", 50);

	ft_printf("%0.10d\n", 50);
	printf("%0.10d\n\n", 50);

	ft_printf("%.010d\n", 50);
	printf("%.010d\n\n", 50);

	ft_printf("%-*d\n", 10, 50);
	printf("%-*d\n\n", 10, 50);

	ft_printf("%.*d\n", 10, 50);
	printf("%.*d\n\n", 10, 50);

	ft_printf("%*.d\n", 10, 50);
	printf("%*.d\n\n", 10, 50);

	ft_printf("%0*d\n", 10, 50);
	printf("%0*d\n\n", 10, 50);

	ft_printf("%-.010d\n", 50);
	printf("%-.010d\n\n", 50);

	ft_printf("%-.010d\n", 50);
	printf("%-.010d\n\n", 50);

	ft_printf("%*.0d\n", 10, 50);
	printf("%*.0d\n\n", 10, 50);

	ft_printf("%0*.d\n", 10, 50);
	printf("%0*.d\n\n", 10, 50);


	printf("\n\n----------STRINGS----------\n\n");

	ft_printf("%.10s|\n", s2);
	printf("%.10s|\n\n", s2);

 	ft_printf("%-10s|\n", s2);
	printf("%-10s|\n\n", s2);

	ft_printf("%-.10s|\n", s2);
	printf("%-.10s|\n\n", s2);

	ft_printf("%.010s|\n", s2);
	printf("%.010s|\n\n", s2);

	ft_printf("%.40s|\n", s2);
	printf("%.40s|\n\n", s2);

	ft_printf("%-40s|\n", s2);
	printf("%-40s|\n\n", s2);

	ft_printf("%-.40s|\n", s2);
	printf("%-.40s|\n\n", s2);

	ft_printf("%.040s|\n", s2);
	printf("%.040s|\n\n", s2);

	ft_printf("%.*s|\n", 10, s2);
	printf("%.*s|\n\n", 10, s2);

	ft_printf("%-*s|\n", 10, s2);
	printf("%-*s|\n\n", 10, s2);

	ft_printf("%*.s|\n", 10, s2);
	printf("%*.s|\n\n", 10, s2);

	ft_printf("%.*s|\n", 10, s2);
	printf("%.*s|\n\n", 10, s2);

	ft_printf("%.50s|\n", s2);
	printf("%.50s|\n\n", s2);

 	ft_printf("%-50s|\n", s2);
	printf("%-50s|\n\n", s2);

	ft_printf("%-.50s|\n", s2);
	printf("%-.50s|\n\n", s2);

	ft_printf("%.050s|\n", s2);
	printf("%.050s|\n\n", s2);

	ft_printf("%.*s|\n", 50, s2);
	printf("%.*s|\n\n", 50, s2);

	ft_printf("%-*s|\n", 50, s2);
	printf("%-*s|\n\n", 50, s2);

	ft_printf("%*.s|\n", 50, s2);
	printf("%*.s|\n\n", 50, s2);

	ft_printf("%.*s|\n", 10, s2);
	printf("%.*s|\n\n", 10, s2);

	printf("\n\n----------CHARS----------\n\n");

	ft_printf("%*c|\n", 50, c);
	printf("%*c|\n\n", 50, c);

	ft_printf("%-10c|\n", c);
	printf("%-10c|\n\n", c);

	ft_printf("%*.c|\n", 50, c);
	printf("%*.c|\n\n", 50, c);

	printf("\n\n----------HEXA UNSIGNED INT----------\n\n");

	ft_printf("%x\n", 42);
	printf("%x\n\n", 42);

	ft_printf("%.10X\n", 42);
	printf("%.10X\n\n", 42);

	ft_printf("%-10X\n", 42);
	printf("%-10X\n\n", 42);

	ft_printf("%*x\n", 10, 42);
	printf("%*x\n\n", 10, 42);

	ft_printf("%-.10X\n", 42);
	printf("%-.10X\n\n", 42);

	ft_printf("%0.X\n", 42);
	printf("%0.X\n\n", 42);

	ft_printf("%.*x\n", 10, 42);
	printf("%.*x\n\n", 10, 42);

	ft_printf("%X\n", 9999999);
	printf("%X\n\n", 9999999);

	printf("\n\n----------UNSIGNED INT----------\n\n");

	ft_printf("%-.10u\n", 2000546511);
	printf("%-.10u\n\n", 2000546511);

	ft_printf("%0.10u\n", 2000546511);
	printf("%0.10u\n\n", 2000546511);

	ft_printf("%.030u\n", 2000546511);
	printf("%.030u\n\n", 2000546511);

	ft_printf("%-*u\n", 30, 2000546511);
	printf("%-*u\n\n", 30, 2000546511);


	return (0);
}
