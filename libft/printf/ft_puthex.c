#include "../includes/libft.h"

size_t	ft_puthex_l(const unsigned int hex)
{
	if (hex / 16)
		return (ft_puthex_l(hex / 16) + ft_puthex_l(hex % 16));
	else if (!(hex / 10))
		ft_putchar(hex + '0');
	else
		ft_putchar((char) hex - 10 + 'a');
	return (1);
}

size_t	ft_puthex_u(const unsigned int hex)
{
	if (hex / 16)
		return (ft_puthex_u(hex / 16) + ft_puthex_u(hex % 16));
	else if (!(hex / 10))
		ft_putchar(hex + '0');
	else
		ft_putchar((char) hex - 10 + 'A');
	return (1);
}
