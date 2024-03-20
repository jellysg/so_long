/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:24:42 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:24:43 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	const char		*s_buffer;
	char			*d_buffer;

	i = 0;
	s_buffer = (char *)src;
	d_buffer = (char *)dest;
	while (i < n && (src || dest))
	{
		d_buffer[i] = s_buffer[i];
		i++;
	}
	return (dest);
}
