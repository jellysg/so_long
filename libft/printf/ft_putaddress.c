#include "../includes/libft.h"

static size_t	print_addr(const unsigned long n)
{
	if (n / 16)
		return (print_addr(n / 16) + print_addr(n % 16));
	else if (!(n / 10))
		ft_putchar(n + '0');
	else
		ft_putchar((char)(n - 10 + 'a'));
	return (1);
}

size_t	ft_putaddress(void *addr)
{
	if (!addr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + print_addr((unsigned long) addr));
}
