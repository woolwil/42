#include "ft_printf.h"

int	main(void)
{
	int	total = 0;
	int	len;

	ft_printf("-------------LIBC PRINTF-------------\n\n");
	printf("c: %c\n", 'A');
	printf("s: %s\n", "hello");
	printf("p: %p\n", (void *)0x1234abcd);
	printf("d: %d\n", -42);
	printf("i: %i\n", 123);
	printf("u: %u\n", 4294967295u);
	printf("x: %x\n", 3735928559u);
	printf("X: %X\n", 3735928559u);
	printf("percent: %%\n");
	ft_printf("\n");
	ft_printf("-------------FT_PRINTF-------------\n\n");
	len = ft_printf("c: %c\n", 'A');                       total += len;
	len = ft_printf("s: %s\n", "hello");                   total += len;
	len = ft_printf("p: %p\n", (void *)0x1234abcd);        total += len;
	len = ft_printf("d: %d\n", -42);                       total += len;
	len = ft_printf("i: %i\n", 123);                       total += len;
	len = ft_printf("u: %u\n", 4294967295u);               total += len;
	len = ft_printf("x: %x\n", 3735928559u);               total += len;
	len = ft_printf("X: %X\n", 3735928559u);               total += len;
	len = ft_printf("percent: %%\n");                      total += len;
	ft_printf("\n");
	ft_printf("Total printed across all calls: %d\n", total);
	len = ft_printf("Just this string.\n");
	ft_printf("Length of previous output: %d\n", len);
	return 0;
}
