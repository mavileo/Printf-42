#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	//printf("%ld\n", i);
	int i;
	i = ft_printf("%u", 4294967);
	i = printf("%u", 4294967);
	return (0);
}
