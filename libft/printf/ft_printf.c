/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:00:22 by jergoh            #+#    #+#             */
/*   Updated: 2024/06/08 22:00:23 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	checkformat(const char *c, size_t *i, va_list *argptr)
{
	char	format;

	*i = *i + 1;
	format = *(c + 1);
	if (format == 'c')
		return (ft_putchar((char) va_arg(*argptr, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*argptr, const char *)));
	else if (format == 'p')
		return (ft_putaddress(va_arg(*argptr, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(*argptr, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(*argptr, unsigned int)));
	else if (format == 'x')
		return (ft_puthex_l(va_arg(*argptr, int)));
	else if (format == 'X')
		return (ft_puthex_u(va_arg(*argptr, int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else if (format && (format + 1))
		return (ft_putchar(*(c)) + ft_putchar(format));
	else
		*i = *i - 1;
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		tmp;
	va_list	argptr;
	size_t	i;

	if (!str)
		return (-1);
	len = 0;
	va_start(argptr, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			tmp = checkformat(str + i, &i, &argptr);
		else
			tmp = ft_putchar(str[i]);
		if (tmp >= 0)
			len += tmp;
		else
			len = tmp;
		i++;
	}
	va_end(argptr);
	return (len);
}
