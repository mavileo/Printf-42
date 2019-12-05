#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


int main()
{
	char s2[] = "salut ca va bien";
	int i;
	int i2;

	printf("\n\n----------NUMBERS----------\n\n");

	i = ft_printf("%-.10d|\n", INT_MAX);
	i2 = printf("%-.10d|\n\n", INT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%0.10d|\n", INT_MAX);
	i2 = printf("%0.10d|\n\n", INT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.010d|\n", INT_MIN);
	i2 = printf("%.010d|\n\n", INT_MIN);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-*d|\n", 50, INT_MIN);
	i2 = printf("%-*d|\n\n", 50, INT_MIN);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.*d|\n", 50, -50);
	i2 = printf("%.*d|\n\n", 50, -50);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%*.d|\n", 50, INT_MIN);
	i2 = printf("%*.d|\n\n", 50, INT_MIN);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%0*d|\n", 10, INT_MAX);
	i2 = printf("%0*d|\n\n", 10, INT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-*d|\n", -10, INT_MIN);
	i2 = printf("%-*d|\n\n", -10, INT_MIN);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.*d|\n", 50, -50);
	i2 = printf("%.*d|\n\n", 50, -50);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%*.d|\n", -50, INT_MIN);
	i2 = printf("%*.d|\n\n", -50, INT_MIN);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%0*d|\n", -10, INT_MAX);
	i2 = printf("%0*d|\n\n", -10, INT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-.010d|\n", INT_MAX);
	i2 = printf("%-.010d|\n\n", INT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-.05d|\n", 0);
	i2 = printf("%-.05d|\n\n", 0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%*.0d|\n", 5, 0);
	i2 = printf("%*.0d|\n\n", 5, 0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%0*.d|\n", 5, 0);
	i2 = printf("%0*.d|\n\n", 5, 0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	

	printf("\n\n----------STRINGS----------\n\n");

	i = ft_printf("%.10s|\n", s2);
	i2 = printf("%.10s|\n\n", s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
 	i = ft_printf("%-10s|\n", "");
	i2 = printf("%-10s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-.10s|\n", "");
	i2 = printf("%-.10s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.010s|\n", s2);
	i2 = printf("%.010s|\n\n", s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.40s|\n", s2);
	i2 = printf("%.40s|\n\n", s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-40s|\n", "");
	i2 = printf("%-40s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-.40s|\n", "");
	i2 = printf("%-.40s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.040s|\n", "");
	i2 = printf("%.040s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.*s|\n", 10, s2);
	i2 = printf("%.*s|\n\n", 10, s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-*s|\n", 10, s2);
	i2 = printf("%-*s|\n\n", 10, s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%*.s|\n", 10, "");
	i2 = printf("%*.s|\n\n", 10, "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.*s|\n", 10, "");
	i2 = printf("%.*s|\n\n", 10, "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.50s|\n", "");
	i2 = printf("%.50s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
 	i = ft_printf("%-50s|\n", "");
	i2 = printf("%-50s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-.50s|\n", "");
	i2 = printf("%-.50s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.050s|\n", "");
	i2 = printf("%.050s|\n\n", "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.*s|\n", -50, s2);
	i2 = printf("%.*s|\n\n", -50, s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-*s|\n", -50, s2);
	i2 = printf("%-*s|\n\n", -50, s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%*.s|\n", -50, "");
	i2 = printf("%*.s|\n\n", -50, "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.*s|\n", 10, "");
	i2 = printf("%.*s|\n\n", 10, "");

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	printf("\n\n----------CHARS----------\n\n");

	i = ft_printf("%*c|\n", 50, (char)0);
	i2 = printf("%*c|\n\n", 50, (char)0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-2c|\n", (char)0);
	i2 = printf("%-2c|\n\n", (char)0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%*.c|\n", 50, (char)0);
	i2 = printf("%*.c|\n\n", 50, (char)0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	printf("\n\n----------HEXA UNSIGNED INT----------\n\n");

	i = ft_printf("%x|\n", 42);
	i2 = printf("%x|\n\n", 42);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.10X|\n", UINT_MAX);
	i2 = printf("%.10X|\n\n", UINT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-10X|\n", UINT_MAX);
	i2 = printf("%-10X|\n\n", UINT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%*x|\n", -10, UINT_MAX);
	i2 = printf("%*x|\n\n", -10, UINT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-.10X|\n", 42);
	i2 = printf("%-.10X|\n\n", 42);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%0.X|\n", 0);
	i2 = printf("%0.X|\n\n", 0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.*x|\n", -10, 0);
	i2 = printf("%.*x|\n\n", -10, 0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%X|\n", 9999999);
	i2 = printf("%X|\n\n", 9999999);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	printf("\n\n----------UNSIGNED INT----------\n\n");

	i = ft_printf("%-.10u|\n", UINT_MAX);
	i2 = printf("%-.10u|\n\n", UINT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%0.10u|\n", UINT_MAX);
	i2 = printf("%0.10u|\n\n", UINT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%.05u|\n", UINT_MAX);
	i2 = printf("%.05u|\n\n", UINT_MAX);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-*u|\n", 30, 0);
	i2 = printf("%-*u|\n\n", 30, 0);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	printf("\n\n----------ADRESS----------\n\n");

	i = ft_printf("%p|\n", s2);
	i2 = printf("%p|\n\n", s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%p|\n", NULL);
	i2 = printf("%p|\n\n", NULL);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%-50p|\n", s2);
	i2 = printf("%-50p|\n\n", s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	
	i = ft_printf("%*p|\n", 50, s2);
	i2 = printf("%*p|\n\n", 50, s2);

	if (i == i2 - 1)
		printf("GOOD RETURN\n\n\n");
	else
		printf("BAD RETURN\n\n\n");
	

	return (0);
}
