#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

//TESTER AVEC DES CONVERSIONS NON GEREES %lu %zu...
//TESTER AVC PLEINS DE CARACTERES ENTRE LE % ET LE TYPE
//TESTER AVEC DES ARGUMENTS DU MAUVAIS TYPE
//TESTER PLUSIEURS CONVERSIONS DANS LE MEME PRINTF
//7 8 11 12 13 strings
int main()
{
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
	
}
