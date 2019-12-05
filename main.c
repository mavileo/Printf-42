#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>


int main()
{
	char s2[] = "salut ca va bien";

	printf("\n\n----------NUMBERS----------\n\n");

	ft_printf("%-.10d\n", INT_MAX);
	printf("%-.10d\n", INT_MAX);

	ft_printf("%0.10d\n", INT_MAX);
	printf("%0.10d\n\n", INT_MAX);

	ft_printf("%.010d\n", INT_MIN);
	printf("%.010d\n\n", INT_MIN);

	ft_printf("%-*d\n", 50, INT_MIN);
	printf("%-*d\n\n", 50, INT_MIN);

	ft_printf("%.*d\n", 50, INT_MIN);
	printf("%.*d\n\n", 50, INT_MIN);

	ft_printf("%*.d\n", 50, INT_MIN);
	printf("%*.d\n\n", 50, INT_MIN);

	ft_printf("%0*d\n", 10, INT_MAX);
	printf("%0*d\n\n", 10, INT_MAX);

	ft_printf("%-.010d\n", INT_MAX);
	printf("%-.010d\n\n", INT_MAX);

	ft_printf("%-.05d\n", 50);
	printf("%-.05d\n\n", 50);

	ft_printf("%*.0d\n", 5, 50);
	printf("%*.0d\n\n", 5, 50);

	ft_printf("%0*.d\n", 5, 50);
	printf("%0*.d\n\n", 5, 50);


	printf("\n\n----------STRINGS----------\n\n");

	ft_printf("%.10s|\n", s2);
	printf("%.10s|\n\n", s2);

 	ft_printf("%-10s|\n", "");
	printf("%-10s|\n\n", "");

	ft_printf("%-.10s|\n", "");
	printf("%-.10s|\n\n", "");

	ft_printf("%.010s|\n", s2);
	printf("%.010s|\n\n", s2);

	ft_printf("%.40s|\n", s2);
	printf("%.40s|\n\n", s2);

	ft_printf("%-40s|\n", "");
	printf("%-40s|\n\n", "");

	ft_printf("%-.40s|\n", "");
	printf("%-.40s|\n\n", "");

	ft_printf("%.040s|\n", "");
	printf("%.040s|\n\n", "");

	ft_printf("%.*s|\n", 10, s2);
	printf("%.*s|\n\n", 10, s2);

	ft_printf("%-*s|\n", 10, s2);
	printf("%-*s|\n\n", 10, s2);

	ft_printf("%*.s|\n", 10, "");
	printf("%*.s|\n\n", 10, "");

	ft_printf("%.*s|\n", 10, "");
	printf("%.*s|\n\n", 10, "");

	ft_printf("%.50s|\n", "");
	printf("%.50s|\n\n", "");

 	ft_printf("%-50s|\n", "");
	printf("%-50s|\n\n", "");

	ft_printf("%-.50s|\n", "");
	printf("%-.50s|\n\n", "");

	ft_printf("%.050s|\n", "");
	printf("%.050s|\n\n", "");

	ft_printf("%.*s|\n", 50, s2);
	printf("%.*s|\n\n", 50, s2);

	ft_printf("%-*s|\n", 50, s2);
	printf("%-*s|\n\n", 50, s2);

	ft_printf("%*.s|\n", 50, s2);
	printf("%*.s|\n\n", 50, s2);

	ft_printf("%.*s|\n", 10, s2);
	printf("%.*s|\n\n", 10, s2);

	printf("\n\n----------CHARS----------\n\n");

	ft_printf("%*c|\n", 50, (char)0);
	printf("%*c|\n\n", 50, (char)0);

	ft_printf("%-10c|\n", (char)0);
	printf("%-10c|\n\n", (char)0);

	ft_printf("%*.c|\n", 50, (char)0);
	printf("%*.c|\n\n", 50, (char)0);

	printf("\n\n----------HEXA UNSIGNED INT----------\n\n");

	ft_printf("%x\n", 42);
	printf("%x\n\n", 42);

	ft_printf("%.10X\n", UINT_MAX);
	printf("%.10X\n\n", UINT_MAX);

	ft_printf("%-10X\n", UINT_MAX);
	printf("%-10X\n\n", UINT_MAX);

	ft_printf("%*x\n", 10, UINT_MAX);
	printf("%*x\n\n", 10, UINT_MAX);

	ft_printf("%-.10X\n", 42);
	printf("%-.10X\n\n", 42);

	ft_printf("%0.X\n", 0);
	printf("%0.X\n\n", 0);

	ft_printf("%.*x\n", 10, 0);
	printf("%.*x\n\n", 10, 0);

	ft_printf("%X\n", 9999999);
	printf("%X\n\n", 9999999);

	printf("\n\n----------UNSIGNED INT----------\n\n");

	ft_printf("%-.10u\n", UINT_MAX);
	printf("%-.10u\n\n", UINT_MAX);

	ft_printf("%0.10u\n", UINT_MAX);
	printf("%0.10u\n\n", UINT_MAX);

	ft_printf("%.030u\n", UINT_MAX);
	printf("%.030u\n\n", UINT_MAX);

	ft_printf("%-*u\n", 30, 0);
	printf("%-*u\n\n", 30, 0);


	return (0);
}
